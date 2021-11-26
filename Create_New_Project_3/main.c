/*
 * main.c
 *
 *  Created on: 25-Nov-2021
 *      Author: Devilal
 */


#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include "F28x_Project.h"
#include "F2837xD_device.h"
#include "F2837xD_Examples.h"

#include "device.h"
#include "driverlib.h"

void gpio_init();
void main(void)
{
    Device_init();
    Device_initGPIO();
    gpio_init();

    while(1)
    {

        GpioDataRegs.GPACLEAR.bit.GPIO31=1;
        DEVICE_DELAY_US(1000000);
        GpioDataRegs.GPASET.bit.GPIO31=1;
        DEVICE_DELAY_US(1000000);;


//        GPIO_writePin(DEVICE_GPIO_PIN_LED1, 1); // led1 mean gpio 31
//        GPIO_writePin(DEVICE_GPIO_PIN_LED2, 1); // led1 mean gpio 31
//        DEVICE_DELAY_US(1000000);
//
//        GPIO_writePin(DEVICE_GPIO_PIN_LED1, 0);
//        GPIO_writePin(DEVICE_GPIO_PIN_LED2, 0);
//        DEVICE_DELAY_US(1000000);
    }
}

void gpio_init()
{
    // config led 1
    GPIO_setPinConfig(DEVICE_GPIO_PIN_LED1);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED1, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED1, GPIO_PIN_TYPE_STD);
    GPIO_setMasterCore(DEVICE_GPIO_PIN_LED1, GPIO_CORE_CPU1);

    // config led 2

    GPIO_setPinConfig(DEVICE_GPIO_PIN_LED2);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED2, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED2, GPIO_PIN_TYPE_STD);
   GPIO_setMasterCore(DEVICE_GPIO_PIN_LED2, GPIO_CORE_CPU1);
}
