/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
/** @file
 *
 * This file provided functionality to provide debug traces
 *
 */


#ifndef __TFP_PRINTF__
#define __TFP_PRINTF__

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif


int wiced_printf(char * buf, int len, ...);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
