#include <iostream>
#include <memory>
using namespace std;

/*-------------------------------------------------------
   STRATEGY INTERFACE
   - Pure virtual function defines the contract for drive()
--------------------------------------------------------*/
class DriveStrategy {
public:
    virtual void drive() = 0;   // abstract method
    virtual ~DriveStrategy() = default;  // virtual destructor
};


/*-------------------------------------------------------
   CONCRETE STRATEGIES
--------------------------------------------------------*/

// Normal Driving Mode
class NormalDrive : public DriveStrategy {
public:
    void drive() override {
        cout << "Driving Capability: Normal" << endl;
    }
};

// Sports Driving Mode
class SportsDrive : public DriveStrategy {
public:
    void drive() override {
        cout << "Driving Capability: Sports" << endl;
    }
};

// Electric Driving Mode
class EVDrive : public DriveStrategy {
public:
    void drive() override {
        cout << "Driving Capability: Electric" << endl;
    }
};


/*-------------------------------------------------------
   CONTEXT CLASS — Vehicle
   - Has-a DriveStrategy
   - Strategy injected via constructor
--------------------------------------------------------*/
class Vehicle {
protected:
    unique_ptr<DriveStrategy> driveStrategy;  // smart pointer

public:
    Vehicle(DriveStrategy* strategy) 
        : driveStrategy(strategy) {}  // constructor injection

    virtual ~Vehicle() = default;

    virtual void drive() {
        // typeid(*this).name() gives class name (mangled)
        cout << "\n" << typeid(*this).name() << ": ";
        driveStrategy->drive();
    }
};


/*-------------------------------------------------------
   CONCRETE VEHICLE TYPES
   - All extend Vehicle
--------------------------------------------------------*/
class GoodsVehicle : public Vehicle {
public:
    GoodsVehicle(DriveStrategy* strategy)
        : Vehicle(strategy) {}
};

class SportsVehicle : public Vehicle {
public:
    SportsVehicle(DriveStrategy* strategy)
        : Vehicle(strategy) {}
};

class OffRoadVehicle : public Vehicle {
public:
    OffRoadVehicle(DriveStrategy* strategy)
        : Vehicle(strategy) {}
};

class HybridVehicle : public Vehicle {
public:
    HybridVehicle(DriveStrategy* strategy)
        : Vehicle(strategy) {}
};


/*-------------------------------------------------------
   CLIENT — MAIN FUNCTION
--------------------------------------------------------*/
int main() {
    cout << "###### Strategy Design Pattern ######" << endl;
    cout << "###### Example: Vehicle Drive Modes ######\n";

    Vehicle* vehicle;

    vehicle = new SportsVehicle(new SportsDrive());
    vehicle->drive();
    delete vehicle;

    vehicle = new GoodsVehicle(new NormalDrive());
    vehicle->drive();
    delete vehicle;

    vehicle = new HybridVehicle(new EVDrive());
    vehicle->drive();
    delete vehicle;

    vehicle = new GoodsVehicle(new NormalDrive());
    vehicle->drive();
    delete vehicle;

    return 0;
}
