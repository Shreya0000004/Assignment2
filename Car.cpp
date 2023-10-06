// Car.cpp

#include "Car.h"

Car::Car() {
    speed = 0;
    gear = 0;
}

void Car::accelerate() {
    speed += 10;
}

void Car::brake() {
    if (speed >= 10) {
        speed -= 10;
    } else {
        speed = 0;
    }
}

void Car::shiftGear(int newGear) {
    gear = newGear;
}

int Car::getSpeed() const { // Marked as const
    return speed;
}

int Car::getGear() const {  // Marked as const
    return gear;
}



