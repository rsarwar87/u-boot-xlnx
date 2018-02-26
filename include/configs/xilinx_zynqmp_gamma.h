/*
 * Configuration for Xilinx ZynqMP zcu102
 *
 * (C) Copyright 2015 Xilinx, Inc.
 * Michal Simek <michal.simek@xilinx.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_ZYNQMP_GAMMA_H
#define __CONFIG_ZYNQMP_GAMMA_H

#define CONFIG_ZYNQ_SDHCI1
#define CONFIG_ZYNQ_I2C0

#ifdef CONFIG_EXTRA_ENV_SETTINGS
#undef CONFIG_EXTRA_ENV_SETTINGS
#endif

#define CONFIG_EXTRA_ENV_SETTINGS	\
	"fdt_high=0x1E000000\0"	\
	"preboot=env import -t 0xFFFFFC00" \
	"sdboot=echo Importing environment from SD... && mmcinfo && fatload mmc 0 0x2000000 uEnv.txt && env import -t 0x2000000 ${filesize} && boot"


#include <configs/xilinx_zynqmp.h>

/* Select Micrel PHY */
#define CONFIG_PHY_MICREL

#define PHY_ANEG_TIMEOUT	8000	/* PHY needs a longer aneg time */

/* Unselect Marvell PHY (selected by zynq-common) */
#ifdef CONFIG_PHY_MARVELL
#undef CONFIG_PHY_MARVELL
#endif

#endif /* __CONFIG_ZYNQMP_GAMMA_H */
