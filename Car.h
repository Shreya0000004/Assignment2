// Car.h

#ifndef CAR_H
#define CAR_H

class Car {
protected:
    int speed;
    int gear;

public:
    Car();
    void accelerate();
    void brake();
    void shiftGear(int newGear);
    int getSpeed() const; // Marked as const
    int getGear() const;  // Marked as const
};

#endif

