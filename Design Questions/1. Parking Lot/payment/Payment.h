#pragma once 

class Payment {

public: 
    virtual bool processPayment(double amount) = 0;
    virtual ~Payment() = default;
};