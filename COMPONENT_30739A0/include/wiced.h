/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/****************************************************************************
**
** Name:         wiced.h
**
** Description:  wiced header file for VS2010 projects
**
**
******************************************************************************/
#ifndef WICED_H
#define WICED_H

#include "wiced_result.h"
#include "stdint.h"

/* Suppress unused variable warning */
#ifndef UNUSED_VARIABLE
#define UNUSED_VARIABLE(x) /*@-noeffect@*/ ( (void)(x) ) /*@+noeffect@*/
#endif

#define WICED_SUPPRESS_WARNINGS(m) if((m)){;}

typedef unsigned int   wiced_bool_t;

#define WICED_FALSE 0
#define WICED_TRUE  1

#define WPRINT_BT_APP_INFO(info)   {printf info;}

#endif //WICED_H
