/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/**
 * Example of using SPI_ADF to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_ADF[12] = "Hello World!";

void SPI_ADF_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_ADF, &io);

	spi_m_sync_enable(&SPI_ADF);
	io_write(io, example_SPI_ADF, 12);
}

/**
 * Example of using SPI_LMX to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_LMX[12] = "Hello World!";

void SPI_LMX_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_LMX, &io);

	spi_m_sync_enable(&SPI_LMX);
	io_write(io, example_SPI_LMX, 12);
}

/**
 * Example of using SPI_ZCD to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_ZCD[12] = "Hello World!";

void SPI_ZCD_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_ZCD, &io);

	spi_m_sync_enable(&SPI_ZCD);
	io_write(io, example_SPI_ZCD, 12);
}

/**
 * Example of using TARGET_IO to write "Hello World" using the IO abstraction.
 */
void TARGET_IO_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&TARGET_IO, &io);
	usart_sync_enable(&TARGET_IO);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

void delay_example(void)
{
	delay_ms(5000);
}

/**
 * Example of using DAC_0 to generate waveform.
 */
void DAC_0_example(void)
{
	uint16_t i = 0;

	dac_sync_enable_channel(&DAC_0, 0);

	for (;;) {
		dac_sync_write(&DAC_0, 0, &i, 1);
		i = (i + 1) % 1024;
	}
}
