/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include <metal/machine/inline.h>

#ifdef __IAR_SYSTEMS_ICC__
#define __NO_IAR_WEAK__
/* This is a dummy so that this file is included when linking */
/* using IAR ELF LINKER for RISC-V                            */
const char __iar_metal_dummy=0;

#endif
