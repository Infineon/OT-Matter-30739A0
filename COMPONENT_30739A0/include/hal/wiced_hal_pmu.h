/*
 * Copyright 2016-2021, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/** @file
 *
 * To provide the methods to set the GPIO alive when into sleep
 *
 */

#ifndef _WICED_HAL_PMU_H_
#define _WICED_HAL_PMU_H_

//==================================================================================================
// Include
//==================================================================================================
#include "wiced_bt_dev.h"
#include "wiced_result.h"

//==================================================================================================
// Functions
//==================================================================================================

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief To init the power down config array data
 * @return @ref wiced_result_t
 */
wiced_result_t wiced_hal_pmu_init_pd_config(void);

/**
 * @brief To set the power down config array data to default value
 * @return @ref wiced_result_t
 */
wiced_result_t wiced_hal_pmu_clear_alive_pin_config(void);

/**
 * @brief To set the pin to keep original active in sleep mode
 * @param[in]  pin   The pin number
 * @return @ref wiced_result_t
 */
wiced_result_t wiced_hal_pmu_set_alive_pin_config(uint8_t pin);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //_WICED_HAL_PMU_H_
