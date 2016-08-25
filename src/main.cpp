#include "stm32f4xx.h"
#include "mbed.h"

Serial pc(PA_9,PA_10);


int getinfo() {
	
    pc.printf("Hello World!\n");
    while(1) {
        pc.putc(pc.getc() + 1);
    }
}

void init(){
	pc.baud(9600);
	device.format(8,no,1);
  device.reply(0x00); 
}

int main(void){
	SystemInit();
	getinfo();
	while(1) 
	{
		 
	}
}


// tx, rx
//Serial pc(PA_9, PA_10); 

