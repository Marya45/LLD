#pragma once 
#include "ParkingSpotLookupStrategy.h"

class RandomLookupStrategy : public ParkingSpotLookupStrategy {
public:
    ParkingSpot* findSpot(std::vector<ParkingSpot*>& spots) override {
        for (auto spot : spots) {
            if (!spot->getIsSpotOccupied()) {
                return spot;
            }
        }
        return nullptr;
    }
};