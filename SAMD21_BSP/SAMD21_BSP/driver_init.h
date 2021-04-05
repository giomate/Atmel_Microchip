/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_INCLUDED
#define DRIVER_INIT_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>

#include <hal_spi_m_sync.h>
#include <hal_spi_m_sync.h>
#include <hal_spi_m_sync.h>

#include <hal_usart_sync.h>

#include <hal_delay.h>

#include <hal_dac_sync.h>

#include "hal_usb_device.h"

extern struct spi_m_sync_descriptor SPI_ADF;
extern struct spi_m_sync_descriptor SPI_LMX;
extern struct spi_m_sync_descriptor SPI_ZCD;

extern struct usart_sync_descriptor TARGET_IO;

extern struct dac_sync_descriptor DAC_0;

void SPI_ADF_PORT_init(void);
void SPI_ADF_CLOCK_init(void);
void SPI_ADF_init(void);

void SPI_LMX_PORT_init(void);
void SPI_LMX_CLOCK_init(void);
void SPI_LMX_init(void);

void SPI_ZCD_PORT_init(void);
void SPI_ZCD_CLOCK_init(void);
void SPI_ZCD_init(void);

void TARGET_IO_PORT_init(void);
void TARGET_IO_CLOCK_init(void);
void TARGET_IO_init(void);

void delay_driver_init(void);

void DAC_0_PORT_init(void);
void DAC_0_CLOCK_init(void);
void DAC_0_init(void);

void USB_DEVICE_INSTANCE_CLOCK_init(void);
void USB_DEVICE_INSTANCE_init(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_INCLUDED
