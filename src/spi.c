#include "shared.h"


void initSpiMaster(void)
{
	initSpi();
	*pSPI_CTL |= (MSTR | !EMISO);
}

void initSpiSlave(void)
{
	initSpi();
	*pSPI_CTL |= (!MSTR | !EMISO);
}

static void initSpi(void)
{
	*pSPI_CTL = (SPE | !SIZE | 0x01);
	*pSPI_BAUD = 0x19;
	// 25
}

void selectSlave(void)
{
	// gpio low
}

void deselectSlave(void)
{
	// gpio high
}

void makeSlave(void)
{
	*pSPI_CTL |= (!MSTR | EMISO);
}


void spiWriteByte(byte_t b)
{
	while ((*pSPI_STAT & TXS) != 0);
	*pSPI_TDBR = b;
}

byte_t spiReadByte(void)
{
	// to be implemented
	return 0;
}
