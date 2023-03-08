/*
 * $ Copyright Cypress Corporation $
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
