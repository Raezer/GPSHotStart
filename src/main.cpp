#include "stm32f4xx.h"
#include "mbed.h"
#include "ubloxOp.h"
#include "main.h"


Serial pc(PA_9,PA_10);

int main(void){
	SystemInit();
	
	while(1) 
	{
		 
	}
}


// tx, rx
//Serial pc(PA_9, PA_10); 

int getinfo() {
	
    pc.printf("Hello World!\n");
    while(1) {
        pc.putc(pc.getc() + 1);
    }
}