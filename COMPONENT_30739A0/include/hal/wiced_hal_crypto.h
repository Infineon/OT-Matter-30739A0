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
 *   The same as ECC point structure in "foundation/hal/seceng/hw_seceng_api.h"
 */
typedef struct wiced_crypto_ecc_point_mul wiced_crypto_ecc_point_mul_t;
typedef void (*wiced_crypto_ecc_point_mul_callback)(wiced_crypto_ecc_point_mul_t *ecc_point_mul);
typedef struct wiced_crypto_ecc_point_mul
{
    UINT32 *hw_pka_next;	//PKA next point
    UINT8   hw_pka_next_id;	//PKA function id
    UINT8   hw_pka_skip_check;	//0: check PKA next point, 1: skip check
    INT8    order;		//data ordering: "Q_BIGNUM"(*Not available), "Q_NORMAL"
    UINT8   k_len;		//key length
    UINT8   src_len;		//source length
    UINT8   status;		//status
    UINT32 *k;			//Integer by which to multiply
    UINT32 *src_x;		//source: x
    UINT32 *src_y;		//source: y
    UINT32 *src_z;		//source: z
    UINT32 *cur_a;		//curve parameter: a
    UINT32 *cur_b;		//curve parameter: b
    UINT32 *cur_p;		//curve parameter: p
    UINT32 *dest_x;		//destination: x
    UINT32 *dest_y;		//destination: y
    UINT32 *dest_z;		//destination: z
    wiced_crypto_ecc_point_mul_callback callback;	//callback function
}wiced_crypto_ecc_point_mul_t;
//==================================================================================================
// Functions
//==================================================================================================
/*
 * Function         wiced_hal_crypto_ecc_point_mul
 *
 *                  use SEC_ENG API in "foundation/hal/seceng/hw_seceng_api.c"
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

