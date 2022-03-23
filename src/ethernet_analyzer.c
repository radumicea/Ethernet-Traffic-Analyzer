/*****************************************************************************
 * ethernet_analyzer.c
 *****************************************************************************/

#include "ethernet_analyzer.h"

/*
 MOSI - PF11 - P9_5
 MISO - PF12 - P9_6
 SCK  - PF13 - P9_8
 SS   - PF14
 */
void initPins(void)
{
	*pPORTF_FER = 0x0003 | PF11 | PF12 | PF13;
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

	initSpi();

	while (true)
	{
		selectSlave();
		spiWriteByte('a');
		deselectSlave();
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
