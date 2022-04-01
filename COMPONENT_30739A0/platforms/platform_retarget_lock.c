/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

#include <sys/lock.h>
#include <wiced_rtos.h>

typedef struct __lock
{
    wiced_mutex_t * mutex;
} lock_t;

static void lock_init_recursive(lock_t * lock);

lock_t __lock___sinit_recursive_mutex;
lock_t __lock___sfp_recursive_mutex;
lock_t __lock___atexit_recursive_mutex;
lock_t __lock___malloc_recursive_mutex;
lock_t __lock___env_recursive_mutex;
lock_t __lock___tz_mutex;

void platform_retarget_lock_init(void)
{
    lock_init_recursive(&__lock___sinit_recursive_mutex);
    lock_init_recursive(&__lock___sfp_recursive_mutex);
    lock_init_recursive(&__lock___malloc_recursive_mutex);
}

void __retarget_lock_init_recursive(lock_t ** lock)
{
    (void) (lock);
}

void __retarget_lock_close_recursive(lock_t * lock)
{
    (void) (lock);
}

void __retarget_lock_acquire(lock_t * lock)
{
    (void) (lock);
}

void __retarget_lock_acquire_recursive(lock_t * lock)
{
    if (lock != NULL && lock->mutex != NULL)
    {
        wiced_rtos_lock_mutex(lock->mutex);
    }
}

void __retarget_lock_release(lock_t * lock)
{
    (void) (lock);
}

void __retarget_lock_release_recursive(lock_t * lock)
{
    if (lock != NULL && lock->mutex != NULL)
    {
        wiced_rtos_unlock_mutex(lock->mutex);
    }
}

void lock_init_recursive(lock_t * lock)
{
    lock->mutex = wiced_rtos_create_mutex();
    if (lock->mutex != NULL)
    {
        wiced_rtos_init_mutex(lock->mutex);
    }
}
