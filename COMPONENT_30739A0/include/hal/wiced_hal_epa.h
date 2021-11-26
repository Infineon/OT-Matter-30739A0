
/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to access the
* External Power Amplifier (ePA) driver.
*
*/

#ifndef __WICED_EPA_H__
#define __WICED_EPA_H__


/**  \addtogroup ExternalPowerAmplifierDriver External Power Amplifier
*   \ingroup HardwareDrivers
*
* @{
*
* Defines a driver to facilitate interfacing with a external power amplifier.
*
* Use this driver to output the CTX and CRX signals needed to drive an
* external power amplifier frontend module
*
*/

/******************************************************************************
*** Parameters.
***
*** The following parameters are used to configure the driver or define
*** return status. They are not modifiable.
******************************************************************************/

//
typedef enum
{
    EPA_VCC_1P8V,
    EPA_VCC_3P3V
} wiced_bt_epa_vcc_config_t;

/******************************************************************************
*** Function prototypes and defines.
******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif


///////////////////////////////////////////////////////////////////////////////
/// Configures, enables, disables external power amplifier control signals
/// CTX and CRX. CTX/CRX can be mapped to WICED_P02, WICED_P04, WICED_P10,
/// WICED_P16, WICED_P17, WICED_P26, WICED_P28, WICED_P34.
///
/// \param ctx    - Tx control signal of external power amplifier
/// \param crx    - Rx control signal of external power amplifier
/// \param enable - TRUE enables normal control, FALSE disables control and
///                 configures ctx=0 and crx =1
/// \param vbias  - EPA_VCC_1P8V or EPA_VCC_3P3V
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_epa_configure(uint8_t ctx, uint8_t crx, wiced_bool_t enable, uint8_t vbias);

/** @} */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __WICED_EPA_H__
