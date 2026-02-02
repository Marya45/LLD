#pragma once
#include "./EntranceGate.h"
#include "./ExitGate.h"
#include "./ParkingBuilding.h"

class ParkingLot {

private:
    EntranceGate* entranceGate;
    ExitGate* exitGate;
    ParkingBuilding* building;

public:
    ParkingLot(EntranceGate* egate, ExitGate* xgate, ParkingBuilding* build) 
        : entranceGate(egate), exitGate(xgate), building(build) {}  

    Ticket* enter(Vehicle* vehicle) {
        return entranceGate->enter(building, vehicle); 
    }

    void exit(Ticket* ticket, Payment* payment) {
        exitGate->exit(building, ticket, payment);
    }

};