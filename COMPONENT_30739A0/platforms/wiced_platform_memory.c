/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#include <stddef.h>

#include "wiced_memory.h"
#include "wiced_platform_os.h"

/**
 * \brief       Allocate memory from the dynamic memory pool.
 *
 * @param[in]   size - size of required memory block
 *
 * @retval      address of the allocate memory block
 *
 */
void *wiced_platform_memory_allocate(uint32_t size)
{
    uint32_t *p_addr = NULL;

    wiced_platform_os_preemption_suspend();

    p_addr = (uint32_t *) wiced_memory_allocate(size);

    wiced_platform_os_preemption_resume();

    return p_addr;
}

/**
 * \brief       Free a memory block.
 *
 * @param[in]   p_addr - start address of the memory block to be freed
 */
void wiced_platform_memory_free(void *p_addr)
{
    wiced_platform_os_preemption_suspend();

    wiced_memory_free(p_addr);

    wiced_platform_os_preemption_resume();
}
