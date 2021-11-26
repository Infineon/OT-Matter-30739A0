/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
#ifndef CELT_SCRATCH_H
#define CELT_SCRATCH_H

#include "brcm_fw_types.h"

typedef struct
{
    UINT32 *buf_base;
    UINT16 buf_offset;
    UINT16 buf_size;
}tCELT_SCRATCH_BUFFER_STATE;


#define OPUS_CELT_DEC_ST_SIZE   2*9300         //byte
#define OPUS_CELT_DEC_SCRATCH_SIZE_UINT32  (OPUS_CELT_DEC_ST_SIZE/4) + 4500 + ((3504*2*2)/4)    //4500 for decoder, ((3504*2*2)/4) for plc
                                                                                                //3504: xqbuflenmax, 2:INT16=2bytes, 2:channels, /4:UINT32=4bytes
#define OPUS_CELT_DEC_SCRATCH_SIZE_BYTE    OPUS_CELT_DEC_SCRATCH_SIZE_UINT32*4

#define OPUS_CELT_PLC_STRUCT_SIZE_BYTE     580  //sizeof(struct CELT_AUDIOPLC_STRUCT)=569

#define OPUS_CELT_ENC_ST_SIZE   3000
#define OPUS_CELT_ENC_SCRATCH_SIZE_UINT32   9000
#define OPUS_CELT_ENC_SCRATCH_SIZE_BYTE     OPUS_CELT_ENC_SCRATCH_SIZE_UINT32*4



#if !defined (CELT_INTEGRATE)
extern UINT32 g_celt_dec_scratch_buf[OPUS_CELT_DEC_SCRATCH_SIZE_UINT32];

extern UINT32 g_celt_enc_scratch_buf[OPUS_CELT_ENC_SCRATCH_SIZE_UINT32];
extern UINT32 g_opus_celt_enc_st_buf[OPUS_CELT_ENC_ST_SIZE];
#endif


extern tCELT_SCRATCH_BUFFER_STATE g_celt_enc_scratch_buf_st;
extern tCELT_SCRATCH_BUFFER_STATE g_celt_dec_scratch_buf_st;

#endif
