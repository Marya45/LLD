#pragma once
#include "Vehicle.h"

class ParkingSpot {
    
private:
    int spotNumber;
    bool isOccupied;

public:
    ParkingSpot(int spotNumber) : spotNumber(spotNumber), isOccupied(false) {}

    int getSpotNumber() {
        return spotNumber;
    }

    bool getIsSpotOccupied() {
        return isOccupied;
    }

    void parkVehicle() {
        isOccupied = true;
    }

    void removeVehicle() {
        isOccupied = false;
    }
};