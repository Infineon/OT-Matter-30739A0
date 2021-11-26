/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * @addtogroup  wicedbt_audio_utils     AIROC Audio Utilities
 * @ingroup     wicedbt_av
 *
 * @{
 */
#pragma once

#include "wiced.h"

/*****************************************************************************
**           Constants
*****************************************************************************/

/*****************************************************************************
 *          Type Definitions
 *****************************************************************************/

/*****************************************************************************
 *          Function Prototypes
 *****************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


/**
 * Initialize the MP3 decoder.
 *
 * @param p_mem[in] : pointer to the allocated buffer used for decoding
 *
 * @return  WICED_TRUE  : Success
 *          WICED_FALSE : Fail
 */
wiced_bool_t wiced_mp3_codec_dec_init(void *p_mem);

/**
 * wiced_mp3_codec_dec_audio_frame_dec
 *
 * Decode the MP3 Audio Frame into PCM samples.
 * A MP3 Audio Frame includes a Audio Frame Header and a Audio Frame Body.
 * The MP3 Audio Frame shall start with the Audio Frame Header.
 *
 * @param[in]   p_in    : point to the input MP3 Audio Frame
 * @param[out]  p_out   : point to the output PCM samples
 * @param[in]   in_size :   size of the input MP3 Audio Frame in bytes
 *
 * @return      Size in bytes of the PCM data in output buffer
 */
uint32_t wiced_mp3_codec_dec_audio_frame_dec(void *p_in, void *p_out, uint32_t in_size);

/** @} wicedbt_audio_utils */


#ifdef __cplusplus
} /* extern "C" */
#endif
