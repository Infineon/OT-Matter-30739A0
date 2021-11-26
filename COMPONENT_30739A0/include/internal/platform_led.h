/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
#pragma once

#include "wiced.h"
#include "data_types.h"
#include "wiced_hal_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 *                      Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/

/******************************************************
 *                   Enumerations
 ******************************************************/
typedef struct
{
    const uint32_t gpio_pin;
	uint8_t channel;
    wiced_bool_t invert;
} platform_led_config_t;

/* Logical led-ids which map to phyiscal leds on the board */
typedef enum
{
    PLATFORM_LED_1,
    PLATFORM_LED_2,
    PLATFORM_LED_MAX, /* Denotes the total number of led on the board. Not a valid Alias */
} platform_led_t;

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *                 Global Variables
 ******************************************************/
extern platform_led_config_t platform_led_config[PLATFORM_LED_MAX];
/******************************************************
 *               Function Declarations
 ******************************************************/
extern wiced_result_t  platform_led_init( const platform_led_config_t* pwm, uint32_t frequency, uint32_t duty_cycle );
extern wiced_result_t  platform_led_reinit( const platform_led_config_t* pwm, uint32_t frequency, uint32_t duty_cycle );
extern wiced_result_t  platform_led_start( const platform_led_config_t* pwm );
extern wiced_result_t  platform_led_stop( const platform_led_config_t* pwm );
extern wiced_result_t  platform_led_deinit( const platform_led_config_t* pwm );

#ifdef __cplusplus
} /* extern "C" */
#endif
