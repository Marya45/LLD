#pragma once 
#include <vector>
#include "../Entity/ParkingSpot.h"

class ParkingSpotLookupStrategy {
public:
    virtual ParkingSpot* findSpot(std::vector<ParkingSpot*>& spots) = 0;
    virtual ~ParkingSpotLookupStrategy() = default;
};