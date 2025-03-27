#include "stm32f10x.h"

#define PIN_BEEP GPIO_Pin_12

/**
  * @brief 切换蜂鸣器状态
  */
void BEEP_toggle(void){
    // 读取当前GPIO输出状态（0或1）
    // 数学取反：1 - 当前值（0→1，1→0）
    // 转换为BitAction枚举类型后写入寄存器
    GPIO_WriteBit(GPIOB, PIN_BEEP, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOB, PIN_BEEP))); 
}

void BEEP_off(void){
    GPIO_SetBits(GPIOB, PIN_BEEP);
}
void BEEP_on(void){
    GPIO_ResetBits(GPIOB, PIN_BEEP);
}

void BEEP_init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = PIN_BEEP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

}
