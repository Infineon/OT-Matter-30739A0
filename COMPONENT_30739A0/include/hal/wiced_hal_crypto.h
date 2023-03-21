/*
 * Copyright 2016-2023, Cypress Semiconductor Corporation (an Infineon company) or
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

/*
 * @file
 * Header for HW crypto API
 */

#ifndef _WICED_HAL_CRYPTO_H_
#define _WICED_HAL_CRYPTO_H_

//==================================================================================================
// Include
//==================================================================================================
#include <stdint.h>

//==================================================================================================
// Constants
//==================================================================================================
/** @brief wiced crypto result */
typedef enum
{
    WICED_CRYPTO_ECC_POINT_MUL_CFG_COMPLETE = 11,    //HW_ECC_POINT_MUL_CFG_COMPLETE
    WICED_CRYPTO_ECC_POINT_MUL_SUCCESS = 12,         //HW_ECC_POINT_MUL_SUCCESS
    WICED_CRYPTO_ECC_POINT_MUL_FAIL = 13,            //HW_ECC_POINT_MUL_FAIL
}wiced_crypto_result_t;

//==================================================================================================
// Type Definitions
//==================================================================================================
/*
 *   The structure of ECC point multiplication
 */
typedef struct wiced_crypto_ecc_point_mul wiced_crypto_ecc_point_mul_t;
typedef void (*wiced_crypto_ecc_point_mul_callback)(wiced_crypto_ecc_point_mul_t *ecc_point_mul);
typedef struct wiced_crypto_ecc_point_mul
{
    uint32_t *hw_pka_next;	//PKA next point
    uint8_t   hw_pka_next_id;	//PKA function id
    uint8_t   hw_pka_skip_check;	//0: check PKA next point, 1: skip check
    int8_t    order;		//data ordering: "Q_BIGNUM"(*Not available), "Q_NORMAL"
    uint8_t   k_len;		//key length
    uint8_t   src_len;		//source length
    uint8_t   status;		//status
    uint32_t *k;			//Integer by which to multiply
    uint32_t *src_x;		//source: x
    uint32_t *src_y;		//source: y
    uint32_t *src_z;		//source: z
    uint32_t *cur_a;		//curve parameter: a
    uint32_t *cur_b;		//curve parameter: b
    uint32_t *cur_p;		//curve parameter: p
    uint32_t *dest_x;		//destination: x
    uint32_t *dest_y;		//destination: y
    uint32_t *dest_z;		//destination: z
    wiced_crypto_ecc_point_mul_callback callback;	//callback function
}wiced_crypto_ecc_point_mul_t;

//==================================================================================================
// Functions
//==================================================================================================
/*
 * Function         wiced_hal_crypto_ecc_point_mul
 *
 *
 * @param[in]	    p_ecc_pt_mul: The parameters of ECC point multiplication
 *
 * @return
 *		    WICED_CRYPTO_ECC_POINT_MUL_CFG_COMPLETE  : hw config successfully
 *                  WICED_CRYPTO_ECC_POINT_MUL_SUCCESS       : hw return result successfully
 *                  WICED_CRYPTO_ECC_POINT_MUL_FAIL          : fail
 */
wiced_crypto_result_t wiced_hal_crypto_ecc_point_mul(wiced_crypto_ecc_point_mul_t *p_ecc_pt_mul);

#endif //_WICED_HAL_CRYPTO_H_
