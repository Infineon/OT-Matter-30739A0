/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
*
* List of parameters and defined functions needed to access the Microphone Driver.
*
*/

#ifndef __WICED_HAL_MIC_H__
#define __WICED_HAL_MIC_H__

//#include "mpaf/drivers/adc.h"
#include "brcm_fw_types.h"

/**
 * @brief Microphone Events.
 *
 * Microphone events received by the Microphone callback (see wiced_hal_mic_callback_t)
 */
typedef enum
{
    WICED_HAL_MIC_EVENT_RX_PCM = 0,
} wiced_hal_mic_event_t;

/**
 * @brief Microphone types.
 *
 * Microphone type
 */
typedef enum
{
    WICED_HAL_MIC_PDM = 0               /**< Digital (Pulse Density Modulation) Microphone */
} wiced_hal_mic_type_t;

/**
 * @brief Microphone Fifo Status.
 *
 * Microphone Fifo Error Status
 */
#define WICED_HAL_MIC_FIFO_STATUS_OK        0x00
#define WICED_HAL_MIC_FIFO_STATUS_OVERLAP   0x01
#define WICED_HAL_MIC_FIFO_STATUS_FULL      0x02
typedef UINT8 wiced_hal_mic_fifo_status_t;

/**
 * @brief Data associated with WICED_HAL_MIC_EVENT_RX_PCM.
 *
 * This event is received when Microphone Rx Data (PCM samples) have been received
 *
 */
typedef struct
{
    UINT8 channel;                    /**< Microphone channel (0 or 1) */
    UINT8 *p_data;                    /**< Pointer on PCM samples */
    UINT32 length;                    /**< Number of bytes in the p_data buffer */
    wiced_hal_mic_fifo_status_t status; /**< Status */
} wiced_hal_mic_rx_pcm_t;

/**
 * @brief Union of data associated with Microphone events
 *
 */
typedef union
{
    wiced_hal_mic_rx_pcm_t rx_pcm;
} wiced_hal_mic_event_data_t;

/**
 * Microphone Callback function type wiced_hal_mic_callback_t
 *
 *                  AIROC Microphone Event callback (registered with wiced_hal_mic_start)
 *
 * @param[in]       event: Microphone event received
 * @param[in]       p_data : Data (pointer on union of structure) associated with the event
 *
 * @return NONE
 */

typedef void (wiced_hal_mic_callback_t)(wiced_hal_mic_event_t event,
        wiced_hal_mic_event_data_t *p_data);

/******************************************************************************
*** Function prototypes and defines.
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


/**
 *
 * Function         wiced_hal_mic_init
 *
 *                  This function is called for Microphone Initialization.
 *
 * @param[in]       p_callback: Microphone callback
 * @param[in]       mic_type: Microphone type
 * @param[in]       nb_channels: Number of Microphone channels (1 or 2)
 * @param[in]       nb_buffers: Number of buffers (per channel)
 *
 * @return          Result code (see wiced_result_t)
 *
 */
wiced_result_t wiced_hal_mic_init(wiced_hal_mic_callback_t *p_callback,
        wiced_hal_mic_type_t mic_type, UINT32 nb_channels);

/**
 *
 * Function         wiced_hal_mic_select_pads
 *
 *                  This function is called to configure the Microphone pads (pins)
 *
 * @param[in]       channel_1_pad: Microphone Channel 1 Pad
 * @param[in]       channel_1_pad: Microphone Channel 2 Pad
 * @param[in]       channel_1_pad: Microphone Clock Pad (for WICED_HAL_MIC_PDM Microphone type)
 *
 * @return          Result code (see wiced_result_t)
 *
 */
wiced_result_t wiced_hal_mic_select_pads(UINT32 channel_1_pad, UINT8 rising_edge_1,
        UINT32 channel_2_pad, UINT8 rising_edge_2, UINT32 pdm_clock_pad);


/**
 *
 * Function         wiced_hal_mic_start
 *
 *                  This function is called to Start Microphone recording
 *
 * @param[in]       sample_rate: Sampling Rate
 * @param[in]       bits_per_sample: Number of bits per sample
 * @param[in]       gain: Gain
 *
 * @return          Result code (see wiced_result_t)
 *
 */
wiced_result_t wiced_hal_mic_start(UINT32 sample_rate, UINT32 bits_per_sample,
        UINT8 pga_gain);


/**
 *
 * Function         wiced_hal_mic_stop
 *
 *                  This function is called to Stop Microphone recording
 *
 * @return          Result code (see wiced_result_t)
 *
 */
wiced_result_t wiced_hal_mic_stop(void);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __WICED_HAL_MIC_H__ */
