/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* DEBUG Universal Asynchronous Receiver/Transmitter (PUART) Driver.
*
*/

#ifndef __WICED_DUART_H__
#define __WICED_DUART_H__

#include "wiced_hal_gpio.h"

/****************************************************************************/
/**
 * @addtogroup  HardwareDrivers Hardware Drivers
 *
 * @{
 */
/****************************************************************************/
/**
 * Defines a driver to facilitate interfacing with the Debug UART hardware to
 * send bytes or a stream of bytes over the Debug UART hardware. Typical
 * use-cases involve printing messages over UART/RS-232.
 *
 * @addtogroup  DUARTDriver Debug UART (DUART)
 * @ingroup HardwareDrivers
 *
 * @{
 */
/****************************************************************************/

/*! @{ */

/******************************************************************************
*** Function prototypes.
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


///////////////////////////////////////////////////////////////////////////////
/// Initialize the Debug UART interface.
///
/// \param tx_pin - target transmit pin
/// \param rx_pin - target receive pin
/// \param baudrate - target baud rate
///
/// \return WICED_TRUE if Success
///
/// Notices: 1. If the tx_pin belongs to the LHL GPIO (<= WICED_P39), the ARM GPIO 6
///             (WICED_GPIO_06) cannot be set to other purpose.
///          2. If the rx_pin belongs to the LHL GPIO (<= WICED_P39), the ARM GPIO 7
///             (WICED_GPIO_07) cannot be set to other purpose.
///          3. The receive function is not supported now.
///////////////////////////////////////////////////////////////////////////////
wiced_bool_t wiced_hal_duart_init(wiced_bt_gpio_numbers_t tx_pin, wiced_bt_gpio_numbers_t rx_pin, uint32_t baudrate);

///////////////////////////////////////////////////////////////////////////////
/// Transmit data via Debug UART
///
/// \param p_buf - data to be sent
/// \param len - length of data in bytes
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_duart_write(uint8_t *p_buf, uint16_t len);


/* @} DUARTDriver */
/* @} HardwareDrivers */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __WICED_DUART_H__
