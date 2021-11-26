/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* \addtogroup  wiced_utils  AIROC Trace Utilities
* \ingroup     wicedsys
*
* @{
*
*Trace Utilities
*
* Support for applications to send debug or information messages to debug UART destinations.
*/
#ifndef _WICED_BT_TRACE_H_
#define _WICED_BT_TRACE_H_

#include <stdarg.h>
#include "string.h"
#include "wiced.h"
#include "wiced_bt_types.h"
#include "wiced_hal_puart.h"

//#define WICED_BT_TRACE_ENABLE
#ifdef WICED_BT_TRACE_ENABLE
#define WICED_SHIM_TRACE_ENABLE
#endif

/** Debug UARTs. Used when calling wiced_set_debug_uart.*/
typedef enum
{
    WICED_ROUTE_DEBUG_NONE  =  0x00, /**< No traces */
    WICED_ROUTE_DEBUG_TO_WICED_UART, /**< send debug strings in formatted AIROC HCI messages over HCI UART to ClientControl or MCU */
    WICED_ROUTE_DEBUG_TO_HCI_UART,   /**< send debug strings as plain text to HCI UART, used by default if wiced_set_debug_uart() not called */
    WICED_ROUTE_DEBUG_TO_DBG_UART,   /**< Deprecated */
    WICED_ROUTE_DEBUG_TO_PUART       /**< send debug strings as plain text to the peripheral uart (PUART) */
}wiced_debug_uart_types_t;

#ifdef WICED_BT_TRACE_ENABLE
/**
 * Macro         WICED_BT_TRACE
 *
 * Utility macro to output trace messages to the debug UART destination.
 *
 * Use this printf()-style macro to print custom messages from application code.
 * Standard printf() % format arguments supported include: 'u,d,i,x,X,c,s'
 *
 * In addition, a custom %B format argument is provided for convenience in printing
 * 6 octect Bluetooth addresses.  Supply a byte array as the corresponding argument
 * to match the %B format specifier.  For example:
 *
 * WICED_BT_TRACE("Received inquiry response from: %B\n", p_inquiry_result->remote_bd_addr);
 */
#define WICED_BT_TRACE(...)                 wiced_printf(NULL, 0, __VA_ARGS__)
/**
 * Macro         WICED_BT_TRACE_ARRAY
 *
 * Utility macro to dump a string message followed by an array of hex data to the debug UART destination.
 *
 * Use this macro to display a string message followed by up to 16 hex bytes of an array from application code.
 * For example:
 *
 * WICED_BT_TRACE_ARRAY("Received EIR data:\n", p_inquiry_result->eir);
 */
#define WICED_BT_TRACE_ARRAY(ptr, len, ...) wiced_printf(NULL, 0, __VA_ARGS__); wiced_trace_array(ptr, len);
#else
#include <stdio.h>
#define WICED_BT_TRACE(...) printf(__VA_ARGS__)
#define WICED_BT_TRACE_ARRAY(ptr, len, ...)
#endif


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Function         wiced_set_debug_uart
 *
 * To specify the UART to be used for the debug traces
 *
 * @param[in]      uart        : UART to be used
 *
 * @return          void
 *
 */
void wiced_set_debug_uart ( wiced_debug_uart_types_t uart );

/* @} */

// deprecated/internal
#ifdef WICED_SHIM_TRACE_ENABLE
#define WICED_SHIM_TRACE(...)     wiced_printf(NULL, 0, __VA_ARGS__)
#else
#define WICED_SHIM_TRACE(...)
#endif

#ifdef WICED_BT_TRACE_ENABLE
#define WICED_BT_TRACE_CRIT(...)            wiced_printf(NULL, 0, __VA_ARGS__)
#endif

void wiced_trace_array( const uint8_t* p_array, uint16_t len);
int wiced_printf(char * buffer, int len, ...);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _WICED_BT_TRACE_H_ */
