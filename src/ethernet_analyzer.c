/*****************************************************************************
 * ethernet_analyzer.c
 *****************************************************************************/

#include "ethernet_analyzer.h"

/*
 GPIO - PF10
 MOSI - PF11 - P9_5
 MISO - PF12 - P9_6
 SCK  - PF13 - P9_8
 SS   - PF14
 */
void initPins(void)
{
#ifdef SPI_SLAVE
	*pPORTF_FER = PF11 | PF12 | PF13 | PF14;
#else
	*pPORTF_FER = PF11 | PF12 | PF13;
#endif
	*pPORTFIO_DIR |= PF10;
	*pPORT_MUX = 0x0000;
}

int main(void)
{
	initPins();
	//initUart();

	/*
	while (true)
	{
		byte_t ch = readByte();
		uartWriteByte(++ch);
	}
	 */
#ifdef SPI_SLAVE
	initSpiSlave();
#else
	initSpiMaster();
#endif
	while (true)
	{
		selectSlave();
		spiTransferByte('a');
		deselectSlave();
		sleep(1000);
	}


	while (true)
	{
		uartWriteByte('a');
	    /*
		if (uartReadByte() == 'a')
		{
			uartWriteByte('x');
		}
		 */
		sleep(1000000);
	}

	return 0;
}
