/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: <your class>
* ---------------------------------------------------------
* Exercise Number: 0
* Title:			car.h
* Author:			P. Bauer
* Due Date:		January 9, 2015
* ----------------------------------------------------------
* Description:
* Car abstract data type demo.
* ----------------------------------------------------------
*/
#ifndef ___CAR_H
#define ___CAR_H

enum type{
    AIXAM, FIAT_MULTIPLA, JEEP
};
enum color{
  RED, GREEN, BLACK, SILVER, BLUE, ORANGE
};

typedef struct CarType* Car;

Car get_car(type type);
type get_type(Car car);
color get_color(Car car);
int get_fill_level(Car car);
double get_acceleration_rate(Car car);
int get_speed(Car car);
void set_acceleration_rate(Car car, double acceleration_rate);
void accelerate(Car car);
void init();
#endif
