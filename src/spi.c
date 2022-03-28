#include "spi.h"

void initSpiMaster(void)
{
	initSpi();
	*pSPI_CTL |= MSTR;
	deselectSlave();
}

void initSpiSlave(void)
{
	initSpi();
	*pSPI_CTL |= !MSTR;
}

void initSpi(void)
{
	*pSPI_CTL = (SPE | !SIZE | EMISO | 0x01);
	*pSPI_BAUD = 0x19;
	// 25
}

void selectSlave(void)
{
	*pPORTFIO &= ~PF10;
}

void deselectSlave(void)
{
	*pPORTFIO |= PF10;
}

byte_t spiTransferByte(byte_t b)
{
	byte_t r;
	*pSPI_TDBR = b;
	while ((*pSPI_STAT & TXS) != 0);
	while ((*pSPI_STAT & SPIF) == 0);
	r = *pSPI_RDBR;
	return r;
}
