#pragma once
#include <vector>
#include "../Entity/ParkingSpot.h"
#include "../LookupStrategy/ParkingSpotLookupStrategy.h"

class ParkingSpotManager {

protected:
    std::vector<ParkingSpot*> parkingSpots;
    ParkingSpotLookupStrategy* lookupStrategy;

public:
    ParkingSpotManager(ParkingSpotLookupStrategy* strategy,std::vector<ParkingSpot*> spots) : lookupStrategy(strategy), parkingSpots(spots) {}

    ParkingSpot* getParkingSpot() {
        return lookupStrategy->findSpot(parkingSpots);
    }

    void addSpot(ParkingSpot* spot){
        parkingSpots.push_back(spot);
    }

    virtual ~ParkingSpotManager() = default;
};