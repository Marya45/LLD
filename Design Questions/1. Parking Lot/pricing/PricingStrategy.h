#pragma once 

class PricingStrategy {
public:
    virtual double calculatePrice(int hoursParked) = 0;
    virtual ~PricingStrategy() = default;
};