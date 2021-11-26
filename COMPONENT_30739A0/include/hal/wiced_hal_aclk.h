
/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to access the
* Auxiliary Clock (aclk) driver.
*
*/

#ifndef __WICED_ACLK_H__
#define __WICED_ACLK_H__

#include "wiced.h"

/**  \addtogroup AuxClkDriver Auxiliary Clock (ACLK)
*   \ingroup HardwareDrivers
*
* @{
*
* Defines a driver to facilitate interfacing with the auxiliary clock.
*
* Use this driver to output a clock to a GPIO pin for external use. Two clock
* sources are avaliable: clk0 or clk1, as well as two base frequencies used
* to calulate the prescaler : 1 MHz or 24 MHz. Note that the desired GPIO pin
* must have already been configured to output for aclk. See the HW muxing
* section in the Kit Guide or HW User Manual for your device for more information.
*
*/

/******************************************************************************
*** Parameters.
***
*** The following enumerations are used to configure the driver or define
*** return status. They are not modifiable.
******************************************************************************/

// Available clock sources.
enum WICED_CLK_SRC_SEL
{
    WICED_ACLK0,
    WICED_ACLK1,
};

// Available base clock frequencies.
enum WICED_CLK_SRC_FREQ_SEL
{
    WICED_ACLK_FREQ_24_MHZ = 1
};

/******************************************************************************
*** Function prototypes and defines.
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


///////////////////////////////////////////////////////////////////////////////
/// Configures, enables, and starts the aclk to be active on a
/// preconfigured GPIO pin.
///
/// (!) Note that the desired GPIO pin must have already been configured
/// to output for aclk. See the HW muxing section in the HW User Manual or Kit
/// Guide for your device for more information.
///
/// \param frequency   - Desired frequency (in KHz) to output; 0 is the same as disable.
/// \param clkSrc      - ACLK0 or ACLK1
/// \param baseFreqSel - ACLK_FREQ_24_MHZ.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_aclk_enable(uint32_t frequency,
                                         uint32_t clkSrc,
                                         uint32_t baseFreqSel);


///////////////////////////////////////////////////////////////////////////////
/// Disables the desired auxilary clock source.
///
/// \param clkSrc - Clock source to disable (aclk0 or aclk1).
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_aclk_disable(uint32_t clkSrc);

/** @} */


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __WICED_ACLK_H__
