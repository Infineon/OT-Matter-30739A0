/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
/******************************************************************************
**
**  File Name:   celt_encoder_api.h
**
**  Description: This file has function declarations and structs for integration
**
**  Revision :
**               2015/11/26  hochangw
**
******************************************************************************/

#ifndef CELT_ENCODER_API_H
#define CELT_ENCODER_API_H

#include "celt_scratch.h"

/******************************************************************************
 *
 *  struct CELT_ENC_PARAMS
 *
 *****************************************************************************/

//struct CELT_ENC_PARAMS_TAG
typedef struct
{
    UINT32 celt_enc_scratch_buf[OPUS_CELT_ENC_SCRATCH_SIZE_UINT32];   /* decoder scratch buffer */
    UINT32 opus_celt_enc_st_buf[OPUS_CELT_ENC_ST_SIZE];

    INT32 sampling_rate;        /* 8k, 16k, 24k or 48k */
    INT16 channels;             /* 1 or 2 */
    INT32 bitrate;              /* bits per second */
    INT16 complexity;           /* 0 - 10 */
    INT16 use_vbr;              /* variable bit rate, 0:cbr, 1:vbr */
    INT16 use_cvbr;             /* constrained vbr, 0: enable, 1:disable */
    INT32 frame_size;           /* PCM samples of input per channel */
    INT16 *pcmBuffer;           /* Encoder input buffer */
    UINT8 *packet;              /* Encoder output buffer */

    /* Below variables are used inside CELT */
    void  *enc_handler;         /* OpusEncoder */

}CELT_ENC_PARAMS;
//typedef struct CELT_ENC_PARAMS_TAG CELT_ENC_PARAMS


/******************************************************************************
 *
 *  Function: CELT_Encoder
 *
 *  Abstract:    Read PCM samples, run the CEL Encoder and return the number of encoded samples
 *
 *  Param:
 *           * ptrEncParams  :   Pointer to CELT_ENC_PARAMS structure
 *
 *  Return:  Packet length (bytes)
 *
 *******************************************************************************/
 extern INT32 CELT_Encoder(CELT_ENC_PARAMS *ptr_enc_param);


 /******************************************************************************
 *
 *  Function: CELT_Encoder_Init
 *
 *  Abstract: InitCELT Encoder
 *
 *  Param:
 *           * ptr_enc_param  : Pointer to CELT_ENC_PARAMS structure
 *
 *  Return:  0 if success
 *
 *******************************************************************************/
 extern INT32 CELT_Encoder_Init(CELT_ENC_PARAMS *ptr_enc_param);


 /******************************************************************************
 *
 *  Function: CELT_Encoder_get_mem_size
 *
 *  Abstract:
 *
 *  Param:
 *           None
 *
 *  Return:  Needed memory size for CELT encoder
 *
 *******************************************************************************/
 extern UINT32 CELT_Encoder_get_mem_size(void);


/******************************************************************************
*
*  Function: CELT_Encoder_get_frame_len
*
*  Abstract:
*
*  Param:   ptr_enc_param->bitrate, ptr_enc_param->sampling_rate, ptr_enc_param->frame_size
*
*
*  Return:  Needed buffer size per frame for CELT encoder output
*
*******************************************************************************/
 extern UINT32 CELT_Encoder_get_frame_len(CELT_ENC_PARAMS *ptr_enc_param);


#endif
