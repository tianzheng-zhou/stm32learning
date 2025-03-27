#ifndef __Light_Sensor_h
#define __Light_Sensor_h

void Light_Sensor_init(void);
unsigned char Light_Sensor_get_status(void);
uint32_t Light_Sensor_get_count(void);
void Light_Sensor_counter_init(void);

#endif
