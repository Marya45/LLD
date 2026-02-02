#pragma once
#include "Entity/Vehicle.h"
#include "Entity/ParkingSpot.h"
#include "parkinglot/ParkingLevel.h"
#include <ctime>

class Ticket {

private:
    Vehicle* vehicle;
    ParkingLevel* parkingLevel;
    ParkingSpot* spot;
    time_t entryTime = time(0);

public: 
    Ticket(Vehicle* v, ParkingSpot* s, ParkingLevel* level) : vehicle(v) , spot(s), parkingLevel(level) {}

    time_t getEntryTime() {
        return entryTime;
    }

    Vehicle* getVehicle() {
        return vehicle;
    }

    ParkingSpot* getParkingSpot() {
        return spot;
    }

    ParkingLevel* getParkingLevel() {
        return parkingLevel;
    }

};