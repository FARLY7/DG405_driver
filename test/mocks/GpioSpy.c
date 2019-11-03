#include "GpioSpy.h"

void gpio_write(void* port, uint16_t pin, uint8_t *val)
{
   *((uint16_t*) port) |= (*val & 1) << pin;  
}

void gpio_read(void* port, uint16_t pin, uint8_t *val)
{
    *val = (*((uint16_t*) port) >> pin) & 1;
}
