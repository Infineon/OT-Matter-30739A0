/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
/**
 * A few utilities with a reasonable implementation for SPAR.
 */
#pragma once

#ifdef __GNUC__
#define sprintf __2sprintf
#define snprintf __2snprintf
#endif

unsigned int _tx_v7m_get_and_disable_int(void);
void _tx_v7m_set_int(unsigned int posture);

#if ENABLE_DEBUG
#include "wiced_hal_wdog.h"
#include <string.h>

/// When debugging is enabled, sets up the HW for debugging.
#define SETUP_APP_FOR_DEBUG_IF_DEBUG_ENABLED()   do{        \
      wiced_hal_gpio_select_function(CY_PLATFORM_SWDCK, WICED_SWDCK); \
      wiced_hal_gpio_select_function(CY_PLATFORM_SWDIO, WICED_SWDIO); \
      wiced_hal_wdog_disable(); \
   }while(0)

/// Optionally waits in a pseudo while(1) until the user allows the CPU to continue
#define BUSY_WAIT_TILL_MANUAL_CONTINUE_IF_DEBUG_ENABLED()     do{   \
        volatile unsigned char spar_debug_continue = 0;             \
        unsigned int interrupt_save = _tx_v7m_get_and_disable_int();\
        while(!spar_debug_continue);                                \
        _tx_v7m_set_int(interrupt_save);                            \
        }while(0)
#else
#define SETUP_APP_FOR_DEBUG_IF_DEBUG_ENABLED()
#define BUSY_WAIT_TILL_MANUAL_CONTINUE_IF_DEBUG_ENABLED()
#endif

/// Allow the app to place code in retention RAM.
/// Note that there is very limited retention RAM, so choose
/// what goes into this area very carefully.
#define PLACE_CODE_IN_RETENTION_RAM    __attribute__ ((section(".code_in_retention_ram")))

/// Allow app to place this data in retention RAM.
#define PLACE_DATA_IN_RETENTION_RAM    __attribute__ ((section(".data_in_retention_ram")))

// If we panic from SPAR, we might not even have access to anything in
// the ROM or the Flash -- we suspect that we've been linked against
// the wrong image. So this.

#define SPAR_ASSERT_PANIC(expr) \
    do { if (!(expr)) while (1) ; } while(0)
