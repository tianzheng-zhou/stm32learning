#include "stm32f10x.h"
#include "Delay.h"

//#include "BEEP.h"
//#include "LED.h"
#include "LED_ON_BOARD.h"

#include "Light_Sensor.h"

#include "OLED.h"

int main(void){


   //KEY_init();
   //LED_init();
   //BEEP_init();
   LED_ON_BOARD_init();
   
   Light_Sensor_init();
   Light_Sensor_counter_init();

   LED_ON_BOARD_on();
   OLED_Init(0);
   OLED_Clear();

   while(1){
      
      
      OLED_ShowString(1,1,"Hello World");
      OLED_ShowNum(2,1,Light_Sensor_get_count(),5);
      
      
      


   }
}

