/***************************************************************************//**
*   @file   demo_dev.h
*   @brief  Header file of iio_demo
*   @author Cristian Pop (cristian.pop@analog.com)
*   @author Mihail Chindris (mihail.chindris@analog.com)
********************************************************************************
* Copyright 2019(c) Analog Devices, Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*  - Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  - Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*  - Neither the name of Analog Devices, Inc. nor the names of its
*    contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*  - The use of this software may or may not infringe the patent rights
*    of one or more patent holders.  This license does not release you
*    from the requirement that you obtain separate licenses from these
*    patent holders to use this software.
*  - Use of the software either in source or binary form, must be run
*    on or directly connected to an Analog Devices Inc. component.
*
* THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef IIO_DEMO_H_
#define IIO_DEMO_H_

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/

#include <stdio.h>
#include "iio_types.h"

/******************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/

#define DEMO_NUM_CHANNELS	2
#define MAX_REG_ADDR		10
#define NB_LOCAL_SAMPLES	500

/** Local channel for loopback */
uint16_t local_ch[DEMO_NUM_CHANNELS][NB_LOCAL_SAMPLES];

/**
 * @struct iio_demo_desc
 * @brief Desciptor.
 */
struct iio_demo_desc {
	/** Dummy registers of device for testing direct_reg_access attribute */
	uint32_t dummy_regs[MAX_REG_ADDR];
	/** Active reg	 */
	uint32_t active_reg_addr;
	/** Demo global device attribute */
	uint32_t dev_global_attr;
	/** Demo device channel attribute */
	uint32_t dev_ch_attr;
	/** Active channels */
	uint32_t ch_mask;
};

/**
 * @struct iio_demo_init_param
 * @brief iio demo configuration.
 */
struct iio_demo_init_param {
	/** Demo global device attribute */
	uint32_t dev_global_attr;
	/** Demo device channel attribute */
	uint32_t dev_ch_attr;
};

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/

ssize_t get_demo_channel_attr(void *device, char *buf, size_t len,
			      const struct iio_ch_info *channel);
ssize_t set_demo_channel_attr(void *device, char *buf, size_t len,
			      const struct iio_ch_info *channel);
ssize_t get_demo_global_attr(void *device, char *buf, size_t len,
			     const struct iio_ch_info *channel);
ssize_t set_demo_global_attr(void *device, char *buf, size_t len,
			     const struct iio_ch_info *channel);

ssize_t get_demo_reg_attr(void *device, char *buf, size_t len,
			  const struct iio_ch_info *channel);
ssize_t set_demo_reg_attr(void *device, char *buf, size_t len,
			  const struct iio_ch_info *channel);

int32_t iio_demo_update_active_channels(void *dev, uint32_t mask);
int32_t iio_demo_close_channels(void *dev);
int32_t	iio_demo_read_local_samples(void *dev, uint16_t *buff, uint32_t samples);
int32_t	iio_demo_write_local_samples(void *dev, uint16_t *buff, uint32_t samples);

/* Init function. */
int32_t iio_demo_dev_init(struct iio_demo_desc **desc,
			  struct iio_demo_init_param *param);
/* Free the resources allocated by iio_demo_init(). */
int32_t iio_demo_dev_remove(struct iio_demo_desc *desc);

#endif /* IIO_DEMO_H_ */
