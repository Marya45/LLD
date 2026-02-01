#pragma once
#include "Payment.h"
#include <iostream>

class UpiPayment : public Payment {

public:
    void processPayment(double amount) override {
        std::cout << "Processing UPI payment of amount: " << amount << std::endl;
    }

};