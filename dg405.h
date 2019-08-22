/*
 * MIT License
 * 
 * Copyright (c) 2019 Sean Farrelly
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
typedef void (*dg405_gpio_fptr_t)(void* port, uint16_t pin, uint8_t *val);

/*!
 * @brief dg405 device structure
 */
typedef struct {

    /* Gpio write function pointer */
    dg405_gpio_fptr_t gpio_write;

    /* Gpio read function pointer */
    dg405_gpio_fptr_t gpio_read;

    /* Gpio pin A  */
    void *port_a;
    uint16_t pin_a;

    /* Gpio pin B */
    void *port_b;
    uint16_t pin_b;

    /* Gpio pin C */
    void *port_c;
    uint16_t pin_c;

    /* Gpio pin En */
    void *port_en;
    uint16_t pin_en;

} dg405_dev_t;

/*!
 *  @brief This API enables the output of the device
 * 
 *  @param[in] dev : Structure instance of dg405_dev_t
 */
dg405_status_t dg405_enable(const dg405_dev_t *dev);

/*!
 *  @brief This API disables the output of the device
 * 
 *  @param[in] dev : Structure instance of dg405_dev_t
 */
dg405_status_t dg405_disable(const dg405_dev_t *dev);

/*!
 *  @brief This API routes the mux of the device to output specified pin.
 * 
 *  @param[in] dev    : Structure instance of dg405_dev_t
 *  @param[in] output : Output pin to mux
 */
dg405_status_t dg405_switch_output(const dg405_dev_t *dev, uint8_t output);

/*!
 *  @brief This API gets the current mux'ed pin
 * 
 *  @param[in] dev : Structure instance of dg405_dev_t
 *  @param[out] output : Pointer to variable to store output
 */
dg405_status_t dg405_get_output(const dg405_dev_t *dev, uint8_t* output);


#ifdef __cplusplus
}
#endif /* End of CPP guard */
#endif /* DG405_H_ */
/** @}*/