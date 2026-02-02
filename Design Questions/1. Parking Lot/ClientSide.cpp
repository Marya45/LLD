#include <iostream>
#include <vector>
#include <map>
#include "parkinglot/ParkingLot.h"
#include "payment/CashPayment.h"
#include "payment/UpiPayment.h"
#include "enums/VehicleType.h"
#include "Entity/Vehicle.h"
#include "spotManagers/ParkingSpotManager.h"
#include "Entity/ParkingSpot.h"
#include "pricing/PricingStrategy.h"
#include "pricing/FixedPricingStrategy.h"
#include "pricing/CostComputation.h"
#include "parkinglot/ParkingLevel.h"
#include "parkinglot/ParkingBuilding.h"
#include "parkinglot/EntranceGate.h"
#include "parkinglot/ExitGate.h"
#include "Ticket.h"
#include "LookupStrategy/RandomLookupStrategy.h"
#include "LookupStrategy/ParkingSpotLookupStrategy.h"
#include "spotManagers/TwoWheelerSpotManager.h"
#include "spotManagers/FourWheelerSpotManager.h"


int main(){

    ParkingSpotLookupStrategy* strategy = new RandomLookupStrategy();

    std::map<VehicleType, ParkingSpotManager*> level1Managers = {
        {VehicleType::FOUR_WHEELER, new FourWheelerSpotManager(strategy,{
            new ParkingSpot(1),
        })},
        {VehicleType::TWO_WHEELER, new TwoWheelerSpotManager(strategy,{
            new ParkingSpot(2),
            new ParkingSpot(3)
        })}
    };

    ParkingLevel* level1 = new ParkingLevel(1, level1Managers);

    std::map<VehicleType, ParkingSpotManager*> level2Managers = {
        {VehicleType::FOUR_WHEELER, new FourWheelerSpotManager(strategy,{
            new ParkingSpot(1),
        })},
        {VehicleType::TWO_WHEELER, new TwoWheelerSpotManager(strategy,{
            new ParkingSpot(2),
        })}
    };

    ParkingLevel* level2 = new ParkingLevel(2, level2Managers);


    ParkingBuilding* building = new ParkingBuilding({level1, level2}, 
        new CostComputation(new FixedPricingStrategy())
    );

    ParkingLot* parkingLot = new ParkingLot(
        new EntranceGate(),
        new ExitGate(new CostComputation(new FixedPricingStrategy())),
        building
    );

    Vehicle* car = new Vehicle(VehicleType::FOUR_WHEELER, "CAR-12345");
    Vehicle* bike = new Vehicle(VehicleType::TWO_WHEELER, "BIKE-54321");
    Vehicle* car2 = new Vehicle(VehicleType::FOUR_WHEELER, "TRUCK-11111");
    Ticket* ticket1 = parkingLot->enter(car);
    Ticket* ticket2 = parkingLot->enter(bike);
    Ticket* ticket3 = parkingLot->enter(car2);

    parkingLot->exit(ticket1, new CashPayment());
    parkingLot->exit(ticket2, new UpiPayment());
}