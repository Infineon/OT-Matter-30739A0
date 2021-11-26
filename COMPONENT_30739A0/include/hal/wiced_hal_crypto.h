/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* Definitions of the crypto functions: sha2_hmac.
*
*/

#ifndef __WICED_HAL_CRYPTO_H__
#define __WICED_HAL_CRYPTO_H__

/******************************************************************************
*** Function prototypes and defines.
******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// Calculated HMAC-SHA. Output = HMAC-SHA-256(224)( hmac key, input buffer )
///
/// \param key     - HMAC secret key
/// \param keylen  - length of the HMAC key
/// \param input   - buffer holding the  data
/// \param ilen    - length of the input data
/// \param output  - HMAC-SHA-224/256 result
/// \param is224   - 0 = use SHA256, 1 = use SHA224
////////////////////////////////////////////////////////////////////////////////
void wiced_sha2_hmac( const unsigned char *key, uint32_t keylen,
                      const unsigned char *input, uint32_t ilen,
                      unsigned char output[32], int32_t is224 );

#endif // __WICED_HAL_CRYPTO_H__
