/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/**
 * @file
 * @brief AIROC Voice Prompt Decoder definitions
 */

#pragma once

#include <stdint.h>
#include "wiced.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Definitions
 */
#define WICED_VPC_DECODER_HEADER_SIZE       5

#define WICED_VPC_DECODER_INPUT_SIZE_MAX    200

#define WICED_VPC_DECODER_OUTPUT_SAMPLES_NB 320     /* 320 samples every 40ms */

/*
 * wiced_vpc_decoder_init
 */
wiced_result_t wiced_vpc_decoder_init(void);

/*
 * wiced_vpc_decoder_header_parse
 */
wiced_result_t wiced_vpc_decoder_header_parse(uint8_t vpc_header[WICED_VPC_DECODER_HEADER_SIZE],
        uint32_t *p_next_nb_bytes);

/*
 * wiced_vpc_decoder_decode
 */
wiced_result_t wiced_vpc_decoder_decode(uint8_t *p_buffer_in, uint32_t buffer_in_size,
        int16_t *p_pcm_out, uint32_t *p_next_nb_bytes, wiced_bool_t *p_end_stream);


#ifdef __cplusplus
} /* extern "C" */
#endif
