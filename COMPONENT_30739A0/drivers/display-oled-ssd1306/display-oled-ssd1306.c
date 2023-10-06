#include "display-oled-ssd1306.h"
#include "mtb_ssd1306_i2c.h"

/*********************************************************************
*
*       wiced_hal_i2c_write
*
* Purpose:
*   Initializes the display controller
*/
void CYW9BTMDM2BASE1_InitController(void)
{
    mtb_ssd1306_write_command_byte(OLED_DISPLAY_OFF);

    for(uint8_t i=0;i<8;i++)
    {   mtb_ssd1306_write_command_byte(0xb0+i);
        mtb_ssd1306_write_command_byte(0x00);
        mtb_ssd1306_write_command_byte(0x10);
        for(uint8_t n=0;n<128;n++)
            mtb_ssd1306_write_data_byte(0);                         //Clear screen
    }

    mtb_ssd1306_write_command_byte(OLED_SET_DISPLAY_CLOCK_DIV);
    mtb_ssd1306_write_command_byte(OLED_DISPLAY_CLOCK_DIVIDE_RATIO |
                                  (OLED_OSCILLATOR_FREQUENCY << 4));

    mtb_ssd1306_write_command_byte(OLED_SET_MULTIPLEX);
    mtb_ssd1306_write_command_byte(YSIZE_PHYS - 1);

    mtb_ssd1306_write_command_byte(OLED_SET_DISPLAY_OFFSET);
    mtb_ssd1306_write_command_byte(OLED_DISPLAY_OFFSET);

    mtb_ssd1306_write_command_byte(OLED_SET_START_LINE | 0x0);     // line #0

    mtb_ssd1306_write_command_byte(OLED_CHARGE_PUMP);
    mtb_ssd1306_write_command_byte(OLED_ENABLE_CHARGE_PUMP);

    mtb_ssd1306_write_command_byte(OLED_MEMORY_MODE);
    mtb_ssd1306_write_command_byte(OLED_MEMORY_MODE_PAGE_ADDRESSING);

    mtb_ssd1306_write_command_byte(OLED_SEGMENT_REMAP | 0x1);

    mtb_ssd1306_write_command_byte(OLED_SET_COM_SCAN_DIRECTION);

    mtb_ssd1306_write_command_byte(OLED_SET_COM_PINS);
    mtb_ssd1306_write_command_byte(OLED_SET_COM_PINS_YSIZE);

    mtb_ssd1306_write_command_byte(OLED_SET_CONTRAST);
    mtb_ssd1306_write_command_byte(OLED_CONTRAST);

    mtb_ssd1306_write_command_byte(OLED_SET_PRECHARGE);
    mtb_ssd1306_write_command_byte(OLED_PRECHARGE);

    mtb_ssd1306_write_command_byte(OLED_SET_VCOMH_DESELECT_LEVEL);
    mtb_ssd1306_write_command_byte(OLED_VCOMH_DESELECT_LEVEL);

    mtb_ssd1306_write_command_byte(OLED_ENTIRE_DISPLAY_ON_RESUME);

    mtb_ssd1306_write_command_byte(OLED_NORMAL_DISPLAY);

    mtb_ssd1306_write_command_byte(OLED_DEACTIVATE_SCROLL);

    mtb_ssd1306_write_command_byte(OLED_DISPLAY_ON);
}