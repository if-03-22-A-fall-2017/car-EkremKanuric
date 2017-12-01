

#include <stdio.h>
#include "car.h"
#define MAX_ACCELERATION_RATE_AIXAM 1.0
#define MAX_ACCELERATION_RATE_FIAT_MULTIPLA 2.26
#define MAX_ACCELERATION_RATE_JEEP 3.14
#define MIN_ACCELERATION_RATE -8
#define MAX_SPEED_AIXAM 45
#define MAX_SPEED_FIAT_MULTIPLA 170
#define MAX_SPEED_JEEP 196

static int count_of_multipla = 0;
static int count_of_jeep = 0;
static int count_of_aixam = 0;

struct CarType{
  enum type type;
  enum color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool available_or_not;
};

static struct CarType A1 {AIXAM, RED, 16, 0, 0, false};
static struct CarType M1 {FIAT_MULTIPLA, GREEN, 65, 0, 0, false};
static struct CarType M2 {FIAT_MULTIPLA, BLUE, 65, 0, 0, false};
static struct CarType M3 {FIAT_MULTIPLA, ORANGE, 65, 0, 0, false};
static struct CarType J1 {JEEP, SILVER, 80, 0, 0, false};
static struct CarType J2 {JEEP, BLACK, 80, 0, 0, false};

void init(){
  A1 = {AIXAM, RED, 16, 0, 0,false};
  M1 = {FIAT_MULTIPLA, GREEN, 65, 0, 0,false};
  M2 = {FIAT_MULTIPLA, BLUE, 65, 0, 0,false};
  M3 = {FIAT_MULTIPLA, ORANGE, 65, 0, 0,false};
  J1 = {JEEP, SILVER, 80, 0, 0,false};
  J2 = {JEEP, BLACK, 80, 0, 0,false};
  count_of_multipla = 0;
  count_of_jeep = 0;
  count_of_aixam = 0;
}
Car get_car(type x){
  Car c;
  if (x == AIXAM ) {
    if (count_of_aixam == 0) {
      c = &A1;
      count_of_aixam++;
      A1.available_or_not = true;
    }
    else{
      return 0;
    }
  }
  else if (x == FIAT_MULTIPLA) {
    if (count_of_multipla == 0) {
      c = &M1;
      count_of_multipla++;
      M1.available_or_not = true;
    }
    else if (count_of_multipla == 1) {
      c = &M2;
      count_of_multipla++;
      M2.available_or_not = true;
    }
    else if (count_of_multipla == 2) {
      count_of_multipla++;
      c = &M3;
      M3.available_or_not = true;
    }
    else{
      return 0;
    }
  }
  else if (x == JEEP) {
    if (x == JEEP) {
      if (count_of_jeep == 0) {
        c = &J1;
        count_of_jeep++;
        J1.available_or_not = true;
      }
      else if (count_of_jeep == 1) {
        count_of_jeep++;
        c = &J2;
        J2.available_or_not = true;
      }
      else{
        return 0;
      }
    }
  }
  return c;
}
type get_type(Car car){
  return car->type;
}
color get_color(Car car){
  return car->color;
}
int get_fill_level(Car car){
  return car->fill_level;
}
double get_acceleration_rate(Car car){
  return car->acceleration_rate;
}
int get_speed(Car car){
  return car->speed +0.5;
}

void accelerate(Car car){
car->speed += car->acceleration_rate * 3.6;
  if (car->type == AIXAM) {
    if (MAX_SPEED_AIXAM < car->speed) {
      car->speed = MAX_SPEED_AIXAM;
    }
  }
  else if (car->type == FIAT_MULTIPLA) {
    if (car->speed > MAX_SPEED_FIAT_MULTIPLA) {
      car->speed = MAX_SPEED_FIAT_MULTIPLA;
    }
  }
  else if (car->type == JEEP) {
    if (car->speed > MAX_SPEED_JEEP) {
      car->speed = MAX_SPEED_JEEP;
    }
  }
}

void set_acceleration_rate(Car car, double acceleration_rate){
  if (acceleration_rate < MIN_ACCELERATION_RATE) {
    acceleration_rate = MIN_ACCELERATION_RATE;
  }
  else if (car->type == AIXAM) {
    if (acceleration_rate > MAX_ACCELERATION_RATE_AIXAM) {
      car->acceleration_rate = MAX_ACCELERATION_RATE_AIXAM;
    }
    else{
      car->acceleration_rate = acceleration_rate;
    }
  }
  else if (car->type == FIAT_MULTIPLA) {
    if (acceleration_rate > MAX_ACCELERATION_RATE_FIAT_MULTIPLA) {
      car->acceleration_rate = MAX_ACCELERATION_RATE_FIAT_MULTIPLA;
    }
    else{
      car->acceleration_rate = acceleration_rate;
    }
  }
  else if (car->type == JEEP) {
    if (acceleration_rate > MAX_ACCELERATION_RATE_JEEP) {
      car->acceleration_rate = MAX_ACCELERATION_RATE_JEEP;
    }
    else{
      car->acceleration_rate = acceleration_rate;
    }
}
}
