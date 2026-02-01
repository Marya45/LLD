#pragma once
#include "PricingStrategy.h"

class CostComputation {

private: 
    PricingStrategy* pricingStrategy;

public:

    CostComputation(PricingStrategy* strategy) : pricingStrategy(strategy) {}

    double computeCost(int hoursParked) {
        return pricingStrategy->calculatePrice(hoursParked);
    }
};