/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * Average RSSI library
 *
 * Use this library to enable the average rssi events for ACL connections.
 * Add average_rss_lib.a in makefile to enable the feature as follows:
 * APP_PATCHES_AND_LIBS += average_rssi_lib.a
 *
 */

#include "wiced_bt_dev.h"

#define AVERAGE_RSSI_MAX_CONNECTIONS    3
#define BTHCI_EVENT_VS_AVERAGE_RSSI_EVENT_CODE      0x88

/* Structure of Average RSSI event */
typedef struct __attribute__((packed)) wiced_average_rssi_event
{
    uint8_t                             evt_code;   // The event code will be BTHCI_EVENT_VS_AVERAGE_RSSI_EVENT_CODE
    uint8_t                             status;     // Reserved for future. Always return 0 in current implementation
    uint8_t                             conn_num;   // The connection number for rssi, avg_rssi and conn_handle
    int8_t                              rssi[AVERAGE_RSSI_MAX_CONNECTIONS];     // The latest RSSI during the average interval
    int8_t                              avg_rssi[AVERAGE_RSSI_MAX_CONNECTIONS]; // The average RSSI during the average interval
    uint16_t                            conn_handle[AVERAGE_RSSI_MAX_CONNECTIONS]; // The connection handles, the same as in
                                                                                   // wiced_average_rssi_enable()
} wiced_average_rssi_event_t;


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Function         wiced_average_rssi_enable
 *
 *                  Enable the average rssi event
 * @param[in]       enable              : 1: enable the event  0: disable the event (the same as wiced_average_rssi_disable)
 * @param[in]       coefficient         : The paramter will be divided by 1024 as the coefficient in the internal 1st order IIR filter
 *                                        y[n] = ax[n] + (1-a)y[n-1]
 * @param[in]       interval            : The timer interval in 100 ms between consecutive average RSSI events
 * @param[in]       elna_gain           : The RSSI will be reduced by elna_gain before filtering
 * @param[in]       conn_handle_num     : The connection number of conn_handle
 * @param[in]       conn_handle         : The array of connection handle
 *
 * @return
 *
 *                  WICED_BT_SUCCESS     : Success
 *                  WICED_BT_NO_RESOURCE : No resource to issue command
 */
wiced_result_t wiced_average_rssi_enable(uint8_t enable, uint16_t coefficient, uint16_t interval,
    uint8_t elna_gain, uint8_t conn_handle_num, uint16_t conn_handle[]);

/**
 * Function         wiced_average_rssi_disable
 *
 *                  Disable the average rssi event
 *
 * @return
 *
                   WICED_BT_SUCCESS     : Success
 *                 WICED_BT_NO_RESOURCE : No resource to issue command
 */
wiced_result_t wiced_average_rssi_disable(void);


#ifdef __cplusplus
} /* extern "C" */
#endif
