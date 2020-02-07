/*
 * (C) Copyright 2013 Xilinx, Inc.
 * (C) Copyright 2017 Antmicro Ltd
 *
 * Configuration for Enclustra Cosmos XZQ10 Board
 *
 * See zynq-common.h for Zynq common configs
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_ZYNQ_COSMOS_XZQ10_H
#define __CONFIG_ZYNQ_COSMOS_XZQ10_H

#define ENCLUSTRA_MARS_ZX
#define CONFIG_BOARD_COSMOS_XZQ10
#define CONFIG_LAST_STAGE_INIT
#define CONFIG_CPU_FREQ_HZ		666666666
#define CONFIG_ZYNQ_I2C0

#include <configs/zynq-common.h>
#include <configs/enclustra_zx_common.h>

#endif /* __CONFIG_ZYNQ_COSMOS_XZQ10_H */
