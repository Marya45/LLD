#pragma once
#include "../Ticket.h"
#include "./ParkingBuilding.h"

class EntranceGate {

public:

    Ticket* enter(ParkingBuilding* building, Vehicle* vehicle) {
        return building->allocate(vehicle);
    }

};