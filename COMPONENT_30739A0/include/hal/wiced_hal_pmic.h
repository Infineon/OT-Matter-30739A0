/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to utilize the PMIC API.
*
*/
#pragma once

#include <stdint.h>

/**  \addtogroup PMIC Power Management Integrated Circuit
*   \ingroup HardwareDrivers
*
* @{
*
* Defines a driver to facilitate interfacing with a PMIC.
*
*/

/**
 * PMIC Voltage Callback function type wiced_hal_pmic_voltage_callback_t
 *
 *                  PMIC Voltage Callback function (registered with
 *                  wiced_hal_pmic_voltage_callback_register)
 *
 * @param[in]       milli_volt: Voltage (in millivolts)
 *
 * @return          NONE
 */
typedef void (wiced_hal_pmic_voltage_callback_t)(uint16_t milli_volt);


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Low Level external FW function definition.
 *
 */
void pmu_ldo_trim_v2_set_pmic_fp(wiced_hal_pmic_voltage_callback_t *p_voltage_cb);

/**
 *
 * Function         wiced_bt_sco_hook_init
 *
 *                  This function is called for SCO Hook Initialization.
 *
 * @param[in]       p_callback: Pointer to application SCO Hook callback function
 *
 * @return          NONE
 *
 */
inline void wiced_hal_pmic_voltage_callback_register(wiced_hal_pmic_voltage_callback_t *p_cback)
{
    pmu_ldo_trim_v2_set_pmic_fp(p_cback);
}


#ifdef __cplusplus
} /* extern "C" */
#endif

/** @} */
