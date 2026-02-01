#pragma once 

class Payment {

public: 
    virtual void processPayment(double amount) = 0;
    virtual ~Payment() = default;
};