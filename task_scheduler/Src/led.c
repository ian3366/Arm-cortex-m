
#include<stdint.h>
#include"led.h"

void delay(uint32_t count){
	for(uint32_t i =0;i<count ;i++);
}
void led_init_all(void){
	uint32_t *pRccAhb1enr = (uint32_t*)0x40023830;
	uint32_t *pGpidModeReg=(uint32_t*)0x400020C00;

	*pRccAhb1enr |= (1<<3);

}
