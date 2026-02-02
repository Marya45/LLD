#pragma once
#include <iostream>
#include "./ParkingLevel.h"
#include "../pricing/CostComputation.h"
#include "../Ticket.h"

class ParkingBuilding {

private:
    std::vector<ParkingLevel*> levels;
    CostComputation* costComputation;

public:
    ParkingBuilding(std::vector<ParkingLevel*> lvls, CostComputation* costComp) 
        : levels(lvls), costComputation(costComp) {}

    Ticket* allocate(Vehicle* vehicle){

        for(auto level : levels){
            if(level->hasAvailableSpot(vehicle->getType())){
                ParkingSpot* spot = level->park(vehicle->getType());
                if(spot != nullptr){
                    std::cout<< "Parking allocated at level: " << level->getLevelNo() << " spot: " << spot->getSpotNumber() << std::endl;
                    return new Ticket(vehicle, spot, level);
                }
            }
        }
        std::cout<<"No parking spot available for vehicle number: " << vehicle->getVehicleNumber() << std::endl;
        return nullptr;
    }

    void releaseTicket(Ticket* ticket){
        ticket->getParkingLevel()->unpark(ticket->getParkingSpot(), ticket->getVehicle()->getType());
        std::cout<< "Parking released at level: " << ticket->getParkingLevel()->getLevelNo() 
                 << " spot: " << ticket->getParkingSpot()->getSpotNumber() << std::endl;
    }

};