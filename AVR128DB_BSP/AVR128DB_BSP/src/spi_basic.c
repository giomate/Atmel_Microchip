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

typedef struct SPI_REFERENCE_descriptor_s {
	spi_transfer_status_t status;
} SPI_REFERENCE_descriptor_t;

static SPI_REFERENCE_descriptor_t SPI_REFERENCE_desc;

/**
 * \brief Initialize SPI interface
 * If module is configured to disabled state, the clock to the SPI is disabled
 * if this is supported by the device's clock system.
 *
 * \return Initialization status.
 * \retval 0 the SPI init was successful
 * \retval 1 the SPI init was not successful
 */
void SPI_REFERENCE_init()
{

	SPI0.CTRLA = 0 << SPI_CLK2X_bp    /* Enable Double Speed: disabled */
	             | 0 << SPI_DORD_bp   /* Data Order Setting: disabled */
	             | 1 << SPI_ENABLE_bp /* Enable Module: enabled */
	             | 0 << SPI_MASTER_bp /* SPI module in slave mode */
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

	SPI_REFERENCE_desc.status = SPI_FREE;
}

/**
 * \brief Enable SPI_REFERENCE
 * 1. If supported by the clock system, enables the clock to the SPI
 * 2. Enables the SPI module by setting the enable-bit in the SPI control register
 *
 * \return Nothing
 */
void SPI_REFERENCE_enable()
{
	SPI0.CTRLA |= SPI_ENABLE_bm;
}

/**
 * \brief Disable SPI_REFERENCE
 * 1. Disables the SPI module by clearing the enable-bit in the SPI control register
 * 2. If supported by the clock system, disables the clock to the SPI
 *
 * \return Nothing
 */
void SPI_REFERENCE_disable()
{
	SPI0.CTRLA &= ~SPI_ENABLE_bm;
}

/**
 * \brief Check if SPI slave is selected, i.e. its SS has been asserted.
 *
 * \return SPI SS status
 * \retval true  SPI is selected
 * \retval false SPI is not selected
 */
bool SPI_REFERENCE_selected()
{
	return (!PA7_get_level());
}

/**
 * \brief Get received data byte from SPI
 *
 * \return Received data byte
 */
uint8_t SPI_REFERENCE_get_rx_data()
{
	return SPI0.DATA;
}

/**
 * \brief Write data byte to SPI
 *
 * \param[in] data The data to transfer
 *
 * \return Nothing
 */
void SPI_REFERENCE_write_tx_data(uint8_t data)
{
	SPI0.DATA = data;
}

/**
 * \brief Wait until SPI has recaived a data byte
 *
 * \return Nothing
 */
void SPI_REFERENCE_wait_dataready()
{
	while (!(SPI0.INTFLAGS & SPI_RXCIF_bm))
		;
}

/**
 * \brief Exchange one byte over SPI SPI_REFERENCE. Blocks until done.
 *
 * \param[in] data The byte to transfer
 *
 * \return Received data byte.
 */
uint8_t SPI_REFERENCE_exchange_byte(uint8_t data)
{
	// Blocking wait for SPI free makes the function work
	// seamlessly also with IRQ drivers.
	while (SPI_REFERENCE_desc.status == SPI_BUSY)
		;
	SPI0.DATA = data;
	while (!(SPI0.INTFLAGS & SPI_RXCIF_bm))
		;
	return SPI0.DATA;
}

void SPI_REFERENCE_exchange_block(void *block, uint8_t size)
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

void SPI_REFERENCE_write_block(void *block, uint8_t size)
{
	uint8_t *b = (uint8_t *)block;
	uint8_t  rdata;
	while (size--) {
		SPI0.DATA = *b;
		while (!(SPI0.INTFLAGS & SPI_RXCIF_bm))
			;
		rdata = SPI0.DATA;
		(void)(rdata); // Silence compiler warning
		b++;
	}
}

void SPI_REFERENCE_read_block(void *block, uint8_t size)
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

typedef struct SPI_ZCD_descriptor_s {
	spi_transfer_status_t  status;
	uint8_t *              data;
	uint8_t                size;
	spi_transfer_type_t    type;
	spi_transfer_done_cb_t cb;
} SPI_ZCD_descriptor_t;

static SPI_ZCD_descriptor_t SPI_ZCD_desc;

/**
 * \brief Initialize SPI interface
 * If module is configured to disabled state, the clock to the SPI is disabled
 * if this is supported by the device's clock system.
 *
 * \return Initialization status.
 * \retval 0 the SPI init was successful
 * \retval 1 the SPI init was not successful
 */
void SPI_ZCD_init()
{

	SPI1.CTRLA = 0 << SPI_CLK2X_bp    /* Enable Double Speed: disabled */
	             | 0 << SPI_DORD_bp   /* Data Order Setting: disabled */
	             | 1 << SPI_ENABLE_bp /* Enable Module: enabled */
	             | 0 << SPI_MASTER_bp /* SPI module in slave mode */
	             | SPI_PRESC_DIV4_gc; /* System Clock / 4 */

	// SPI1.CTRLB = 0 << SPI_BUFEN_bp /* Buffer Mode Enable: disabled */
	//		 | 0 << SPI_BUFWR_bp /* Buffer Write Mode: disabled */
	//		 | SPI_MODE_0_gc /* SPI Mode 0 */
	//		 | 0 << SPI_SSD_bp; /* Slave Select Disable: disabled */

	SPI1.INTCTRL = 1 << SPI_DREIE_bp    /* Data Register Empty Interrupt Enable: enabled */
	               | 1 << SPI_IE_bp     /* Interrupt Enable: enabled */
	               | 1 << SPI_RXCIE_bp  /* Receive Complete Interrupt Enable: enabled */
	               | 0 << SPI_SSIE_bp   /* Slave Select Trigger Interrupt Enable: disabled */
	               | 1 << SPI_TXCIE_bp; /* Transfer Complete Interrupt Enable: enabled */

	SPI_ZCD_desc.status = SPI_FREE;
	SPI_ZCD_desc.cb     = NULL;
}

/**
 * \brief Enable SPI_ZCD
 * 1. If supported by the clock system, enables the clock to the SPI
 * 2. Enables the SPI module by setting the enable-bit in the SPI control register
 *
 * \return Nothing
 */
void SPI_ZCD_enable()
{
	SPI1.CTRLA |= SPI_ENABLE_bm;
}

/**
 * \brief Disable SPI_ZCD
 * 1. Disables the SPI module by clearing the enable-bit in the SPI control register
 * 2. If supported by the clock system, disables the clock to the SPI
 *
 * \return Nothing
 */
void SPI_ZCD_disable()
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
void SPI_ZCD_register_callback(spi_transfer_done_cb_t f)
{
	SPI_ZCD_desc.cb = f;
}

// ISR(SPI1_INT_vect)
// {
// 	/* SPI_ZCD_desc.data points to array element
// 	   to write the received data to. The data to be transmitted
// 	   is in the next array element.
// 	*/
// 	uint8_t rdata = SPI1.DATA;
// 	uint8_t wdata = 0;
// 
// 	SPI1.INTFLAGS = SPI_RXCIF_bm;
// 
// 	if (SPI_ZCD_desc.type != SPI_WRITE) {
// 		*SPI_ZCD_desc.data = rdata;
// 	}
// 
// 	SPI_ZCD_desc.data++;
// 
// 	if (SPI_ZCD_desc.type != SPI_READ)
// 		wdata = *SPI_ZCD_desc.data;
// 
// 	SPI_ZCD_desc.size--;
// 	// if more bytes to be transferred
// 	if (SPI_ZCD_desc.size != 0) {
// 		// more data to send, send a byte
// 		SPI1.DATA = wdata;
// 	}
// 
// 	// if last byte has been transferred, update status
// 	// and optionally call callback
// 	else {
// 		SPI_ZCD_desc.status = SPI_DONE;
// 		if (SPI_ZCD_desc.cb != NULL) {
// 			SPI_ZCD_desc.cb();
// 		}
// 	}
// }

/**
 * \brief Check if SPI bus is FREE.
 *
 * \return SPI free status
 * \retval true  SPI bus is FREE
 * \retval false SPI bus is not FREE
 */
bool SPI_ZCD_status_free()
{
	return (SPI_ZCD_desc.status == SPI_FREE);
}

/**
 * \brief Check if SPI bus is IDLE.
 *
 * \return SPI IDLE status
 * \retval true  SPI bus is IDLE
 * \retval false SPI bus is not IDLE
 */
bool SPI_ZCD_status_idle()
{
	return (SPI_ZCD_desc.status == SPI_IDLE);
}

/**
 * \brief Check if SPI bus is BUSY.
 *
 * \return SPI BUSY status
 * \retval true  SPI bus is BUSY
 * \retval false SPI bus is not BUSY
 */
bool SPI_ZCD_status_busy()
{
	return (SPI_ZCD_desc.status == SPI_BUSY);
}

/**
 * \brief Check if SPI bus is DONE.
 *
 * \return SPI DONE status
 * \retval true  SPI bus is DONE
 * \retval false SPI bus is not DONE
 */
bool SPI_ZCD_status_done()
{
	return (SPI_ZCD_desc.status == SPI_DONE);
}

uint8_t SPI_ZCD_exchange_byte(uint8_t data)
{
	SPI_ZCD_desc.data   = (uint8_t *)&data;
	SPI_ZCD_desc.size   = 1;
	SPI_ZCD_desc.type   = SPI_READ;
	SPI_ZCD_desc.status = SPI_BUSY;

	SPI1.DATA = *SPI_ZCD_desc.data;
	while (SPI_ZCD_desc.status == SPI_BUSY)
		;
	return data;
}

void SPI_ZCD_exchange_block(void *block, uint8_t size)
{
	SPI_ZCD_desc.data   = (uint8_t *)block;
	SPI_ZCD_desc.size   = size;
	SPI_ZCD_desc.type   = SPI_EXCHANGE;
	SPI_ZCD_desc.status = SPI_BUSY;

	SPI1.DATA = *SPI_ZCD_desc.data;
}

void SPI_ZCD_write_block(void *block, uint8_t size)
{
	SPI_ZCD_desc.data   = (uint8_t *)block;
	SPI_ZCD_desc.size   = size;
	SPI_ZCD_desc.type   = SPI_WRITE;
	SPI_ZCD_desc.status = SPI_BUSY;

	SPI1.DATA = *SPI_ZCD_desc.data;
}

void SPI_ZCD_read_block(void *block, uint8_t size)
{
	SPI_ZCD_desc.data   = (uint8_t *)block;
	SPI_ZCD_desc.size   = size;
	SPI_ZCD_desc.type   = SPI_READ;
	SPI_ZCD_desc.status = SPI_BUSY;

	SPI1.DATA = 0;
}
