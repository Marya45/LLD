#pragma once
#include "../spotManagers/ParkingSpotManager.h"
#include "../Entity/ParkingSpot.h"
#include "../enums/VehicleType.h"
#include <map>

class ParkingLevel {

private: 
    int level_no;
    std::map<VehicleType, ParkingSpotManager*> managers;

public:
    ParkingLevel(int level_no,std::map<VehicleType, ParkingSpotManager*> mgrs) 
        : level_no(level_no), managers(mgrs) {}

    bool hasAvailableSpot(VehicleType type) {
        ParkingSpotManager* manager = managers[type];
        ParkingSpot* spot = manager->getParkingSpot();
        return spot != nullptr;
    }

    ParkingSpot* park(VehicleType type) {
        ParkingSpotManager* manager = managers[type];
        ParkingSpot* spot = manager->getParkingSpot();
        if (spot != nullptr) {
            spot->parkVehicle();
        }
        return spot;
    }

    void unpark(ParkingSpot* spot, VehicleType type) {
        spot->removeVehicle();
    }

    int getLevelNo() {
        return level_no;
    }

};