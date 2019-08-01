/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * File        dg405.h
 * Created by  Sean Farrelly
 * Version     1.0
 * 
 */

/*! @file dg405.h
 * @brief Driver for DG405 multiplexer.
 */


/*!
 * @defgroup DG405 MUX API
 */
#ifndef DG405_H_
#define DG405_H_

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

/*!
 * @brief API status codes
 */
typedef enum {
    DG405_OK,
    DG405_E_NULL_PTR
} dg405_status_t;

/*!
 * @brief Type definitions
 */
typedef void    (*dg405_gpio_write_fptr_t)(void* port, uint16_t pin, uint8_t val);
typedef uint8_t (*dg405_gpio_read_fptr_t) (void* port, uint16_t pin);

/*!
 * @brief dg405 device structure
 */
typedef struct {

    /* Gpio write function pointer */
    dg405_gpio_write_fptr_t gpio_write;

    /* Gpio read function pointer */
    dg405_gpio_read_fptr_t gpio_read;

    /* Gpio pin A  */
    void *gpio_port_a;
    uint16_t gpio_pin_a;

    /* Gpio pin B */
    void *gpio_port_b;
    uint16_t gpio_pin_b;

    /* Gpio pin C */
    void *gpio_port_c;
    uint16_t gpio_pin_c;

    /* Gpio pin En */
    void *gpio_port_en;
    uint16_t gpio_pin_en;

} dg405_dev;

/*!
 *  @brief This API enables the output of the device
 * 
 *  @param[in] dev : Structure instance of dg405_dev
 */
dg405_status_t dg405_enable(const dg405_dev *dev);

/*!
 *  @brief This API disables the output of the device
 * 
 *  @param[in] dev : Structure instance of dg405_dev
 */
dg405_status_t dg405_disable(const dg405_dev *dev);

/*!
 *  @brief This API routes the mux of the device to output specified pin.
 * 
 *  @param[in] dev    : Structure instance of dg405_dev
 *  @param[in] output : Output pin to mux
 */
dg405_status_t dg405_switch_output(const dg405_dev *dev, uint8_t output);

/*!
 *  @brief This API gets the current mux'ed pin
 * 
 *  @param[in] dev : Structure instance of dg405_dev
 *  @param[out] output : Pointer to variable to store output
 */
dg405_status_t dg405_get_output(const dg405_dev *dev, uint8_t* output);


#ifdef __cplusplus
}
#endif /* End of CPP guard */
#endif /* DG405_H_ */
/** @}*/