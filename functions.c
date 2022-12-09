//function.c
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#define ON 1
#define OFF 0

extern char engine_state;
extern int vehicle_speed;
extern char AC;
extern int AC_temp;
extern int room_temp;
extern int engine_temp;
extern char engine_temperature_controller;
extern int engine_desired_temp;
extern char quit;//flag to quit system
extern char speed_control;//flag for traffic light speed control

void engine_on_off()
{
	int choose_state=0;//initial system state
	setvbuf(stdout,NULL,_IONBF,0);
	printf("Do you want to turn the engine on\n");
	printf(" 0:engine OFF \t 1:engine ON \t 2:Quit engine\n");
	scanf("%d",&choose_state);
	while(!(choose_state>=0 && choose_state<=2))
	{	printf("invalid input try again \n");
	printf(" 0:engine OFF \t 1:engine ON \t 2:Quit engine\n");
	scanf("%d",&choose_state);
	}
	switch (choose_state)
	{
	case 0:
		engine_state=OFF;
		printf("System state :Engine is OFF\n");
		break;
	case 1:
		engine_state=ON;
		printf("System state :Engine is ON\n");
		break;
	case 2:
		quit=1;
		printf("System state :Quit system\n");
		break;
	default:
		printf("invalid input try again\n");
	}
}

void sensor_set_menu()
{	/*	the passenger should enter all the current data
		that should be given from sensor in a normal situation
 */
	int menu_choice;
	printf("please enter the current data for the following menus\n");
	printf("\n0:to turn off the engine \n1:keep it running \n ");
	scanf(" %d",&menu_choice);
	if(0 == menu_choice)
	{
		printf("Engine OFF \n\n");
		turn_off_the_engine();
	}
	else if (1==menu_choice)
	{
		set_vehicle_speed(); //set the car speed according to the traffic lights
		printf("\n set the room temperature and AC \n");
		set_room_temp();
		printf("\n set the engine temperature \n");
		set_the_engine_temp();
	}
	else
	{
		printf("invalid input try again \n");
		sensor_set_menu();
	}
}

void turn_off_the_engine()
{
	engine_state=OFF;
}

void set_vehicle_speed()
{
	char traffic_light;
	printf("enter current speed in Km/h \n");
	scanf("%d",&vehicle_speed);
	printf("current traffic light color is  \t 'G'\t 'O'\t 'R'\n");
	scanf(" %c",&traffic_light);
	switch (traffic_light)
	{
	case'G':
		speed_control=ON;
		vehicle_speed=100;
		break;
	case'O':
		speed_control=ON;
		vehicle_speed=30;
		break;
	case'R':
		speed_control=ON;
		vehicle_speed=0;
		break;
	default:
		printf("no traffic light no control is required \n");
		speed_control=0;
	}
}

void set_room_temp()
{
	printf("please enter current temperature\n");
	scanf(" %d",&room_temp);
	if(room_temp<10 || room_temp>30)
	{
		AC=ON;
		AC_temp=20;
	}
	else
	{
		AC=OFF;
	}
}

void set_the_engine_temp()
{
	printf("please enter the current engine temperature\n");
	scanf(" %d",&engine_temp);
	if(engine_temp<100 || engine_temp>150)
	{
		engine_temperature_controller=ON;
		engine_desired_temp=125;
	}
	else
	{
		engine_temperature_controller=OFF;
	}
}

void display_data()
{
	if(ON==engine_state)
	{
		printf("Engine state :ON \n");
	}

	else
	{
		printf("Engine state :OFF \n");
	}

	if(ON==AC)
	{
		printf("AC :ON \n");
		printf("AC temperature = %d cel. \n",AC_temp);
	}

	else
	{
		printf("AC :OFF \n");
	}
	printf("Vehicle Speed = %d Km/h \n",vehicle_speed);
	printf("Current room temperature = %d Cel \n",room_temp);
	if(ON==engine_temperature_controller)
	{
		printf("Engine Temperature controller is ON \n");
		printf("Engine desired temperature = %d cel. \n",engine_desired_temp);
	}
	else
	{
		printf("Engine Temperature controller is OFF \n");
	}


	printf("current engine temperature = %d Cel. \n",engine_temp);

}
