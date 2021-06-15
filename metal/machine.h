/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */
/* ----------------------------------- */
/* ----------------------------------- */

#ifndef ASSEMBLY

#include <metal/machine/platform.h>

#ifdef __METAL_MACHINE_MACROS

#ifndef MACROS_IF_OUTPUT__MACHINE_H
#define MACROS_IF_OUTPUT__MACHINE_H

#define __METAL_CLINT_NUM_PARENTS 2

#ifndef __METAL_CLINT_NUM_PARENTS
#define __METAL_CLINT_NUM_PARENTS 0
#endif
#define __METAL_PLIC_SUBINTERRUPTS 31

#define __METAL_PLIC_NUM_PARENTS 1

#ifndef __METAL_PLIC_SUBINTERRUPTS
#define __METAL_PLIC_SUBINTERRUPTS 0
#endif
#ifndef __METAL_PLIC_NUM_PARENTS
#define __METAL_PLIC_NUM_PARENTS 0
#endif
#ifndef __METAL_CLIC_SUBINTERRUPTS
#define __METAL_CLIC_SUBINTERRUPTS 0
#endif

#endif /* MACROS_IF_OUTPUT__MACHINE_H*/

#else /* ! __METAL_MACHINE_MACROS */

#ifndef MACROS_ELSE_OUTPUT__MACHINE_H
#define MACROS_ELSE_OUTPUT__MACHINE_H

#define __METAL_CLINT_2000000_INTERRUPTS 2

#define METAL_MAX_CLINT_INTERRUPTS 2

#define __METAL_CLINT_NUM_PARENTS 2

#define __METAL_INTERRUPT_CONTROLLER_C000000_INTERRUPTS 1

#define __METAL_PLIC_SUBINTERRUPTS 31

#define METAL_MAX_PLIC_INTERRUPTS 1

#define __METAL_PLIC_NUM_PARENTS 1

#define __METAL_CLIC_SUBINTERRUPTS 0
#define METAL_MAX_CLIC_INTERRUPTS 0

#define __METAL_LOCAL_EXTERNAL_INTERRUPTS_0_INTERRUPTS 16

#define METAL_MAX_LOCAL_EXT_INTERRUPTS 16

#define __METAL_GLOBAL_EXTERNAL_INTERRUPTS_INTERRUPTS 8

#define METAL_MAX_GLOBAL_EXT_INTERRUPTS 8

#define __METAL_GPIO_20002000_INTERRUPTS 16

#define METAL_MAX_GPIO_INTERRUPTS 16

#define METAL_MAX_I2C0_INTERRUPTS 0

#define __METAL_PWM_20005000_INTERRUPTS 4

#define METAL_MAX_PWM0_INTERRUPTS 4

#define METAL_MAX_PWM0_NCMP 4

#define __METAL_SERIAL_20000000_INTERRUPTS 1

#define METAL_MAX_UART_INTERRUPTS 1

#define METAL_MAX_SIMUART_INTERRUPTS 0


#include <metal/drivers/fixed-clock.h>
#include <metal/memory.h>
#include <metal/drivers/riscv_clint0.h>
#include <metal/drivers/riscv_cpu.h>
#include <metal/drivers/riscv_plic0.h>
#include <metal/pmp.h>
#include <metal/drivers/sifive_local-external-interrupts0.h>
#include <metal/drivers/sifive_global-external-interrupts0.h>
#include <metal/drivers/sifive_gpio0.h>
#include <metal/drivers/sifive_gpio-buttons.h>
#include <metal/drivers/sifive_gpio-leds.h>
#include <metal/drivers/sifive_gpio-switches.h>
#include <metal/drivers/sifive_pwm0.h>
#include <metal/drivers/sifive_spi0.h>
#include <metal/drivers/sifive_test0.h>
#include <metal/drivers/sifive_uart0.h>

#ifdef __IAR_SYSTEMS_ICC__
#ifdef __NO_IAR_WEAK__
#define __MD_EXTERNAL //
#else
#define __MD_EXTERNAL extern __weak
#endif
#else
#define __MD_EXTERNAL
#endif

/* From subsystem_pbus_clock */
__MD_EXTERNAL struct __metal_driver_fixed_clock __metal_dt_subsystem_pbus_clock;

__MD_EXTERNAL struct metal_memory __metal_dt_mem_dtim_80000000;

__MD_EXTERNAL struct metal_memory __metal_dt_mem_itim_1800000;

__MD_EXTERNAL struct metal_memory __metal_dt_mem_spi_20004000;

/* From clint@2000000 */
__MD_EXTERNAL struct __metal_driver_riscv_clint0 __metal_dt_clint_2000000;

/* From cpu@0 */
__MD_EXTERNAL struct __metal_driver_cpu __metal_dt_cpu_0;

__MD_EXTERNAL struct __metal_driver_riscv_cpu_intc __metal_dt_cpu_0_interrupt_controller;

/* From interrupt_controller@c000000 */
__MD_EXTERNAL struct __metal_driver_riscv_plic0 __metal_dt_interrupt_controller_c000000;

extern struct metal_pmp __metal_dt_pmp;

/* From local_external_interrupts_0 */
__MD_EXTERNAL struct __metal_driver_sifive_local_external_interrupts0 __metal_dt_local_external_interrupts_0;

/* From global_external_interrupts */
__MD_EXTERNAL struct __metal_driver_sifive_global_external_interrupts0 __metal_dt_global_external_interrupts;

/* From gpio@20002000 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio0 __metal_dt_gpio_20002000;

/* From button@0 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_button __metal_dt_button_0;

/* From button@1 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_button __metal_dt_button_1;

/* From button@2 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_button __metal_dt_button_2;

/* From button@3 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_button __metal_dt_button_3;

/* From led@0 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_led __metal_dt_led_0;

/* From led@1 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_led __metal_dt_led_1;

/* From led@2 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_led __metal_dt_led_2;

/* From switch@0 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_switch __metal_dt_switch_0;

/* From switch@1 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_switch __metal_dt_switch_1;

/* From switch@2 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_switch __metal_dt_switch_2;

/* From switch@3 */
__MD_EXTERNAL struct __metal_driver_sifive_gpio_switch __metal_dt_switch_3;

/* From pwm@20005000 */
__MD_EXTERNAL struct __metal_driver_sifive_pwm0 __metal_dt_pwm_20005000;

/* From spi@20004000 */
__MD_EXTERNAL struct __metal_driver_sifive_spi0 __metal_dt_spi_20004000;

/* From teststatus@4000 */
__MD_EXTERNAL struct __metal_driver_sifive_test0 __metal_dt_teststatus_4000;

/* From serial@20000000 */
__MD_EXTERNAL struct __metal_driver_sifive_uart0 __metal_dt_serial_20000000;



/* --------------------- fixed_clock ------------ */
static __inline__ unsigned long __metal_driver_fixed_clock_rate(const struct metal_clock *clock)
{
	if ((uintptr_t)clock == (uintptr_t)&__metal_dt_subsystem_pbus_clock) {
		return METAL_FIXED_CLOCK__SUBSYSTEM_PBUS_CLOCK_CLOCK_FREQUENCY;
	}
	else {
		return 0;
	}
}



/* --------------------- fixed_factor_clock ------------ */


/* --------------------- sifive_clint0 ------------ */
static __inline__ unsigned long __metal_driver_sifive_clint0_control_base(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_clint_2000000) {
		return METAL_RISCV_CLINT0_2000000_BASE_ADDRESS;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_clint0_control_size(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_clint_2000000) {
		return METAL_RISCV_CLINT0_2000000_SIZE;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_clint0_num_interrupts(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_clint_2000000) {
		return METAL_MAX_CLINT_INTERRUPTS;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_interrupt * __metal_driver_sifive_clint0_interrupt_parents(struct metal_interrupt *controller, int idx)
{
	if (idx == 0) {
		return (struct metal_interrupt *)&__metal_dt_cpu_0_interrupt_controller.controller;
	}
	else if (idx == 1) {
		return (struct metal_interrupt *)&__metal_dt_cpu_0_interrupt_controller.controller;
	}
	else {
		return NULL;
	}
}

static __inline__ int __metal_driver_sifive_clint0_interrupt_lines(struct metal_interrupt *controller, int idx)
{
	if (idx == 0) {
		return 3;
	}
	else if (idx == 1) {
		return 7;
	}
	else {
		return 0;
	}
}



/* --------------------- cpu ------------ */
static __inline__ int __metal_driver_cpu_hartid(struct metal_cpu *cpu)
{
	if ((uintptr_t)cpu == (uintptr_t)&__metal_dt_cpu_0) {
		return 0;
	}
	else {
		return -1;
	}
}

static __inline__ int __metal_driver_cpu_timebase(struct metal_cpu *cpu)
{
	if ((uintptr_t)cpu == (uintptr_t)&__metal_dt_cpu_0) {
		return 32500000;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_interrupt * __metal_driver_cpu_interrupt_controller(struct metal_cpu *cpu)
{
	if ((uintptr_t)cpu == (uintptr_t)&__metal_dt_cpu_0) {
		return &__metal_dt_cpu_0_interrupt_controller.controller;
	}
	else {
		return NULL;
	}
}

static __inline__ int __metal_driver_cpu_num_pmp_regions(struct metal_cpu *cpu)
{
	if ((uintptr_t)cpu == (uintptr_t)&__metal_dt_cpu_0) {
		return 8;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_buserror * __metal_driver_cpu_buserror(struct metal_cpu *cpu)
{
	if ((uintptr_t)cpu == (uintptr_t)&__metal_dt_cpu_0) {
		return NULL;
	}
	else {
		return NULL;
	}
}



/* --------------------- sifive_plic0 ------------ */
static __inline__ unsigned long __metal_driver_sifive_plic0_control_base(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_interrupt_controller_c000000) {
		return METAL_RISCV_PLIC0_C000000_BASE_ADDRESS;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_plic0_control_size(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_interrupt_controller_c000000) {
		return METAL_RISCV_PLIC0_C000000_SIZE;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_plic0_num_interrupts(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_interrupt_controller_c000000) {
		return METAL_RISCV_PLIC0_C000000_RISCV_NDEV;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_plic0_max_priority(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_interrupt_controller_c000000) {
		return METAL_RISCV_PLIC0_C000000_RISCV_MAX_PRIORITY;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_interrupt * __metal_driver_sifive_plic0_interrupt_parents(struct metal_interrupt *controller, int idx)
{
	if (idx == 0) {
		return (struct metal_interrupt *)&__metal_dt_cpu_0_interrupt_controller.controller;
	}
	else {
		return NULL;
	}
}

static __inline__ int __metal_driver_sifive_plic0_interrupt_lines(struct metal_interrupt *controller, int idx)
{
	if (idx == 0) {
		return 11;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_plic0_context_ids(int hartid)
{
	if (hartid == 0) {
		return 0;
	}
	else {
		return -1;
	}
}



/* --------------------- sifive_buserror0 ------------ */


/* --------------------- sifive_clic0 ------------ */


/* --------------------- sifive_local_external_interrupts0 ------------ */
static __inline__ struct metal_interrupt * __metal_driver_sifive_local_external_interrupts0_interrupt_parent(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_local_external_interrupts_0) {
		return (struct metal_interrupt *)&__metal_dt_cpu_0_interrupt_controller.controller;
	}
	else {
		return NULL;
	}
}

static __inline__ int __metal_driver_sifive_local_external_interrupts0_num_interrupts(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_local_external_interrupts_0) {
		return METAL_MAX_LOCAL_EXT_INTERRUPTS;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_local_external_interrupts0_interrupt_lines(struct metal_interrupt *controller, int idx)
{
	if (idx == 0) {
		return 16;
	}
	else if (idx == 1) {
		return 17;
	}
	else if (idx == 2) {
		return 18;
	}
	else if (idx == 3) {
		return 19;
	}
	else if (idx == 4) {
		return 20;
	}
	else if (idx == 5) {
		return 21;
	}
	else if (idx == 6) {
		return 22;
	}
	else if (idx == 7) {
		return 23;
	}
	else if (idx == 8) {
		return 24;
	}
	else if (idx == 9) {
		return 25;
	}
	else if (idx == 10) {
		return 26;
	}
	else if (idx == 11) {
		return 27;
	}
	else if (idx == 12) {
		return 28;
	}
	else if (idx == 13) {
		return 29;
	}
	else if (idx == 14) {
		return 30;
	}
	else if (idx == 15) {
		return 31;
	}
	else {
		return 0;
	}
}



/* --------------------- sifive_global_external_interrupts0 ------------ */
static __inline__ int __metal_driver_sifive_global_external_interrupts0_init_done()
{
		return 0;
}

static __inline__ struct metal_interrupt * __metal_driver_sifive_global_external_interrupts0_interrupt_parent(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_global_external_interrupts) {
		return (struct metal_interrupt *)&__metal_dt_interrupt_controller_c000000.controller;
	}
	else {
		return NULL;
	}
}

static __inline__ int __metal_driver_sifive_global_external_interrupts0_num_interrupts(struct metal_interrupt *controller)
{
	if ((uintptr_t)controller == (uintptr_t)&__metal_dt_global_external_interrupts) {
		return METAL_MAX_GLOBAL_EXT_INTERRUPTS;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_global_external_interrupts0_interrupt_lines(struct metal_interrupt *controller, int idx)
{
	if (idx == 0) {
		return 23;
	}
	else if (idx == 1) {
		return 24;
	}
	else if (idx == 2) {
		return 25;
	}
	else if (idx == 3) {
		return 26;
	}
	else if (idx == 4) {
		return 27;
	}
	else if (idx == 5) {
		return 28;
	}
	else if (idx == 6) {
		return 29;
	}
	else if (idx == 7) {
		return 30;
	}
	else {
		return 0;
	}
}



/* --------------------- sifive_gpio0 ------------ */
static __inline__ unsigned long __metal_driver_sifive_gpio0_base(struct metal_gpio *gpio)
{
	if ((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) {
		return METAL_SIFIVE_GPIO0_20002000_BASE_ADDRESS;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_gpio0_size(struct metal_gpio *gpio)
{
	if ((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) {
		return METAL_SIFIVE_GPIO0_20002000_SIZE;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_gpio0_num_interrupts(struct metal_gpio *gpio)
{
	if ((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) {
		return METAL_MAX_GPIO_INTERRUPTS;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_interrupt * __metal_driver_sifive_gpio0_interrupt_parent(struct metal_gpio *gpio)
{
	if ((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) {
		return (struct metal_interrupt *)&__metal_dt_interrupt_controller_c000000.controller;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_gpio0_interrupt_lines(struct metal_gpio *gpio, int idx)
{
	if (((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 0)) {
		return 2;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 1))) {
		return 3;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 2))) {
		return 4;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 3))) {
		return 5;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 4))) {
		return 6;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 5))) {
		return 7;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 6))) {
		return 8;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 7))) {
		return 9;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 8))) {
		return 10;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 9))) {
		return 11;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 10))) {
		return 12;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 11))) {
		return 13;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 12))) {
		return 14;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 13))) {
		return 15;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 14))) {
		return 16;
	}
	else if ((((uintptr_t)gpio == (uintptr_t)&__metal_dt_gpio_20002000) && (idx == 15))) {
		return 17;
	}
	else {
		return 0;
	}
}



/* --------------------- sifive_gpio_button ------------ */
static __inline__ struct metal_gpio * __metal_driver_sifive_gpio_button_gpio(struct metal_button *button)
{
	if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_0) {
		return (struct metal_gpio *)&__metal_dt_gpio_20002000;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_1) {
		return (struct metal_gpio *)&__metal_dt_gpio_20002000;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_2) {
		return (struct metal_gpio *)&__metal_dt_gpio_20002000;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_3) {
		return (struct metal_gpio *)&__metal_dt_gpio_20002000;
	}
	else {
		return NULL;
	}
}

static __inline__ int __metal_driver_sifive_gpio_button_pin(struct metal_button *button)
{
	if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_0) {
		return 4;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_1) {
		return 5;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_2) {
		return 6;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_3) {
		return 7;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_interrupt * __metal_driver_sifive_gpio_button_interrupt_controller(struct metal_button *button)
{
	if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_0) {
		return (struct metal_interrupt *)&__metal_dt_local_external_interrupts_0;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_1) {
		return (struct metal_interrupt *)&__metal_dt_local_external_interrupts_0;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_2) {
		return (struct metal_interrupt *)&__metal_dt_local_external_interrupts_0;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_3) {
		return (struct metal_interrupt *)&__metal_dt_local_external_interrupts_0;
	}
	else {
		return NULL;
	}
}

static __inline__ int __metal_driver_sifive_gpio_button_interrupt_line(struct metal_button *button)
{
	if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_0) {
		return 4;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_1) {
		return 5;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_2) {
		return 6;
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_3) {
		return 7;
	}
	else {
		return 0;
	}
}

static __inline__ char * __metal_driver_sifive_gpio_button_label(struct metal_button *button)
{
	if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_0) {
		return "BTN0";
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_1) {
		return "BTN1";
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_2) {
		return "BTN2";
	}
	else if ((uintptr_t)button == (uintptr_t)&__metal_dt_button_3) {
		return "BTN3";
	}
	else {
		return "";
	}
}



/* --------------------- sifive_gpio_led ------------ */
static __inline__ struct metal_gpio * __metal_driver_sifive_gpio_led_gpio(struct metal_led *led)
{
	if ((uintptr_t)led == (uintptr_t)&__metal_dt_led_0) {
		return (struct metal_gpio *)&__metal_dt_gpio_20002000;
	}
	else if ((uintptr_t)led == (uintptr_t)&__metal_dt_led_1) {
		return (struct metal_gpio *)&__metal_dt_gpio_20002000;
	}
	else if ((uintptr_t)led == (uintptr_t)&__metal_dt_led_2) {
		return (struct metal_gpio *)&__metal_dt_gpio_20002000;
	}
	else {
		return NULL;
	}
}

static __inline__ int __metal_driver_sifive_gpio_led_pin(struct metal_led *led)
{
	if ((uintptr_t)led == (uintptr_t)&__metal_dt_led_0) {
		return 0;
	}
	else if ((uintptr_t)led == (uintptr_t)&__metal_dt_led_1) {
		return 1;
	}
	else if ((uintptr_t)led == (uintptr_t)&__metal_dt_led_2) {
		return 2;
	}
	else {
		return 0;
	}
}

static __inline__ char * __metal_driver_sifive_gpio_led_label(struct metal_led *led)
{
	if ((uintptr_t)led == (uintptr_t)&__metal_dt_led_0)
        {
		return "LD0red";
	}
	else if ((uintptr_t)led == (uintptr_t)&__metal_dt_led_1) {
		return "LD0green";
	}
	else if ((uintptr_t)led == (uintptr_t)&__metal_dt_led_2) {
		return "LD0blue";
	}
	else {
		return "";
	}
}



/* --------------------- sifive_gpio_switch ------------ */
static __inline__ struct metal_gpio * __metal_driver_sifive_gpio_switch_gpio(struct metal_switch *flip)
{
		return NULL;
}

static __inline__ int __metal_driver_sifive_gpio_switch_pin(struct metal_switch *flip)
{
		return 0;
}

static __inline__ struct metal_interrupt * __metal_driver_sifive_gpio_switch_interrupt_controller(struct metal_switch *flip)
{
	if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_0) {
		return (struct metal_interrupt *)&__metal_dt_local_external_interrupts_0;
	}
	else if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_1) {
		return (struct metal_interrupt *)&__metal_dt_local_external_interrupts_0;
	}
	else if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_2) {
		return (struct metal_interrupt *)&__metal_dt_local_external_interrupts_0;
	}
	else if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_3) {
		return (struct metal_interrupt *)&__metal_dt_local_external_interrupts_0;
	}
	else {
		return NULL;
	}
}

static __inline__ int __metal_driver_sifive_gpio_switch_interrupt_line(struct metal_switch *flip)
{
	if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_0) {
		return 0;
	}
	else if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_1) {
		return 1;
	}
	else if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_2) {
		return 2;
	}
	else if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_3) {
		return 3;
	}
	else {
		return 0;
	}
}

static __inline__ char * __metal_driver_sifive_gpio_switch_label(struct metal_switch *flip)
{
	if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_0) {
		return "SW0";
	}
	else if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_1) {
		return "SW1";
	}
	else if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_2) {
		return "SW2";
	}
	else if ((uintptr_t)flip == (uintptr_t)&__metal_dt_switch_3) {
		return "SW3";
	}
	else {
		return "";
	}
}



/* --------------------- sifive_i2c0 ------------ */


/* --------------------- sifive_pwm0 ------------ */
static __inline__ unsigned long __metal_driver_sifive_pwm0_control_base(struct metal_pwm *pwm)
{
	if ((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) {
		return METAL_SIFIVE_PWM0_20005000_BASE_ADDRESS;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_pwm0_control_size(struct metal_pwm *pwm)
{
	if ((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) {
		return METAL_SIFIVE_PWM0_20005000_SIZE;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_clock * __metal_driver_sifive_pwm0_clock(struct metal_pwm *pwm)
{
	if ((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) {
		return (struct metal_clock *)&__metal_dt_subsystem_pbus_clock.clock;
	}
	else {
		return NULL;
	}
}

static __inline__ struct __metal_driver_sifive_gpio0 * __metal_driver_sifive_pwm0_pinmux(struct metal_pwm *pwm)
{
	if ((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) {
		return NULL;
	}
	else {
		return NULL;
	}
}

static __inline__ unsigned long __metal_driver_sifive_pwm0_pinmux_output_selector(struct metal_pwm *pwm)
{
	if ((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) {
		return 0;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_pwm0_pinmux_source_selector(struct metal_pwm *pwm)
{
	if ((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) {
		return 0;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_pwm0_num_interrupts(struct metal_pwm *pwm)
{
	if ((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) {
		return __METAL_PWM_20005000_INTERRUPTS;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_interrupt * __metal_driver_sifive_pwm0_interrupt_parent(struct metal_pwm *pwm)
{
		return (struct metal_interrupt *)&__metal_dt_interrupt_controller_c000000.controller;
}

static __inline__ int __metal_driver_sifive_pwm0_interrupt_lines(struct metal_pwm *pwm, int idx)
{
	if (((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) && (idx == 0)) {
		return 18;
	}
	else if ((((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) && (idx == 1))) {
		return 19;
	}
	else if ((((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) && (idx == 2))) {
		return 20;
	}
	else if ((((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) && (idx == 3))) {
		return 21;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_pwm0_compare_width(struct metal_pwm *pwm)
{
	if ((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) {
		return 8;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_pwm0_comparator_count(struct metal_pwm *pwm)
{
	if ((uintptr_t)pwm == (uintptr_t)&__metal_dt_pwm_20005000) {
		return 4;
	}
	else {
		return 0;
	}
}



/* --------------------- sifive_rtc0 ------------ */

static __inline__ unsigned long __metal_driver_sifive_spi0_control_base(struct metal_spi *spi)
{
	if ((uintptr_t)spi == (uintptr_t)&__metal_dt_spi_20004000) {
		return METAL_SIFIVE_SPI0_20004000_BASE_ADDRESS;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_spi0_control_size(struct metal_spi *spi)
{
	if ((uintptr_t)spi == (uintptr_t)&__metal_dt_spi_20004000) {
		return METAL_SIFIVE_SPI0_20004000_SIZE;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_clock * __metal_driver_sifive_spi0_clock(struct metal_spi *spi)
{
	if ((uintptr_t)spi == (uintptr_t)&__metal_dt_spi_20004000) {
		return (struct metal_clock *)&__metal_dt_subsystem_pbus_clock.clock;
	}
	else {
		return 0;
	}
}

static __inline__ struct __metal_driver_sifive_gpio0 * __metal_driver_sifive_spi0_pinmux(struct metal_spi *spi)
{
	if ((uintptr_t)spi == (uintptr_t)&__metal_dt_spi_20004000) {
		return NULL;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_spi0_pinmux_output_selector(struct metal_spi *spi)
{
	if ((uintptr_t)spi == (uintptr_t)&__metal_dt_spi_20004000) {
		return 0;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_spi0_pinmux_source_selector(struct metal_spi *spi)
{
	if ((uintptr_t)spi == (uintptr_t)&__metal_dt_spi_20004000) {
		return 0;
	}
	else {
		return 0;
	}
}



/* --------------------- sifive_test0 ------------ */
static __inline__ unsigned long __metal_driver_sifive_test0_base(const struct __metal_shutdown *sd)
{
	if ((uintptr_t)sd == (uintptr_t)&__metal_dt_teststatus_4000) {
		return METAL_SIFIVE_TEST0_4000_BASE_ADDRESS;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_test0_size(const struct __metal_shutdown *sd)
{
	if ((uintptr_t)sd == (uintptr_t)&__metal_dt_teststatus_4000) {
		return METAL_SIFIVE_TEST0_4000_SIZE;
	}
	else {
		return 0;
	}
}



/* --------------------- sifive_trace ------------ */

/* --------------------- sifive_uart0 ------------ */
static __inline__ unsigned long __metal_driver_sifive_uart0_control_base(struct metal_uart *uart)
{
	if ((uintptr_t)uart == (uintptr_t)&__metal_dt_serial_20000000) {
		return METAL_SIFIVE_UART0_20000000_BASE_ADDRESS;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_uart0_control_size(struct metal_uart *uart)
{
	if ((uintptr_t)uart == (uintptr_t)&__metal_dt_serial_20000000) {
		return METAL_SIFIVE_UART0_20000000_SIZE;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_uart0_num_interrupts(struct metal_uart *uart)
{
	if ((uintptr_t)uart == (uintptr_t)&__metal_dt_serial_20000000) {
		return METAL_MAX_UART_INTERRUPTS;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_interrupt * __metal_driver_sifive_uart0_interrupt_parent(struct metal_uart *uart)
{
	if ((uintptr_t)uart == (uintptr_t)&__metal_dt_serial_20000000) {
		return (struct metal_interrupt *)&__metal_dt_interrupt_controller_c000000.controller;
	}
	else {
		return 0;
	}
}

static __inline__ int __metal_driver_sifive_uart0_interrupt_line(struct metal_uart *uart)
{
	if ((uintptr_t)uart == (uintptr_t)&__metal_dt_serial_20000000) {
		return 1;
	}
	else {
		return 0;
	}
}

static __inline__ struct metal_clock * __metal_driver_sifive_uart0_clock(struct metal_uart *uart)
{
	if ((uintptr_t)uart == (uintptr_t)&__metal_dt_serial_20000000) {
		return (struct metal_clock *)&__metal_dt_subsystem_pbus_clock.clock;
	}
	else {
		return 0;
	}
}

static __inline__ struct __metal_driver_sifive_gpio0 * __metal_driver_sifive_uart0_pinmux(struct metal_uart *uart)
{
	if ((uintptr_t)uart == (uintptr_t)&__metal_dt_serial_20000000) {
		return NULL;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_uart0_pinmux_output_selector(struct metal_uart *uart)
{
	if ((uintptr_t)uart == (uintptr_t)&__metal_dt_serial_20000000) {
		return 0;
	}
	else {
		return 0;
	}
}

static __inline__ unsigned long __metal_driver_sifive_uart0_pinmux_source_selector(struct metal_uart *uart)
{
	if ((uintptr_t)uart == (uintptr_t)&__metal_dt_serial_20000000) {
		return 0;
	}
	else {
		return 0;
	}
}



/* --------------------- sifive_simuart0 ------------ */


/* --------------------- sifive_wdog0 ------------ */


/* --------------------- sifive_fe310_g000_hfrosc ------------ */


/* --------------------- sifive_fe310_g000_hfxosc ------------ */


/* --------------------- sifive_fe310_g000_lfrosc ------------ */


/* --------------------- sifive_fe310_g000_pll ------------ */


/* --------------------- sifive_fe310_g000_prci ------------ */


#define __METAL_DT_MAX_MEMORIES 3

#ifndef __IAR_SYSTEMS_ICC__
struct metal_memory *__metal_memory_table[] __attribute__((weak)) = {
#else
__MD_EXTERNAL
struct metal_memory *__metal_memory_table[] = {
#endif
					&__metal_dt_mem_dtim_80000000,
					&__metal_dt_mem_itim_1800000,
					&__metal_dt_mem_spi_20004000};

/* From clint@2000000 */
#define __METAL_DT_RISCV_CLINT0_HANDLE (&__metal_dt_clint_2000000.controller)

#define __METAL_DT_CLINT_2000000_HANDLE (&__metal_dt_clint_2000000.controller)

#define __METAL_DT_MAX_HARTS 1

#define __METAL_CPU_0_ICACHE_HANDLE 1

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_cpu *__metal_cpu_table[] = {
#else
struct __metal_driver_cpu *__metal_cpu_table[] __attribute__((weak))  = {
#endif
					&__metal_dt_cpu_0};

/* From interrupt_controller@c000000 */
#define __METAL_DT_RISCV_PLIC0_HANDLE (&__metal_dt_interrupt_controller_c000000.controller)

#define __METAL_DT_INTERRUPT_CONTROLLER_C000000_HANDLE (&__metal_dt_interrupt_controller_c000000.controller)

#define __METAL_DT_PMP_HANDLE (&__metal_dt_pmp)

/* From global_external_interrupts */
#define __METAL_DT_SIFIVE_GLOBAL_EXINTR0_HANDLE (&__metal_dt_global_external_interrupts.irc)

#define __METAL_DT_GLOBAL_EXTERNAL_INTERRUPTS_HANDLE (&__metal_dt_global_external_interrupts.irc)

#define __MEE_DT_MAX_GPIOS 1

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_gpio0 *__metal_gpio_table[] = {
#else
struct __metal_driver_sifive_gpio0 *__metal_gpio_table[] __attribute__((weak))  = {
#endif
					&__metal_dt_gpio_20002000};

#define __METAL_DT_MAX_BUTTONS 4

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_gpio_button *__metal_button_table[] = {
#else
struct __metal_driver_sifive_gpio_button *__metal_button_table[] __attribute__((weak))  = {
#endif
					&__metal_dt_button_0,
					&__metal_dt_button_1,
					&__metal_dt_button_2,
					&__metal_dt_button_3};

#define __METAL_DT_MAX_LEDS 3

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_gpio_led *__metal_led_table[] = {
#else
struct __metal_driver_sifive_gpio_led *__metal_led_table[] __attribute__((weak))  = {
#endif
					&__metal_dt_led_0,
					&__metal_dt_led_1,
					&__metal_dt_led_2};

#define __METAL_DT_MAX_SWITCHES 4

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_gpio_switch *__metal_switch_table[] = {
#else
struct __metal_driver_sifive_gpio_switch *__metal_switch_table[] __attribute__((weak))  = {
#endif
					&__metal_dt_switch_0,
					&__metal_dt_switch_1,
					&__metal_dt_switch_2,
					&__metal_dt_switch_3};

#define __METAL_DT_MAX_I2CS 0

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_i2c0 *__metal_i2c_table[] = {
#else
struct __metal_driver_sifive_i2c0 *__metal_i2c_table[] __attribute__((weak))  = {
#endif
					NULL };
#define __METAL_DT_MAX_PWMS 1

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_pwm0 *__metal_pwm_table[] = {
#else
struct __metal_driver_sifive_pwm0 *__metal_pwm_table[] __attribute__((weak))  = {
#endif
					&__metal_dt_pwm_20005000};

#define __METAL_DT_MAX_RTCS 0

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_rtc0 *__metal_rtc_table[] = {
#else
struct __metal_driver_sifive_rtc0 *__metal_rtc_table[] __attribute__((weak))  = {
#endif
					NULL };
#define __METAL_DT_MAX_SPIS 1

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_spi0 *__metal_spi_table[] = {
#else
struct __metal_driver_sifive_spi0 *__metal_spi_table[] __attribute__((weak))  = {
#endif
					&__metal_dt_spi_20004000};

/* From teststatus@4000 */
#define __METAL_DT_SHUTDOWN_HANDLE (&__metal_dt_teststatus_4000.shutdown)

#define __METAL_DT_TESTSTATUS_4000_HANDLE (&__metal_dt_teststatus_4000.shutdown)

#define __METAL_DT_MAX_UARTS 1

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_uart0 *__metal_uart_table[] = {
#else
struct __metal_driver_sifive_uart0 *__metal_uart_table[] __attribute__((weak))  = {
#endif
					&__metal_dt_serial_20000000};

#define __METAL_DT_MAX_SIMUARTS 0

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_simuart0 *__metal_simuart_table[] = {
#else
struct __metal_driver_sifive_simuart0 *__metal_simuart_table[] __attribute__((weak))  = {
#endif
					NULL };
#define __METAL_DT_MAX_WDOGS 0

#ifdef __IAR_SYSTEMS_ICC__
__MD_EXTERNAL
struct __metal_driver_sifive_wdog0 *__metal_wdog_table[] = {
#else
struct __metal_driver_sifive_wdog0 *__metal_wdog_table[] __attribute__((weak))  = {
#endif
					NULL };
#endif /* MACROS_ELSE_OUTPUT__MACHINE_H*/

#endif /* ! __METAL_MACHINE_MACROS */

#undef __MD_EXTERNAL

#endif /* ! ASSEMBLY */
