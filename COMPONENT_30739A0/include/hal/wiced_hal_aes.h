/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to calculate the
* AES with Hardware acceleration.
*
*/

#ifndef __WICED_AES_H__
#define __WICED_AES_H__

/**  \addtogroup AesCalculation
* \ingroup HardwareDrivers
* @{
*
* Defines a driver for the AES calculation with Hardware acceleration.
* It uses a 16 bytes key and 16 bytes input data to generate a 16 bytes ouput data.
* These are useful for applications such as authentication.
*
*/

/******************************************************************************
*** Function prototypes and defines.
******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// Calculate AES encryption by using Hardware acceleration
///
/// \param in_data  - point to input data buffer
/// \param out_data - point to output data buffer
/// \param key      - point to key data buffer
///
/// \return         - none
////////////////////////////////////////////////////////////////////////////////
void wiced_bcsulp_AES(uint8_t* key, uint8_t* in_data, uint8_t* out_data);

/* @} */

#endif // __WICED_AES_H__
