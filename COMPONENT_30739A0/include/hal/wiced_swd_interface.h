/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/*******************************************************************************
 * All common definitions for configuring SWD interface pins
 *******************************************************************************/

#ifndef _WICED_SWD_INTERFACE__H_
#define _WICED_SWD_INTERFACE__H_

#include "wiced_hal_gpio.h"

 /* Enum of all the possible pins through which SWDCK can be routed. */
typedef enum
{
    SWDCK_DISABLED = -1,
    SWDCK_ON_P01
}SWDCK_pin_t;

/* Enum of all the possible pins through which SWDIO can be routed. */
typedef enum
{
    SWDIO_DISABLED = -1,
    SWDIO_ON_P00
}SWDIO_pin_t;

#ifdef __cplusplus
extern "C" {
#endif


/* Choose the pins for SWDIO and SWDCK */
void wiced_configure_swd_pins(SWDCK_pin_t swdck_pin, SWDIO_pin_t swdio_pin);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  /* _WICED_SWD_INTERFACE__H_ */
