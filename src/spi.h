/*****************************************************************************
 * spi.h
 *****************************************************************************/

#ifndef __SPI_H__
#define __SPI_H__

#include "shared.h"

void initSpiMaster(void);
void initSpiSlave(void);
byte_t spiTransferByte(byte_t b);
void selectSlave(void);
void deselectSlave(void);

#endif  /* __SPI_H__ */
