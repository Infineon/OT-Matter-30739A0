/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/**
 * @file
 * @brief Implement platform functions required by standard buffered input/output functions
 */
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wiced.h>

#include <wiced_hal_duart.h>

int _close(int __fildes)
{
    UNUSED_VARIABLE(__fildes);

    errno = ENOSYS;
    return -1;
}

int _isatty(int __fildes)
{
    UNUSED_VARIABLE(__fildes);

    errno = ENOSYS;
    return 0;
}

_off_t _lseek(int __fildes, _off_t __offset, int __whence)
{
    UNUSED_VARIABLE(__fildes);
    UNUSED_VARIABLE(__offset);
    UNUSED_VARIABLE(__whence);

    errno = ENOSYS;
    return -1;
}

int _read(int __fd, void *__buf, size_t __nbyte)
{
    UNUSED_VARIABLE(__fd);
    UNUSED_VARIABLE(__buf);
    UNUSED_VARIABLE(__nbyte);

    errno = ENOSYS;
    return -1;
}


int _write(int __fd, const void *__buf, size_t __nbyte)
{
    UNUSED_VARIABLE(__fd);

    wiced_hal_duart_write((uint8_t *) __buf, __nbyte);

    return __nbyte;
}

int	_fstat(int __fd, struct stat *__sbuf)
{
    UNUSED_VARIABLE(__fd);
    UNUSED_VARIABLE(__sbuf);

    errno = ENOSYS;
    return -1;
}
