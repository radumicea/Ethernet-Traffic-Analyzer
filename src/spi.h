/*****************************************************************************
 * spi.h
 *****************************************************************************/

#ifndef __SPI_H__
#define __SPI_H__

#include "shared.h"

void initSpiMaster(void);
void initSpiSlave(void);
void spiWriteByte(byte_t b);
byte_t spiReadByte(void);
void selectSlave(void);
void deselectSlave(void);

#endif  /* __SPI_H__ */
