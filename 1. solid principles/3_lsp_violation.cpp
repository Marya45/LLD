#include <iostream>
#include <string>
#include <stdexcept>

// ------------------------------------------------------------
// BAD: This design violates LSP
// ------------------------------------------------------------
class Bike {
public:
    virtual void turnOnEngine() = 0;
    virtual void turnOffEngine() = 0;
    virtual void accelerate() = 0;
    virtual void applyBrakes() = 0;

    virtual ~Bike() = default; // "Please generate the default implementation of this function for me."
};

// ------------------------------------------------------------
// Subclass of Bike - implements all Bike class behavior
// ------------------------------------------------------------
class MotorCycle : public Bike {
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
        this->speed = this->speed + 10; // increase the speed
        std::cout << "MotorCycle Speed: " << this->speed << "\n";
    }

    void applyBrakes() override {
        this->speed = this->speed - 5; // decrease the speed
        std::cout << "MotorCycle Speed: " << this->speed << "\n";
    }
};

// ------------------------------------------------------------
// This class violates LSP!
// ------------------------------------------------------------
class Bicycle : public Bike {
public:
    std::string brand;
    bool hasGears;
    int speed;

    Bicycle(std::string brand, bool hasGears, int speed)
        : brand(brand), hasGears(hasGears), speed(speed) {}

    // ------------------------------------------------------------
    // LSP Violation: Strengthening preconditions
    // Bicycle changes the behavior of turnOnEngine
    // ------------------------------------------------------------
    void turnOnEngine() override {
        throw std::logic_error("Detail Message: Bicycle has no engine!");
    }

    // Bicycle changes the behavior of turnOffEngine
    void turnOffEngine() override {
        throw std::logic_error("Detail Message: Bicycle has no engine!");
    }

    void accelerate() override {
        this->speed = this->speed + 10; // increase the speed
        std::cout << "Bicycle Speed: " << this->speed << "\n";
    }

    void applyBrakes() override {
        this->speed = this->speed - 5; // decrease the speed
        std::cout << "Bicycle Speed: " << this->speed << "\n";
    }
};

// ------------------------------------------------------------
// Usage example - demonstrates the LSP violations
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

    std::cout << "\n--- Bicycle Behavior (LSP violation expected) ---\n";

    // Client expects to be able to see the same behavior with Bicycle
    try {
        bicycle.turnOnEngine(); // fails to implement Bike class behavior
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    bicycle.accelerate();
    bicycle.applyBrakes();

    try {
        bicycle.turnOffEngine(); // fails to implement Bike class behavior
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}