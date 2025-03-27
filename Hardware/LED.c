#include "stm32f10x.h"

#define PIN_LED GPIO_Pin_0

void LED_init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = PIN_LED;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(GPIOA, &GPIO_InitStructure);

}
void LED_on(void){
    GPIO_WriteBit(GPIOA, PIN_LED, Bit_SET);
    //GPIO_SetBits(GPIOA, PIN_LED);
}

void LED_off(void){
    GPIO_WriteBit(GPIOA, PIN_LED, Bit_RESET);
    //GPIO_ResetBits(GPIOA, PIN_LED);
}

/**
  * @brief  切换LED状态
  * 
  * @note   通过读取当前输出状态并取反实现状态翻转
  *         适用于所有推挽输出模式的GPIO
  */
void LED_toggle(void){
    GPIO_WriteBit(GPIOA, PIN_LED, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOA, PIN_LED)));
}
