#pragma once
#include "../enums/VehicleType.h"
#include <string>

class Vehicle {

private:
    VehicleType type;
    std::string vehicleNumber;

public:
    Vehicle(VehicleType type, const std::string& vehicleNumber) : type(type), vehicleNumber(vehicleNumber) {}

    VehicleType getType() const {
        return type;
    }

    std::string getVehicleNumber() const {
        return vehicleNumber;
    }
};