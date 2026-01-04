#include <iostream>
#include <string>

// ------------------------------------------------------------
// abstract class Bike
// All Bikes can do these things
// ------------------------------------------------------------
class Bike {
public:
    virtual void accelerate() = 0;
    virtual void applyBrakes() = 0;

    virtual ~Bike() = default;
};

// ------------------------------------------------------------
// interface Engine (C++ version)
// ------------------------------------------------------------
class Engine {
public:
    virtual void turnOnEngine() = 0;
    virtual void turnOffEngine() = 0;

    virtual ~Engine() = default;
};

// ------------------------------------------------------------
// Subclass of Bike - implements all Bike class behavior
// ------------------------------------------------------------
// MotorCycle extends Bike implements Engine
class MotorCycle : public Bike, public Engine {
public:
    std::string company;
    bool isEngineOn;
    int speed;

    MotorCycle(std::string company, int speed)
        : company(company), isEngineOn(false), speed(speed) {}

    void turnOnEngine() override {
        this->isEngineOn = true; // turn on the engine!
        std::cout << "Engine is ON!\n";
    }

    void turnOffEngine() override {
        this->isEngineOn = false; // turn off the engine!
        std::cout << "Engine is OFF!\n";
    }

    void accelerate() override {
        this->speed += 10; // increase the speed
        std::cout << "MotorCycle Speed: " << this->speed << "\n";
    }

    void applyBrakes() override {
        this->speed -= 5; // decrease the speed
        std::cout << "MotorCycle Speed: " << this->speed << "\n";
    }
};

// ------------------------------------------------------------
// GOOD: Following LSP
// Subclass of Bike - implements all Bike class behavior
// As Bicycles do not have engines, we need not implement Engine interface
// ------------------------------------------------------------
class Bicycle : public Bike {
public:
    std::string brand;
    bool hasGears;
    int speed;

    Bicycle(std::string brand, bool hasGears, int speed)
        : brand(brand), hasGears(hasGears), speed(speed) {}

    void accelerate() override {
        this->speed += 10; // increase the speed
        std::cout << "Bicycle Speed: " << this->speed << "\n";
    }

    void applyBrakes() override {
        this->speed -= 5; // decrease the speed
        std::cout << "Bicycle Speed: " << this->speed << "\n";
    }
};

// ------------------------------------------------------------
// Usage of LSP-compliant design
// ------------------------------------------------------------
int main() {
    // create the objects
    MotorCycle motorCycle("HeroHonda", 10);
    Bicycle bicycle("Hercules", true, 10);

    // Works fine with MotorCycle - implements all Bike class behavior
    motorCycle.turnOnEngine();
    motorCycle.accelerate();
    motorCycle.applyBrakes();
    motorCycle.turnOffEngine();

    // Works fine with Bicycle - implements all Bike class behavior
    bicycle.accelerate();
    bicycle.applyBrakes();

    return 0;
}
