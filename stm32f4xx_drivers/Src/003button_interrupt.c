
#include"stm32f446.h"
#include"stm32f446_GPIO_driver.h"
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

void delay(void)
{
	for(uint32_t i = 0 ; i < 50000 ; i ++);
}

int main()
{
	GPIO_Handle_t GpioLed,Gpiobtn;
	memset(&GpioLed,0,sizeof(GpioLed));
	memset(&Gpiobtn,0,sizeof(Gpiobtn));

	GpioLed.pGPIOx = GPIOB;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&GpioLed);

	Gpiobtn.pGPIOx = GPIOC;
	Gpiobtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	Gpiobtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	Gpiobtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpiobtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&Gpiobtn);

	//IRQ configuration

	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);
	while(1)
	{
		GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_0, HIGH);
	}
	return 0;
}
void EXTI15_10_IRQHandler(void)
{
	GPIO_IRQHandling(GPIO_PIN_NO_13);
	GPIO_WriteToOutputPin(GPIOB, GPIO_PIN_NO_0, LOW);
	delay();
}


