# DG405 Mux API
A simple driver for the DG405 8-channel multiplexer.

## Introduction
This package contains the DG405 8-channel multiplexer driver.
The driver includes dg405.c and dg405.h files.

## Integration details
* Integrate dg405.h and dg405.c files into the project
* Include the dg405.h file in your code like below.

## File information
* dg405.h : This header file contains the declarations of the driver APIs.
* dg405.c : This source file contains the definitions of the driver APIs.

## Supported interfaces
* GPIO

``` c
#include "dg405.h"
```

## User Guide
### Initialising the device
To intialise the device, the user must create a device structure. The user can do this by creating an instance of the structure dg405_dev. The user must then fill in the various parameters as shown below.

``` c
dg405_status_t rslt = DG405_OK;
dg405_dev mux1 = {
    .gpio_write = user_gpio_write,
    .gpio_read = user_gpio_read,
    .gpio_port_a  = GPIOB,
    .gpio_pin_a   = GPIO_PIN_12,
    .gpio_port_b  = GPIOB,
    .gpio_pin_b   = GPIO_PIN_13,
    .gpio_port_c  = GPIOB,
    .gpio_pin_c   = GPIO_PIN_14,
    .gpio_port_en = GPIOB,
    .gpio_pin_en  = GPIO_PIN_15
};

rslt = dg405_switch_output(&mux1, 3); /* Enable output X3 */
rslt = dg405_enable(&mux1);
````

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
