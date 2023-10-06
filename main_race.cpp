#include <iostream>
#include "Car.h"
#include <vector>
#include <algorithm>

// Function to determine the winner based on final speed
Car& determineWinner(std::vector<Car>& cars) {
    Car* winner = &cars[0];
    for (size_t i = 1; i < cars.size(); ++i) {
        if (cars[i].getSpeed() > winner->getSpeed()) {
            winner = &cars[i];
        }
    }
    return *winner;
}

int main() {
    const int numCars = 5; // Number of cars in the race
    std::vector<Car> cars(numCars); // Create a vector of Car objects

    // Test Case 1
    for (int i = 0; i < numCars; ++i) {
        for (int j = 0; j < 3; ++j) {
            cars[i].accelerate();
        }
    }

    // Test Case 2
    cars[0].shiftGear(2);
    cars[1].shiftGear(3);
    cars[2].shiftGear(4);

    // Test Case 3
    for (int i = 0; i < numCars; ++i) {
        cars[i].brake();
    }

    // Test Case 4
    cars[3].accelerate();
    cars[4].accelerate();

    // Test Case 5
    cars[0].shiftGear(2);
    cars[1].shiftGear(3);
    cars[2].shiftGear(4);
    cars[3].shiftGear(5);
    cars[4].shiftGear(2);

    // Simulate the race for 9 time steps
    for (int time = 0; time < 9; ++time) {
        std::cout << "\nTime Step " << time + 1 << ":" << std::endl;
        for (int i = 0; i < numCars; ++i) {
            std::cout << "Car " << i + 1 << " - Speed: " << cars[i].getSpeed() << ", Gear: " << cars[i].getGear() << std::endl;
        }

        // Alternate acceleration and braking for specific cars in additional time steps
        if (time == 5) {
            cars[0].brake();
            cars[2].brake();
            cars[4].brake();
            cars[1].accelerate();
            cars[3].accelerate();
        } else if (time > 5) {
            if ((time - 5) % 2 == 0) {
                cars[0].accelerate();
                cars[2].accelerate();
                cars[4].accelerate();
            } else {
                cars[0].brake();
                cars[2].brake();
                cars[4].brake();
            }
        }
    }

    // Determine the winner
    Car& winner = determineWinner(cars);

    std::cout << "\nRace Results:" << std::endl;
    for (int i = 0; i < numCars; ++i) {
        std::cout << "Car " << i + 1 << " finished with a speed of " << cars[i].getSpeed() << std::endl;
    }

    std::cout << "Winner: Car " << &winner - &cars[0] + 1 << " with a speed of " << winner.getSpeed() << std::endl;

    return 0;
}





