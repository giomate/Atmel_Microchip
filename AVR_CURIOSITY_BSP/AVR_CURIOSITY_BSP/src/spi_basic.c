/**
 * \file
 *
 * \brief SPI basic driver.
 *
 (c) 2020 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/**
 * \defgroup doc_driver_spi_basic SPI Basic
 * \ingroup doc_driver_spi
 *
 * \section doc_driver_spi_basic_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <spi_basic.h>
#include <atmel_start_pins.h>

typedef struct SPI_ADF_descriptor_s {
	spi_transfer_status_t status;
} SPI_ADF_descriptor_t;

static SPI_ADF_descriptor_t SPI_ADF_desc;

/**
 * \brief Initialize SPI interface
 * If module is configured to disabled state, the clock to the SPI is disabled
 * if this is supported by the device's clock system.
 *
 * \return Initialization status.
 * \retval 0 the SPI init was successful
 * \retval 1 the SPI init was not successful
 */
void SPI_ADF_init()
{

	SPI0.CTRLA = 0 << SPI_CLK2X_bp    /* Enable Double Speed: disabled */
	             | 0 << SPI_DORD_bp   /* Data Order Setting: disabled */
	             | 1 << SPI_ENABLE_bp /* Enable Module: enabled */
	             | 1 << SPI_MASTER_bp /* SPI module in master mode */
	             | SPI_PRESC_DIV4_gc; /* System Clock / 4 */

	// SPI0.CTRLB = 0 << SPI_BUFEN_bp /* Buffer Mode Enable: disabled */
	//		 | 0 << SPI_BUFWR_bp /* Buffer Write Mode: disabled */
	//		 | SPI_MODE_0_gc /* SPI Mode 0 */
	//		 | 0 << SPI_SSD_bp; /* Slave Select Disable: disabled */

	SPI0.INTCTRL = 0 << SPI_DREIE_bp    /* Data Register Empty Interrupt Enable: disabled */
	               | 1 << SPI_IE_bp     /* Interrupt Enable: enabled */
	               | 0 << SPI_RXCIE_bp  /* Receive Complete Interrupt Enable: disabled */
	               | 0 << SPI_SSIE_bp   /* Slave Select Trigger Interrupt Enable: disabled */
	               | 0 << SPI_TXCIE_bp; /* Transfer Complete Interrupt Enable: disabled */

	SPI_ADF_desc.status = SPI_FREE;
}

/**
 * \brief Enable SPI_ADF
 * 1. If supported by the clock system, enables the clock to the SPI
 * 2. Enables the SPI module by setting the enable-bit in the SPI control register
 *
 * \return Nothing
 */
void SPI_ADF_enable()
{
	SPI0.CTRLA |= SPI_ENABLE_bm;
}

/**
 * \brief Disable SPI_ADF
 * 1. Disables the SPI module by clearing the enable-bit in the SPI control register
 * 2. If supported by the clock system, disables the clock to the SPI
 *
 * \return Nothing
 */
void SPI_ADF_disable()
{
	SPI0.CTRLA &= ~SPI_ENABLE_bm;
}

/**
 * \brief Exchange one byte over SPI SPI_ADF. Blocks until done.
 *
 * \param[in] data The byte to transfer
 *
 * \return Received data byte.
 */
uint8_t SPI_ADF_exchange_byte(uint8_t data)
{
	// Blocking wait for SPI free makes the function work
	// seamlessly also with IRQ drivers.
	while (SPI_ADF_desc.status == SPI_BUSY)
		;
	SPI0.DATA = data;
	while (!(SPI0.INTFLAGS & SPI_RXCIF_bm))
		;
	return SPI0.DATA;
}

/**
 * \brief Exchange a buffer over SPI SPI_ADF. Blocks if using polled driver.
 *
 * \param[inout] block The buffer to transfer. Received data is returned here.
 * \param[in] size The size of buffer to transfer
 *
 * \return Nothing.
 */
void SPI_ADF_exchange_block(void *block, uint8_t size)
{
	uint8_t *b = (uint8_t *)block;
	while (size--) {
		SPI0.DATA = *b;
		while (!(SPI0.INTFLAGS & SPI_RXCIF_bm))
			;
		*b = SPI0.DATA;
		b++;
	}
}

/**
 * \brief Write a buffer over SPI SPI_ADF. Blocks if using polled driver.
 *
 * \param[in] block The buffer to transfer
 * \param[in] size The size of buffer to transfer
 *
 * \return Nothing.
 */
void SPI_ADF_write_block(void *block, uint8_t size)
{
	uint8_t *b = (uint8_t *)block;
	while (size--) {
		SPI0.DATA = *b;
		while (!(SPI0.INTFLAGS & SPI_RXCIF_bm))
			;
		b++;
	}
}

/**
 * \brief Read a buffer over SPI SPI_ADF. Blocks if using polled driver.
 *
 * Zeros are transmitted out of the SPI.
 *
 * \param[out] block Received data is written here.
 * \param[in] size The size of buffer to transfer
 *
 * \return Nothing.
 */
void SPI_ADF_read_block(void *block, uint8_t size)
{
	uint8_t *b = (uint8_t *)block;
	while (size--) {
		SPI0.DATA = 0;
		while (!(SPI0.INTFLAGS & SPI_RXCIF_bm))
			;
		*b = SPI0.DATA;
		b++;
	}
}

typedef struct SPI_LMX_descriptor_s {
	spi_transfer_status_t  status;
	uint8_t *              data;
	uint8_t                size;
	spi_transfer_type_t    type;
	spi_transfer_done_cb_t cb;
} SPI_LMX_descriptor_t;

static SPI_LMX_descriptor_t SPI_LMX_desc;

/**
 * \brief Initialize SPI interface
 * If module is configured to disabled state, the clock to the SPI is disabled
 * if this is supported by the device's clock system.
 *
 * \return Initialization status.
 * \retval 0 the SPI init was successful
 * \retval 1 the SPI init was not successful
 */
void SPI_LMX_init()
{

	SPI1.CTRLA = 0 << SPI_CLK2X_bp    /* Enable Double Speed: disabled */
	             | 0 << SPI_DORD_bp   /* Data Order Setting: disabled */
	             | 1 << SPI_ENABLE_bp /* Enable Module: enabled */
	             | 1 << SPI_MASTER_bp /* SPI module in master mode */
	             | SPI_PRESC_DIV4_gc; /* System Clock / 4 */

	// SPI1.CTRLB = 0 << SPI_BUFEN_bp /* Buffer Mode Enable: disabled */
	//		 | 0 << SPI_BUFWR_bp /* Buffer Write Mode: disabled */
	//		 | SPI_MODE_0_gc /* SPI Mode 0 */
	//		 | 0 << SPI_SSD_bp; /* Slave Select Disable: disabled */

	SPI1.INTCTRL = 0 << SPI_DREIE_bp    /* Data Register Empty Interrupt Enable: disabled */
	               | 1 << SPI_IE_bp     /* Interrupt Enable: enabled */
	               | 0 << SPI_RXCIE_bp  /* Receive Complete Interrupt Enable: disabled */
	               | 0 << SPI_SSIE_bp   /* Slave Select Trigger Interrupt Enable: disabled */
	               | 0 << SPI_TXCIE_bp; /* Transfer Complete Interrupt Enable: disabled */

	SPI_LMX_desc.status = SPI_FREE;
	SPI_LMX_desc.cb     = NULL;
}

/**
 * \brief Enable SPI_LMX
 * 1. If supported by the clock system, enables the clock to the SPI
 * 2. Enables the SPI module by setting the enable-bit in the SPI control register
 *
 * \return Nothing
 */
void SPI_LMX_enable()
{
	SPI1.CTRLA |= SPI_ENABLE_bm;
}

/**
 * \brief Disable SPI_LMX
 * 1. Disables the SPI module by clearing the enable-bit in the SPI control register
 * 2. If supported by the clock system, disables the clock to the SPI
 *
 * \return Nothing
 */
void SPI_LMX_disable()
{
	SPI1.CTRLA &= ~SPI_ENABLE_bm;
}

/*
  Callback function is typically used to:
  In master mode: Release SS after transfer as finished.
  In slave mode: Implement SPI protocol, setting up next transfer
                 after the previous one (i.e. data transfer phase
                 after control/command phase).
*/
void SPI_LMX_register_callback(spi_transfer_done_cb_t f)
{
	SPI_LMX_desc.cb = f;
}

ISR(SPI1_INT_vect)
{
	/* SPI_LMX_desc.data points to array element
	   to write the received data to. The data to be transmitted
	   is in the next array element.
	*/
	uint8_t rdata = SPI1.DATA;
	uint8_t wdata = 0;

	SPI1.INTFLAGS = SPI_RXCIF_bm;

	if (SPI_LMX_desc.type != SPI_WRITE) {
		*SPI_LMX_desc.data = rdata;
	}

	SPI_LMX_desc.data++;

	if (SPI_LMX_desc.type != SPI_READ)
		wdata = *SPI_LMX_desc.data;

	SPI_LMX_desc.size--;
	// if more bytes to be transferred
	if (SPI_LMX_desc.size != 0) {
		// more data to send, send a byte
		SPI1.DATA = wdata;
	}

	// if last byte has been transferred, update status
	// and optionally call callback
	else {
		SPI_LMX_desc.status = SPI_DONE;
		if (SPI_LMX_desc.cb != NULL) {
			SPI_LMX_desc.cb();
		}
	}
}

/**
 * \brief Check if SPI bus is FREE.
 *
 * \return SPI free status
 * \retval true  SPI bus is FREE
 * \retval false SPI bus is not FREE
 */
bool SPI_LMX_status_free()
{
	return (SPI_LMX_desc.status == SPI_FREE);
}

/**
 * \brief Check if SPI bus is IDLE.
 *
 * \return SPI IDLE status
 * \retval true  SPI bus is IDLE
 * \retval false SPI bus is not IDLE
 */
bool SPI_LMX_status_idle()
{
	return (SPI_LMX_desc.status == SPI_IDLE);
}

/**
 * \brief Check if SPI bus is BUSY.
 *
 * \return SPI BUSY status
 * \retval true  SPI bus is BUSY
 * \retval false SPI bus is not BUSY
 */
bool SPI_LMX_status_busy()
{
	return (SPI_LMX_desc.status == SPI_BUSY);
}

/**
 * \brief Check if SPI bus is DONE.
 *
 * \return SPI DONE status
 * \retval true  SPI bus is DONE
 * \retval false SPI bus is not DONE
 */
bool SPI_LMX_status_done()
{
	return (SPI_LMX_desc.status == SPI_DONE);
}

uint8_t SPI_LMX_exchange_byte(uint8_t data)
{
	SPI_LMX_desc.data   = (uint8_t *)&data;
	SPI_LMX_desc.size   = 1;
	SPI_LMX_desc.type   = SPI_READ;
	SPI_LMX_desc.status = SPI_BUSY;

	SPI1.DATA = *SPI_LMX_desc.data;
	while (SPI_LMX_desc.status == SPI_BUSY)
		;
	return data;
}

void SPI_LMX_exchange_block(void *block, uint8_t size)
{
	SPI_LMX_desc.data   = (uint8_t *)block;
	SPI_LMX_desc.size   = size;
	SPI_LMX_desc.type   = SPI_EXCHANGE;
	SPI_LMX_desc.status = SPI_BUSY;

	SPI1.DATA = *SPI_LMX_desc.data;
}

void SPI_LMX_write_block(void *block, uint8_t size)
{
	SPI_LMX_desc.data   = (uint8_t *)block;
	SPI_LMX_desc.size   = size;
	SPI_LMX_desc.type   = SPI_WRITE;
	SPI_LMX_desc.status = SPI_BUSY;

	SPI1.DATA = *SPI_LMX_desc.data;
}

void SPI_LMX_read_block(void *block, uint8_t size)
{
	SPI_LMX_desc.data   = (uint8_t *)block;
	SPI_LMX_desc.size   = size;
	SPI_LMX_desc.type   = SPI_READ;
	SPI_LMX_desc.status = SPI_BUSY;

	SPI1.DATA = 0;
}
