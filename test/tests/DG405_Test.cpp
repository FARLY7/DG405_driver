#include "CppUTest/TestHarness.h"

#include "dg405.h"
#include "GpioSpy.h"

dg405_dev_t dev = {0};
uint16_t port;

TEST_GROUP(DG405)
{
    /* Define data accessible to test group members here */

    void setup()
    {
        dev.gpio_write = gpio_write;
        dev.gpio_read = gpio_read;
        dev.port_a = &port;
        dev.port_b = &port;
        dev.port_c = &port;
        dev.port_en = &port;
        dev.pin_a   = 3;
        dev.pin_b   = 4;
        dev.pin_c  = 5;
        dev.pin_en = 6;
        port = 0;

        /* Initialisation steps are executed before each TEST */
    }   

    void teardown()
    {
        /* Clean up steps are executed after each TEST */
    } 
};


TEST(DG405, OnDisableEnPinIsDisabled)
{
    dg405_disable(&dev);
    LONGS_EQUAL(port, 1 << dev.pin_en);
}

TEST(DG405, OnEnableEnPinIsEnabled)
{
    dg405_enable(&dev);
    LONGS_EQUAL(port, 0 << dev.pin_en);
}

TEST(DG405, EnableMuxOutputA)
{
    dg405_enable(&dev);
    dg405_switch_output(&dev, 3);
    LONGS_EQUAL(port, 0x18);
}
