/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to enable auto
* eLNA switch.
*
*/

#ifndef __WICED_HAL_RFM_H__
#define __WICED_HAL_RFM_H__

#ifdef __cplusplus
extern "C" {
#endif


///////////////////////////////////////////////////////////////////////////////
/// Configures, enables, disables auto eLNA switch
///
/// \param enable - 1 enables auto eLNA switch, 0 disables auto eLNA switch
/// \param rx_pu_pin - GPIO number of RX_PU
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_rfm_auto_elna_enable(BOOL8 enabled, wiced_bt_gpio_numbers_t rx_pu_pin);

///////////////////////////////////////////////////////////////////////////////
/// Configures, enables, disables auto ePA switch
///
/// \param enable - 1 enables auto ePA switch, 0 disables auto ePA switch
/// \param tx_pu_pin - GPIO number of TX_PU
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_rfm_auto_epa_enable(BOOL8 enabled, wiced_bt_gpio_numbers_t tx_pu_pin);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
