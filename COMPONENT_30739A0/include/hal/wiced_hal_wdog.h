/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to utilize the
* watchdog.
*
*/

#ifndef __WICED_WDOG_RESET_H__
#define __WICED_WDOG_RESET_H__

#include "wiced.h"
#include "wiced_bt_types.h"

/**  \addtogroup WatchdogInterface Watchdog Interface
* \ingroup HardwareDrivers
* Defines a driver for the watchdog interface. This driver manages the
* hardware watchdog countdown timer. When enabled, the watchdog timer will generate
* an interrupt when the timer counts down to zero, then will reload the counter.
* If the counter counts down to zero again, the hardware performs a device reset.
* The lowest priority "idle" thread restarts the watchdog counter preiodically,
* and other operations that may keep the system busy call wiced_hal_wdog_restart to
* extend the watchdog countdown.
*/
/*! @{ */

/******************************************************************************
*** Type definitions.
******************************************************************************/
typedef void (wiced_hal_application_wdog_cback_t)(uint8_t* app_thread_cb,
        uint32_t app_thread_cb_size, uint8_t* app_thread_stack, uint32_t app_thread_stack_size);

/******************************************************************************
*** Function prototypes.
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


///////////////////////////////////////////////////////////////////////////////
/// Disable the system watchdog. Useful for debugging when the watchdog would
/// interfere and reset the system when not desired (e.g. when the system
/// is connected to a debugger, etc).
///
/// NOTE: This is for debugging purposes only. Hence, there is no complementary
/// "Enable Watchdog" function. Please do *not* use this function in production
/// applications.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_wdog_disable(void);

///////////////////////////////////////////////////////////////////////////////
/// Execute a soft reset of the system.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_wdog_reset_system(void);

///////////////////////////////////////////////////////////////////////////////
/// Restart the watchdog (restart the watchdog's internal timer). Used to
/// manually "pet" the watchdog when certain processes might otherwise cause
/// the watchdog to trigger and reset the system.
/// The default timeout for watchdog reset is two seconds.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_wdog_restart(void);

///////////////////////////////////////////////////////////////////////////////
/// Change the watchdog count down
///
/// \param count: countdown reload value for watchdog, 128000 = 1 sec for 20739B1
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_wdog_set_restart_countdown(uint32_t count);

///////////////////////////////////////////////////////////////////////////////
/// Enables application thread watchdog
///
/// \param p_application_wdog_cback: callback to be called when appliation thread is deadlocked
///
/// \return wiced_result_t
///////////////////////////////////////////////////////////////////////////////
wiced_result_t wiced_hal_wdog_enable_application_wdog(wiced_hal_application_wdog_cback_t *p_application_wdog_cback);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __WICED_WDOG_RESET_H__
