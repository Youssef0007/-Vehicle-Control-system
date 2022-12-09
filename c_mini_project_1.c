//main.c
#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#define ON 1
#define OFF 0


char engine_state=OFF;//engine off
int vehicle_speed=0;
char AC=OFF;
int AC_temp;
char engine_temperature_controller=OFF;
int engine_desired_temp;
int room_temp;
int engine_temp;
char quit=0;
char speed_control=OFF;

int main(void) {

	while(quit!=1 && engine_state==OFF)//ask if he want to turn on the engine while it's off
	{
		engine_on_off();
		if(quit!=1 && engine_state==ON)
		{
			sensor_set_menu();

			if(30==vehicle_speed)
			{
				AC=ON;
				AC_temp=(room_temp*5/4)+1;
				engine_temperature_controller=ON;
				engine_desired_temp=(engine_temp*5/4)+1;
			}
		}
	}
	if(quit!=1)
	{
			display_data();//display data when engine and system are ON
	}
	return 0;
}
