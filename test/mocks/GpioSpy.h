#ifndef GPIO_SPY_H
#define GPIO_SPY_H

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void gpio_write(void* port, uint16_t pin, uint8_t *val);
void gpio_read(void* port, uint16_t pin, uint8_t *val);

#endif

#ifdef __cplusplus
}
#endif /* End of CPP guard */