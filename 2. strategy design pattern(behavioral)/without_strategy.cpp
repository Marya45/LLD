#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    virtual void drive() {
        cout << "\nVehicle: ";
        cout << "Driving Capability: Normal";
    }

    // Always add virtual destructor when using inheritance
    virtual ~Vehicle() = default;
};

// =================== SportsVehicle ===================
class SportsVehicle : public Vehicle {
public:
    // Overriding the drive method to provide specific behavior for sports vehicles
    void drive() override {
        cout << "\nSportsVehicle: ";
        cout << "Driving Capability: Sports";
    }
};

// =================== OffRoadVehicle ===================
class OffRoadVehicle : public Vehicle {
public:
    // Overriding the drive method to provide specific behavior
    void drive() override {
        cout << "\nOffRoadVehicle: ";
        cout << "Driving Capability: Sports"; // code duplication
        // As sports drive mode is not available in the parent class, we need to override it
        // and implement the specific behavior for all new vehicle types that require sports drive mode
    }
};

// =================== PassengerVehicle ===================
class PassengerVehicle : public Vehicle {
    // Reusing the existing drive method from the parent class
    // Driving Capability: Normal
    // No new implementation required
};

// =================== Demo ===================
int main() {
    cout << "Vehicle Drive Modes: Problem Demo";

    Vehicle* vehicle = new Vehicle();

    // Sports vehicle - sports drive mode
    vehicle = new SportsVehicle();
    vehicle->drive();

    // Off-road vehicle - sports drive mode
    vehicle = new OffRoadVehicle();
    vehicle->drive();

    // Passenger vehicle - normal drive mode
    vehicle = new PassengerVehicle();
    vehicle->drive();

    cout << "\n";
    return 0;
}
