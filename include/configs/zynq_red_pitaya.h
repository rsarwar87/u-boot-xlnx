#include <configs/zynq-common.h>

#ifndef __CONFIG_ZYNQ_RED_PITAYA_H
#define __CONFIG_ZYNQ_RED_PITAYA_H

#define CONFIG_ZYNQ_I2C0
#define CONFIG_ZYNQ_EEPROM

#ifdef CONFIG_EXTRA_ENV_SETTINGS
#undef CONFIG_EXTRA_ENV_SETTINGS
#endif

#define CONFIG_EXTRA_ENV_SETTINGS	\
	"kernel_image=uImage\0"	\
	"kernel_load_address=0x2080000\0" \
	"ramdisk_image=uramdisk.image.gz\0"	\
	"ramdisk_load_address=0x4000000\0"	\
	"devicetree_image=devicetree.dtb\0"	\
	"devicetree_load_address=0x2000000\0"	\
	"boot_image=boot.bin\0"	\
	"loadbit_addr=0x100000\0"	\
	"loadbootenv_addr=0x2000000\0" \
	"kernel_size=0x500000\0"	\
	"devicetree_size=0x20000\0"	\
	"ramdisk_size=0x5E0000\0"	\
	"boot_size=0xF00000\0"	\
	"fdt_high=0x1E000000\0"	\
	"initrd_high=0x20000000\0"	\
	"bootenv=uEnv.txt\0" \
	"loadbootenv=load mmc 0 ${loadbootenv_addr} ${bootenv}\0" \
	"importbootenv=echo Importing environment from SD ...; " \
		"env import -t ${loadbootenv_addr} $filesize\0" \
	"sd_uEnvtxt_existence_test=test -e mmc 0 /uEnv.txt\0" \
	"preboot=env import -t 0xFFFFFC00" \
	"mmc_loadbit=echo Loading bitstream from SD/MMC/eMMC to RAM.. && " \
		"mmcinfo && " \
		"load mmc 0 ${loadbit_addr} ${bitstream_image} && " \
		"fpga load 0 ${loadbit_addr} ${filesize}\0" \
	"uenvboot=" \
		"if run loadbootenv; then " \
			"echo Loaded environment from ${bootenv}; " \
			"run importbootenv; " \
		"fi; " \
		"if test -n $uenvcmd; then " \
			"echo Running uenvcmd ...; " \
			"run uenvcmd; " \
		"fi\0" \
	"sdboot=echo Importing environment from SD... && mmcinfo && fatload mmc 0 0x2000000 uEnv.txt && env import -t 0x2000000 ${filesize} && boot"


#define PHY_ANEG_TIMEOUT	10000	/* PHY needs a longer aneg time */

#undef CONFIG_PHY_MARVELL

#undef CONFIG_SYS_I2C_EEPROM_ADDR_LEN
#undef CONFIG_SYS_I2C_EEPROM_ADDR
#undef CONFIG_SYS_EEPROM_PAGE_WRITE_BITS
#undef CONFIG_SYS_EEPROM_SIZE

#undef CONFIG_ENV_IS_NOWHERE
#undef CONFIG_ENV_SIZE
#undef CONFIG_ENV_OFFSET

#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN		2
#define CONFIG_SYS_I2C_EEPROM_ADDR		0x50
#define CONFIG_SYS_EEPROM_PAGE_WRITE_BITS	5
#define CONFIG_SYS_EEPROM_SIZE			8192 /* Bytes */

#define CONFIG_ENV_IS_IN_EEPROM
#define CONFIG_ENV_SIZE		1024 /* Total Size of Environment Sector */
#define CONFIG_ENV_OFFSET	(2048*3) /* WP area starts at last 1/4 of 8k eeprom */

#endif /* __CONFIG_ZYNQ_RED_PITAYA_H */
