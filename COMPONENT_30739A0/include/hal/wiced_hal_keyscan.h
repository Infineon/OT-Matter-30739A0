/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to access the
* Key Scan driver.
*
*/

#ifndef __WICED_KEYSCAN_H__
#define __WICED_KEYSCAN_H__

#include "brcm_fw_types.h"
#include "keyscan.h"


#ifdef __cplusplus
extern "C" {
#endif


/**  \addtogroup keyscan Keyscan Interface
 *  \ingroup HardwareDrivers
*/
/*! @{ */
/**
* Defines the keyscan driver. The keyscan driver
* provides the status and control for the keyscan driver. It provides the
* keyEvents to the interface, maintains the queue behind it. It also supports
* keyscanning turning on or off.
*
*/

///////////////////////////////////////////////////////////////////////////////
/// configure Keyscan matrix row and column
///
/// Application use this to configure its number of keyscan matrix rows and columns. This only
/// need to be done once before keyscan driver initialization
///
/// \param num_rows - number of rows in keyscan matrix
/// \param num_columns - number of columns in keyscan matrix
///
/// \return - none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_keyscan_configure(uint8_t num_rows, uint8_t num_columns);

////////////////////////////////////////////////////////////////
/// Keyscan driver initialization function. Thisw allocates
/// space for the FW FIFO for key events and initializes
/// the keyscan HW. This function should be invoked only once
/// before using any keyscan services. Subsequent invocations
/// will invoke undefined behavior.
/// Keyscan driver must be initialized AFTER mia driver is initialized.
///
/// \param -none
///
/// \return - none
////////////////////////////////////////////////////////////////
void wiced_hal_keyscan_init(void);

/////////////////////////////////////////////////////////////////////
/// Reset the keyscan HW. All state information and events are lost.
/// Any pressed keys will be detected anew.
///
/// \param -none
///
/// \return - none
/////////////////////////////////////////////////////////////////////
void wiced_hal_keyscan_reset(void);

/////////////////////////////////////////////////////////////////////
///  Turns off the keyscan HW
///
/// \param -none
///
/// \return - none
/////////////////////////////////////////////////////////////////////
void wiced_hal_keyscan_turnOff(void);


////////////////////////////////////////////////////////////////
/// Register for notification of changes.
/// Once registered, you CAN NOT UNREGISTER; registration is meant to
/// be a startup activity
///
/// \param userfn - points to the function to call when the interrupt
///          comes and matches one of the masks (if you pass a method, it must
///          be static). The function does not need to clear the interrupt
///          status; this will be done by KeyscanDriver::lhlInterrupt(). The
///          function will be called ONCE per interrupt.
/// \param userdata - will be passed back to userfn as-is;
///
///\return - none
////////////////////////////////////////////////////////////////
void wiced_hal_keyscan_register_for_event_notification(void (*userfn)(void*), void* userdata);

/////////////////////////////////////////////////////////////////////
/// Enable/disable keyscan ghost key detection.
///
/// \param enable - enable(WICED_TRUE)/disable(WICED_FALSE)
///
///\return - none
/////////////////////////////////////////////////////////////////////
void wiced_hal_keyscan_enable_ghost_detection(wiced_bool_t enable);

/////////////////////////////////////////////////////////////////////
/// Configure GPIOs for keyscan operation. Note that only GPIOs
/// that are in the matrix are configured for keyscan operation.
/// GPIOs that are not part of the scan matrix are left alone.
///
/// \param -none
///
/// \return - none
/////////////////////////////////////////////////////////////////////
void wiced_hal_keyscan_config_gpios(void);

/////////////////////////////////////////////////////////////////////
/// check if HW detects any pressed key
///
/// \param -none
///
/// \return - WICED_TRUE -some key is pressed
///               WICED_FALSE -all keys are released
/////////////////////////////////////////////////////////////////////
wiced_bool_t wiced_hal_keyscan_is_any_key_pressed(void);

/* @} */

/**  \addtogroup keyscanQueue Keyscan Interface Queue
 *  \ingroup keyscan
 */

/*! @{ */
/**
* Defines a keyscan driver.
*
* The keyscan interface is practically defined as a queue from the consumer's
* perspective. Key up/down events are seen as a stream coming from the driver.
* In addition the interface provides the user with the ability to reset the
* HW as well as turn key scanning on/off.
*/
/////////////////////////////////////////////////////////////////////
/// Check if there are any pending events in the firmware FIFO
///
/// \return
///   - WICED_TRUE if keyscan events are pending in firmware FIFO
///   - WICED_FALSE otherwise
/////////////////////////////////////////////////////////////////////
wiced_bool_t wiced_hal_keyscan_events_pending(void);

/////////////////////////////////////////////////////////////////////
///  Get the next event. Note that this function only returns events
/// from the FW FIFO. It does not check the HW. The HW is checked
/// when the MIA poll function is called.
///
/// \param key - pointer to the key event
/// \return
///     - WICED_FALSE - if FW fifo is empty,
///     - WICED_TRUE  - otherwise.
///
/////////////////////////////////////////////////////////////////////
wiced_bool_t wiced_hal_keyscan_get_next_event(KeyEvent *key);

////////////////////////////////////////////////////////////////////////////////
/// Clears the keys in the HW queue
///
/// \param -none
///
/// \return - none
////////////////////////////////////////////////////////////////////////////////
void wiced_hal_keyscan_flush_HW_events(void);

/* @} */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
