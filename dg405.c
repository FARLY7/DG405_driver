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
 * File        dg405.c
 * Created by  Sean Farrelly
 * Version     1.0
 * 
 */

/*! @file dg405.c
 * @brief Driver for DG405 multiplexer.
 */
#include "dg405.h"

#define LEN(arr) ((int)(sizeof(arr) / sizeof(arr)[0])) /* Return length of array. */

/*!
 * @brief This internal API is used to validate the device structure pointer for
 * null conditions.
 */
static dg405_status_t null_ptr_check(const dg405_dev *dev);

/*!
 * @brief Truth table defining possible mux combinations.
 */
static const uint8_t dg405_mux[8][3] = {
    {0, 0, 0},
    {0, 0, 1},
    {0, 1, 0},
    {0, 1, 1},
    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 1}
};

/*!
 * @brief This API enables the routing/output of the device.
 */
dg405_status_t dg405_enable(const dg405_dev *dev)
{   
    if(null_ptr_check(dev) != DG405_OK)
        return DG405_E_NULL_PTR;

    dev->gpio_write(dev->gpio_port_en, dev->gpio_pin_en, 0);

    return DG405_OK;
}

/*!
 * @brief This API disables the routing/output of the device.
 */
dg405_status_t dg405_disable(const dg405_dev *dev)
{
    if(null_ptr_check(dev) != DG405_OK)
        return DG405_E_NULL_PTR;

    dev->gpio_write(dev->gpio_port_en, dev->gpio_pin_en, 1);

    return DG405_OK;
}

/*!
 * @brief This API configures the mux of the device to output specified pin.
 */
dg405_status_t dg405_switch_output(const dg405_dev *dev, uint8_t output)
{
    if(null_ptr_check(dev) != DG405_OK)
        return DG405_E_NULL_PTR;

    dev->gpio_write(dev->gpio_port_a, dev->gpio_pin_a, dg405_mux[output][0]);
    dev->gpio_write(dev->gpio_port_b, dev->gpio_pin_b, dg405_mux[output][1]);
    dev->gpio_write(dev->gpio_port_c, dev->gpio_pin_c, dg405_mux[output][2]);

    return DG405_OK;
}

/*!
 * @brief This API get the currently configured output pin of the mux.
 */
dg405_status_t dg405_get_output(const dg405_dev *dev, uint8_t *output)
{
    if(null_ptr_check(dev) != DG405_OK)
        return DG405_E_NULL_PTR;

    uint8_t pin_a = dev->gpio_read(dev->gpio_port_a, dev->gpio_pin_a);
    uint8_t pin_b = dev->gpio_read(dev->gpio_port_b, dev->gpio_pin_b);
    uint8_t pin_c = dev->gpio_read(dev->gpio_port_c, dev->gpio_pin_c);

    for(size_t i = 0 ; i < LEN(dg405_mux) ; i++)
    {
        if(dg405_mux[i][0] == pin_a && dg405_mux[i][1] == pin_b && dg405_mux[i][2] == pin_c)
        {
            *output = i;
            break;
        }
    }

    return DG405_OK;
}

/*!
 * @brief This internal API is used to validate the device structure pointer for
 * null conditions.
 */
static dg405_status_t null_ptr_check(const dg405_dev *dev)
{
    dg405_status_t rslt;

    if ((dev == NULL) || (dev->gpio_write == NULL) || (dev->gpio_read == NULL))
    {
        /* Device structure pointer is not valid */
        rslt = DG405_E_NULL_PTR;
    }
    else
    {
        /* Device structure is fine */
        rslt = DG405_OK;
    }

    return rslt;
}