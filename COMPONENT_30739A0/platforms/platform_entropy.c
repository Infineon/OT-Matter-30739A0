/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#include <stddef.h>
#include <wiced_hal_rand.h>


wiced_result_t wiced_platform_entropy_get(uint8_t *output, uint16_t output_length)
{
    uint16_t remain_length;
    uint8_t *p_index = NULL;
    uint32_t rand_num = 0;
    uint8_t i;
    uint8_t shift;

    if (output == NULL)
    {
        return WICED_BADARG;
    }

    remain_length = output_length;
    p_index = output;
    i = 0;

    while (remain_length)
    {
        if (i % sizeof(uint32_t) == 0)
        {
            rand_num = wiced_hal_rand_gen_num();
        }

        shift = 8 * (i % sizeof(uint32_t));
        *p_index = (uint8_t) (rand_num >> shift);

        p_index++;
        i++;
        remain_length--;
    }

    return WICED_SUCCESS;
}
