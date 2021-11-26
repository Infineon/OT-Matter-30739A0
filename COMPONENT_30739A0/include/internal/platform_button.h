/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
#pragma once

#include "wiced.h"
#include "data_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 *                      Macros
 ******************************************************/
/**
 * determine size (number of elements) in an array
 */
#define ARRAY_SIZE(a)                                ( sizeof(a) / sizeof(a[0]) )

/**
 * Macro to determine the element index in an array from the element address
 */
#define ARRAY_POSITION( array, element_pointer )     ( ((uint32_t)element_pointer - (uint32_t)array) / sizeof(array[0]) )

/******************************************************
 *                    Constants
 ******************************************************/

/******************************************************
 *                   Enumerations
 ******************************************************/
/* Logical Button-ids which map to phyiscal buttons on the board */
typedef enum
{
    PLATFORM_BUTTON_1,
	PLATFORM_BUTTON_2,
	PLATFORM_BUTTON_3,
	PLATFORM_BUTTON_4,
	PLATFORM_BUTTON_5,
	PLATFORM_BUTTON_6,
	PLATFORM_BUTTON_MAX,
} platform_button_t;
/******************************************************
 *                 Type Definitions
 ******************************************************/

typedef void (*platform_button_state_change_callback_t)( platform_button_t id, wiced_bool_t new_state );

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *                 Global Variables
 ******************************************************/

/******************************************************
 *               Function Declarations
 ******************************************************/
extern wiced_result_t  platform_button_init( platform_button_t button );
extern wiced_result_t  platform_button_deinit( platform_button_t button );
extern wiced_result_t  platform_button_enable( platform_button_t button );
extern wiced_result_t  platform_button_disable( platform_button_t button );
extern wiced_bool_t    platform_button_get_value( platform_button_t button );
extern wiced_result_t  platform_button_register_state_change_callback( platform_button_state_change_callback_t callback );

#ifdef __cplusplus
} /* extern "C" */
#endif
