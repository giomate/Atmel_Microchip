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

static void button_on_PA14_pressed(void)
{
}

/**
 * Example of using EXTERNAL_IRQ_0
 */
void EXTERNAL_IRQ_0_example(void)
{

	ext_irq_register(PIN_PA14, button_on_PA14_pressed);
}

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
 * Example of using USART_0 to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_USART_0[12] = "Hello World!";

static void tx_cb_USART_0(const struct usart_async_descriptor *const io_descr)
{
	/* Transfer completed */
}

void USART_0_example(void)
{
	struct io_descriptor *io;

	usart_async_register_callback(&USART_0, USART_ASYNC_TXC_CB, tx_cb_USART_0);
	/*usart_async_register_callback(&USART_0, USART_ASYNC_RXC_CB, rx_cb);
	usart_async_register_callback(&USART_0, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&USART_0, &io);
	usart_async_enable(&USART_0);

	io_write(io, example_USART_0, 12);
}

void delay_example(void)
{
	delay_ms(5000);
}

static struct timer_task TIMER_ZCD_task1, TIMER_ZCD_task2;

/**
 * Example of using TIMER_ZCD.
 */
static void TIMER_ZCD_task1_cb(const struct timer_task *const timer_task)
{
}

static void TIMER_ZCD_task2_cb(const struct timer_task *const timer_task)
{
}

void TIMER_ZCD_example(void)
{
	TIMER_ZCD_task1.interval = 100;
	TIMER_ZCD_task1.cb       = TIMER_ZCD_task1_cb;
	TIMER_ZCD_task1.mode     = TIMER_TASK_REPEAT;
	TIMER_ZCD_task2.interval = 200;
	TIMER_ZCD_task2.cb       = TIMER_ZCD_task2_cb;
	TIMER_ZCD_task2.mode     = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_ZCD, &TIMER_ZCD_task1);
	timer_add_task(&TIMER_ZCD, &TIMER_ZCD_task2);
	timer_start(&TIMER_ZCD);
}

static struct timer_task TIMER_USB_task1, TIMER_USB_task2;

/**
 * Example of using TIMER_USB.
 */
static void TIMER_USB_task1_cb(const struct timer_task *const timer_task)
{
}

static void TIMER_USB_task2_cb(const struct timer_task *const timer_task)
{
}

void TIMER_USB_example(void)
{
	TIMER_USB_task1.interval = 100;
	TIMER_USB_task1.cb       = TIMER_USB_task1_cb;
	TIMER_USB_task1.mode     = TIMER_TASK_REPEAT;
	TIMER_USB_task2.interval = 200;
	TIMER_USB_task2.cb       = TIMER_USB_task2_cb;
	TIMER_USB_task2.mode     = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_USB, &TIMER_USB_task1);
	timer_add_task(&TIMER_USB, &TIMER_USB_task2);
	timer_start(&TIMER_USB);
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
