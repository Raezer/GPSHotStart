#include "stm32f4xx.h"
#include "stdio.h"
#include "defines.h"
#include "tm_stm32f4_usart.h"

uint8_t cmdToSend[] ={0xB5,0x62,0x0B,0x01,0x00,0x00};
uint8_t cHistory[100],c;
uint8_t cHandled[100][100];
bool msgStarted;
int i=0,cHandledN=0,cHandledCharN=0,msgEndSq,cSentN=0;
void ubloxMsgSend(){
	while (cSentN<=6)
	{
	TM_USART_Putc(USART1,cmdToSend[cSentN]);
		cSentN++;
	}
	cSentN=0;
}
void ubloxMsgGet(uint8_t buf) {
    	if (buf) {
			/* If anything received, put it back to terminal */
			cHistory[i]= buf;
			i++;
			if (buf=='$')
			{
				msgStarted=true;
			}
			if (msgStarted)
			{
			  cHandled[cHandledN][cHandledCharN]=buf;
				cHandledCharN++;
				if (buf==0x0D)
				{
					msgEndSq++;
				}
				if (buf==0x0A&&msgEndSq==1)
				{
					msgStarted=false;
					cHandledN++;
					msgEndSq=0;
					cHandledCharN=0;
				}
			}
			if (i==99)
			{
				i=0;
				ubloxMsgSend();
			}
			if (cHandledN==99)
			{
				cHandledN=0;
				ubloxMsgSend();
			}
			
		}
}



int main(void){
	SystemInit();
	TM_USART_Init(USART1, TM_USART_PinsPack_1, 9600);
	while(1) 
	{
		ubloxMsgGet(TM_USART_Getc(USART1));

	}
}

