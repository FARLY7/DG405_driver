# DG405_driver
A simple driver for the DG405 multiplexer.

### Templates for function pointers
``` c

dg405_status_t user_gpio_read(void* port, uint16_t pin)
{
    dg405_status_t rslt = DG405_OK;

    return rslt;
}

dg405_status_t user_gpio_write(void* port, uint16_t pin, uint8_t val)
{
    dg405_status_t rslt = DG405_OK;

    return rslt;
}

```