#include "stm32f10x.h"

#define PIN_KEY GPIO_Pin_11

void KEY_init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = PIN_KEY;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

}

/**
  * @brief get the status of the key
  * @retval return 1: key is pressed
  */
uint8_t KEY_get_status(void){
    if(GPIO_ReadInputDataBit(GPIOB, PIN_KEY) == 0){
        return 1;
    }else{
        return 0;
    }
}
