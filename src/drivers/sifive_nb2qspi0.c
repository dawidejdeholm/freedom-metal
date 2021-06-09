/* Copyright 2020 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <metal/machine/platform.h>
#define METAL_SIFIVE_NB2QSPI0
#ifdef METAL_SIFIVE_NB2QSPI0

#include <metal/drivers/sifive_nb2qspi0.h>
#include <metal/machine.h>
#include <metal/io.h>
#include <metal/time.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define START_APB				(1 << 0)

/* QSPI Configure Fields */

#define QSPI_ADDR				 0
#define LENGTH_TX				 1
#define LENGTH_RX				 3
#define CS_I					 6
#define LSB_FIRST				 8
#define OP_MODE					 10
#define SPEED_MODE				 12
#define WP						 15
#define HOLD					 16
#define RX_MODE					 17
#define BURST_MODE				 18
#define RX_DELAY_COUNT			 20
#define RX_DELAY_FINE_COUNT		 22
#define BYPASS_PHASE_SHIFT		 24
#define RX_DELAY_HALF_CLK		 31

#define METAL_QSPI_REG(offset)   (((unsigned long long)control_base + offset))
#define METAL_QSPI_REGB(offset)  (__METAL_ACCESS_ONCE((__metal_io_u8  *)METAL_QSPI_REG(offset)))
#define METAL_QSPI_REGW(offset)  (__METAL_ACCESS_ONCE((__metal_io_u32 *)METAL_QSPI_REG(offset)))


static unsigned long long control_base=0;

static qspi_static_config_t qcfg;
static qspi_command_config_t *cparams;


static inline void qspi_apb_write(uint32_t txdata)
  {
  METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_TX_DATA_REG) = txdata;
  }

static void inline qspi_apb_read(uint32_t *rxdata)
  {
 	*rxdata = METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_RX_DATA_REG);
 }

static void qspi_wait_for_idle()
{
	uint32_t rd_dt;
	do{
		rd_dt = METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_SYSTEM_STATUS_REG);
	}while(rd_dt != QSPI_IDLE_STATE);
}


/* APIs for read-write access in APB mode */
static inline void qspi_apb_setaddr(uint32_t addr)
{
	METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_ADDRESS_REG) = addr;
}


static inline void qspi_apb_rw_trigger(void)
{
	METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_START_CMD_REG) |= (START_APB);
}


/* APIs to access QSPI controller registers */
/*static inline void qspi_set_dummy_dlp( uint32_t dlp_count, uint32_t dummy_count, uint32_t dummy_pattern)
  {
  METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_DUMMY_DLP_REG) = ((dlp_count & 0x0F)<<12)  | ((dummy_count & 0x0F)<<8) | (dummy_pattern & 0xFF);
  }*/

static inline void qspi_set_dummy_dlp( uint32_t dummy_stg)
{
	METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_DUMMY_DLP_REG) = dummy_stg;
}

/*static inline void qspi_set_mode_reg( uint32_t mode_count, uint32_t mode_pattern)
  {
  METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_MODE_REG) = ((mode_count & 0x07)<<8) | (mode_pattern & 0xFF);
  }*/

static inline void qspi_set_mode_reg( uint32_t mode_stg)
{
	METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_MODE_REG) = mode_stg;
}


static inline void qspi_set_custom_cmd(uint32_t mask)
{
	METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_CUSTOM_CMD_REG) = mask;
}

static inline void qspi_set_opcode(uint32_t opcode)
{
	METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_COMMAND_REG) = opcode;
}

static void pre_rate_change_callback_func(void *priv)
{
	control_base = __metal_driver_sifive_nb2qspi0_control_base((struct metal_qspi *)priv);
}

static void post_rate_change_callback_func(void *priv)
{
	struct __metal_driver_sifive_nb2qspi0 *qspi = priv;
	metal_qspi_set_baud_rate(&qspi->qspi, qspi->baud_rate);
}


/*********************************************************************************************************************************************/

/* APIs to get / clear QPI controller interrupt flags  */
void __metal_driver_sifive_nb2qspi0_clr_interrupt_mask(struct metal_qspi *qspi, uint32_t mask)
{
	control_base = __metal_driver_sifive_nb2qspi0_control_base(qspi);
	METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_INTR_MASK_CLR_REG) = mask;
}

uint32_t __metal_driver_sifive_nb2qspi0_get_interrupt_status(struct metal_qspi *qspi)
{
	control_base = __metal_driver_sifive_nb2qspi0_control_base(qspi);
	uint32_t intr_status;
	intr_status = METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_INTR_STAT_REG);
	return intr_status;
}

int __metal_driver_sifive_nb2qspi0_execute_cmd(struct metal_qspi *qspi)
{
	int retval=0;
	if(METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_SYSTEM_STATUS_REG)==QSPI_IDLE_STATE)
	{
		qspi_apb_rw_trigger();
		// wait For IDEL
		qspi_wait_for_idle();
	}else
	{
		retval=-1;
	}

	return retval;
}

int __metal_driver_sifive_nb2qspi0_read(struct metal_qspi *gqspi,uint32_t addr_offset,size_t len,uint8_t *rx_buf)
{
	if(len != 0){
		if(rx_buf){
			if(qcfg.burstmode==QSPI_APB_ACCESS)
			{
				qspi_apb_read((uint32_t*)rx_buf);
			}
			else if(qcfg.burstmode==QSPI_SINGLE_BURST)
			{
				//Single burst read
				uint64_t axi_addr = (METAL_QSPI_AXI_BASE_ADDR+addr_offset);
				uint32_t *dataptr= (uint32_t*)rx_buf;
				//Read length/4 locations
				for (int i = 0; i < len/4; i++)
				{
					*dataptr=*(volatile uint32_t *)axi_addr;
					axi_addr=axi_addr+4;
					dataptr++;
				}
			}
		}
	}
	return 0;

/*	uint32_t remaining_bytes=nbytes;

	if(nbytes != 0){
		if(rx_buf){
			if(qcfg.burstmode==QSPI_APB_ACCESS)
			{

				

				qspi_apb_read((uint32_t*)rx_buf);

			}
			else if(qcfg.burstmode==QSPI_SINGLE_BURST)
			{
				uint32_t data=0;	
				//Single burst read
				uint32_t *axi_addr = (uint32_t*) (METAL_QSPI_AXI_BASE_ADDR+addr_offset);
				uint32_t *dataptr= (uint32_t*)rx_buf;

				if(nbytes>=4)
				{
					// Read length/4 locations 
					for (int i = 0; i < nbytes/4; i++)
					{
						*dataptr=*axi_addr; //Copy data from 
						axi_addr++;
						dataptr++;
					}
				}

				uint8_t remaining_bytes = nbytes%4?(nbytes%4):0;

				if(remaining_bytes)
				{
					uint8_t *tempbufptr=(uint8_t*)dataptr;
					data=*axi_addr;

					while(remaining_bytes){
						*((uint8_t*)tempbufptr) = data & 0xFF;
						data >>= 8;
						remaining_bytes--;
						tempbufptr++;
					}
				}
			}	


		}
	}
	return 0;
*/
}


int __metal_driver_sifive_nb2qspi0_write(struct metal_qspi *gqspi,uint32_t addr_offset,size_t len,uint8_t *tx_buf)
{
	int retval=0;

	if(len != 0){
		if(tx_buf) {
			if(qcfg.burstmode==QSPI_APB_ACCESS)
			{
				qspi_apb_write((uint32_t)*tx_buf);
				__metal_driver_sifive_nb2qspi0_execute_cmd(gqspi);
			}
			else if(qcfg.burstmode==QSPI_SINGLE_BURST)
			{
				uint64_t axi_addr =(METAL_QSPI_AXI_BASE_ADDR+addr_offset);
				uint32_t *dataptr=(uint32_t *)tx_buf;
				*(volatile uint32_t *)axi_addr =*dataptr;
			}
		}
		else{
			retval= -1;
		}
	}
	else{
			retval= -1;
	}

	return retval;
}


int __metal_driver_sifive_nb2qspi0_init(struct metal_qspi *gqspi, uint32_t baud_rate)
{
	int retval=0;
	control_base = __metal_driver_sifive_nb2qspi0_control_base(gqspi);
	struct __metal_driver_sifive_nb2qspi0 *qspi = (void *)(gqspi);
	struct metal_clock *clock = __metal_driver_sifive_nb2qspi0_clock(gqspi);
	//	struct __metal_driver_sifive_nb2gpio0 *pinmux = __metal_driver_sifive_nb2qspi0_pinmux(gqspi);

	/* QSPI IOMUX CONFIG */

	if(clock != NULL) {
		qspi->pre_rate_change_callback.callback = &pre_rate_change_callback_func;
		qspi->pre_rate_change_callback.priv = qspi;
		metal_clock_register_pre_rate_change_callback(clock, &(qspi->pre_rate_change_callback));

		qspi->post_rate_change_callback.callback = &post_rate_change_callback_func;
		qspi->post_rate_change_callback.priv = qspi;
		metal_clock_register_post_rate_change_callback(clock, &(qspi->post_rate_change_callback));
	}


	retval=metal_qspi_set_baud_rate(&(qspi->qspi), baud_rate);

	/*	if (pinmux != NULL) {
		long pinmux_output_selector = __metal_driver_sifive_nb2qspi0_pinmux_output_selector(gqspi);
		long pinmux_source_selector = __metal_driver_sifive_nb2qspi0_pinmux_source_selector(gqspi);
		pinmux->gpio.vtable->enable_io((struct metal_gpio *) pinmux,pinmux_output_selector,pinmux_source_selector);
		}
		*/
	qspi_static_config_t cfg;

	/* Set-up initial parameters */
	memset((void *)&cfg,0,sizeof(qspi_static_config_t));
	/* Set-up initial parameters */
	cfg.addrlen = QSPI_ADDR_32BIT;
	cfg.rxlen   = QSPI_32BIT;
	cfg.txlen   = QSPI_32BIT;
	cfg.cs_i    = QSPI_DEVICE_0;
	cfg.clk_div = QSPI_DIV_4;
	cfg.bit_align = QSPI_MSB_FIRST;
	cfg.clock_polarity=0;
	cfg.opmode      = QSPI_SPI;
	cfg.speedmode   = QSPI_CMD_ADDR_SERIAL;
	cfg.write_prot  = QSPI_WRITE_PROT_DIS;
	cfg.hold 	= QSPI_HOLD_DIS;
	cfg.burstmode   = QSPI_SINGLE_BURST;
	cfg.wrmode      = QSPI_READ;
	cfg.rxdelay      =0;
	cfg.rxfinedelay =0;
	cfg.rx_dly_half_clk=0;
	cfg.rx_phshift_bypass=0;

	retval=metal_qspi_setconfig(gqspi,&cfg);

	return retval;
}


int __metal_driver_sifive_nb2qspi0_get_baud_rate(struct metal_qspi *gspi)
{
	struct __metal_driver_sifive_nb2qspi0 *qspi = (void *)gspi;
	return qspi->baud_rate;
}


int __metal_driver_sifive_nb2qspi0_set_baud_rate(struct metal_qspi *gqspi, uint32_t baud_rate)
{
	struct __metal_driver_sifive_nb2qspi0 *qspi = (void *)gqspi;
	control_base = __metal_driver_sifive_nb2qspi0_control_base(gqspi);
	struct metal_clock *clock = __metal_driver_sifive_nb2qspi0_clock(gqspi);

	qspi->baud_rate = baud_rate;

	long clock_rate;
	long div = 0;

	if (clock != NULL) {
		clock_rate = clock->vtable->get_rate_hz(clock);

		/* Calculate divider */
		if(baud_rate > clock_rate) {
			return -1;
		}

		while(1) {
			int temp = clock_rate / (1<<div);
			if(temp <= baud_rate)
				break;
			div++;
		}
	}

	qcfg.clk_div=div & 0x7;
	METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_BAUD_RATE_REG) = (div & 0x07);

	/*New updated baud_rate*/
	qspi->baud_rate=clock_rate*div;

	return 0;
}

int __metal_driver_sifive_nb2qspi0_setcommand_params(struct metal_qspi *qspi,qspi_command_config_t *cparams,qspi_static_config_t *cfg)
{
	int retval=0;
	if(cfg->burstmode==QSPI_APB_ACCESS)
	{
		qspi_apb_setaddr(cparams->addr);
	}
	qspi_set_dummy_dlp(cparams->dummy_stg);
	qspi_set_mode_reg(cparams->mode_stg);
	qspi_set_opcode(cparams->opcode);
	qspi_set_custom_cmd(cparams->custom_command);

	/*Check if there is no config error*/
	if((METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_SYSTEM_STATUS_REG)>>3)&1)
	{
		retval=-1;
	}else
	{
		retval=0;
	}

	return retval;
}


/* API to configure QSPI controller */
int __metal_driver_sifive_nb2qspi0_setconfig(struct metal_qspi *qspi,qspi_static_config_t *cfg)
{
	int retval=0;
	if(cfg) {
		qcfg = *cfg;
		METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_CMD_CFG_REG) =\
								    (((qcfg.addrlen & 0x01) << QSPI_ADDR)
								     | ((qcfg.txlen & 0x03) << LENGTH_TX)
								     | ((qcfg.rxlen & 0x03) << LENGTH_RX)
								     | ((qcfg.cs_i & 0x03) << CS_I)
								     | ((qcfg.bit_align & 0x01) << LSB_FIRST)
								     | ((qcfg.opmode & 0x03) << OP_MODE)
								     | ((qcfg.speedmode & 0x03) << SPEED_MODE)
								     | ((qcfg.write_prot & 0x01) << WP)
								     | ((qcfg.hold & 0x01) << HOLD)
								     | ((qcfg.wrmode & 0x01) << RX_MODE)
								     | ((qcfg.burstmode & 0x03) << BURST_MODE)
								     | ((qcfg.rxdelay & 0x03) << RX_DELAY_COUNT)
								     | ((qcfg.rxfinedelay & 0x03) << RX_DELAY_FINE_COUNT)
								     | ((qcfg.rx_dly_half_clk & 0x01) << RX_DELAY_HALF_CLK)
								     | ((qcfg.rx_phshift_bypass & 0x01) << BYPASS_PHASE_SHIFT));

		/*Check if there is no config error*/
		if((METAL_QSPI_REGW(METAL_SIFIVE_NB2QSPI0_SYSTEM_STATUS_REG)>>3)&1)
		{
			retval=-1;
		}else
		{
			retval=0;
		}

	}else
	{
		retval=-1;
	}

	return retval;
}

__METAL_DEFINE_VTABLE(__metal_driver_vtable_sifive_nb2qspi0) = {

	.qspi.init		= __metal_driver_sifive_nb2qspi0_init,
	.qspi.set_baud_rate 	= __metal_driver_sifive_nb2qspi0_set_baud_rate,
	.qspi.get_baud_rate	= __metal_driver_sifive_nb2qspi0_get_baud_rate,
	.qspi.setconfig         = __metal_driver_sifive_nb2qspi0_setconfig,
	.qspi.setcommand_params = __metal_driver_sifive_nb2qspi0_setcommand_params,
	.qspi.read  		= __metal_driver_sifive_nb2qspi0_read,
	.qspi.write  		= __metal_driver_sifive_nb2qspi0_write,
	.qspi.execute_cmd	= __metal_driver_sifive_nb2qspi0_execute_cmd,
};

#endif /* METAL_SIFIVE_NB2QSPI0 */

typedef int no_empty_translation_units;
