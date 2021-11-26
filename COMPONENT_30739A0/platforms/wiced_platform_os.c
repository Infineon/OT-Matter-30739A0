/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

extern volatile unsigned int _tx_thread_preempt_disable;

extern void _tx_thread_system_preempt_check(void);

/**
 * \brief Suspend/Disable the OS thread preemption capability.
 */
void wiced_platform_os_preemption_suspend(void)
{
    _tx_thread_preempt_disable++;
}

/**
 * \brief Resume/Enable the OS thread preemption capability.
 */
void wiced_platform_os_preemption_resume(void)
{
    _tx_thread_preempt_disable--;
    _tx_thread_system_preempt_check();
}
