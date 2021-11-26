/*
 * $ Copyright Cypress Semiconductor $
 */

#pragma once

/* Include the actual RTOS definitions for:
 * - wiced_timed_event_t
 * - timed_event_handler_t
 */
#include "wiced_result.h"
#include "wiced_bt_dev.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    WICED_RTOS_DEFER_TO_MPAF_THREAD,
    WICED_RTOS_DEFER_TO_LM_THREAD,
    WICED_RTOS_MAX_DEFER_THREADS_SUPPORTED
}wiced_defer_context_t;

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *             Structures
 ******************************************************/

/** Defer execution of callback function to a different thread (currently only App and LM threads are supported)
 *
 * @param new_thread_context : thread context to which the execution is being defered to
 * @param func               : Callback function to be invoked from the thread context chosen above
 * @param data               : Data to be given to the above function
 *
 * @return    WICED_SUCCESS : on success.
 * @return    WICED_BADARG   : if an invalid arg is received
 */
wiced_result_t wiced_rtos_defer_execution(wiced_defer_context_t new_thread_context, void (*func)(void *), void *data);

/** @} */


#ifdef __cplusplus
} /*extern "C" */
#endif
