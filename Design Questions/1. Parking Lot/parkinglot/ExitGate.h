#pragma once
#include <iostream>
#include "../Ticket.h"
#include "../pricing/CostComputation.h"
#include "../payment/Payment.h"
#include "./ParkingBuilding.h"

class ExitGate {

private:
    CostComputation* costComputation;

public:

    ExitGate(CostComputation* costComp) : costComputation(costComp) {}

    void exit(ParkingBuilding* building,Ticket* ticket, Payment* payment) {
        double amount = price(ticket);
        bool success = payment->processPayment(amount);
        if(success){
            building->releaseTicket(ticket);
            std::cout<<"Vehicle exited successfully."<<std::endl;
        }
        else{
            std::cout<<"Payment failed. Cannot exit vehicle."<<std::endl;
        }
    }

    double price(Ticket* ticket) {
        time_t currentTime = time(0);
        double hoursParked = difftime(currentTime, ticket->getEntryTime()) / 3600;
        return costComputation->computeCost(static_cast<int>(hoursParked));
    }

};