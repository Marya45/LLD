#pragma once 
#include "PricingStrategy.h"

class FixedPricingStrategy : public PricingStrategy {
private:
    double fixedRatePerHour = 10.0; 
public: 
    double calculatePrice(int hoursParked) override {
        return fixedRatePerHour * hoursParked;
    }
};