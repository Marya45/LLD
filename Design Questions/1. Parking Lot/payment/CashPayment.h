#pragma once
#include "Payment.h"
#include <iostream>

class CashPayment : public Payment {

public:
    bool processPayment(double amount) override {
        std::cout << "Processing cash payment of amount: " << amount << std::endl;
        return true;
    }

};