#include <iostream>
#include <memory>

using namespace std;

// ==================================================
// Step 1: Abstract Product Interfaces
// ==================================================
class CarExterior {
public:
    virtual void addExteriorComponents() = 0;
    virtual ~CarExterior() = default;
};

class CarInterior {
public:
    virtual void addInteriorComponents() = 0;
    virtual ~CarInterior() = default;
};

// ==================================================
// Step 2: Concrete Products – Economy Car Family
// ==================================================
class EconomyCarExterior : public CarExterior {
public:
    void addExteriorComponents() override {
        cout << "Adding basic exterior components for Economy Car." << endl;
    }
};

class EconomyCarInterior : public CarInterior {
public:
    void addInteriorComponents() override {
        cout << "Adding basic interior components for Economy Car." << endl;
    }
};

// ==================================================
// Step 3: Concrete Products – Luxury Car Family
// ==================================================
class LuxuryCarExterior : public CarExterior {
public:
    void addExteriorComponents() override {
        cout << "Adding luxurious exterior components for Luxury Car." << endl;
    }
};

class LuxuryCarInterior : public CarInterior {
public:
    void addInteriorComponents() override {
        cout << "Adding luxurious interior components for Luxury Car." << endl;
    }
};

// ==================================================
// Step 4: Abstract Factory Interface
// ==================================================
class CarFactory {
public:
    // Factory methods
    virtual shared_ptr<CarInterior> createInterior() = 0;
    virtual shared_ptr<CarExterior> createExterior() = 0;

    virtual void produceCompleteVehicle() {
        cout << "Starting complete vehicle production..." << endl;

        auto interior = createInterior();
        auto exterior = createExterior();

        interior->addInteriorComponents();
        exterior->addExteriorComponents();

        cout << "Vehicle production completed!" << endl;
    }

    virtual ~CarFactory() = default;
};

// ==================================================
// Step 5: Concrete Factories
// ==================================================
class EconomyCarFactory : public CarFactory {
private:
    string brand;

public:
    EconomyCarFactory(const string& brand) : brand(brand) {}

    shared_ptr<CarInterior> createInterior() override {
        return make_shared<EconomyCarInterior>();
    }

    shared_ptr<CarExterior> createExterior() override {
        return make_shared<EconomyCarExterior>();
    }
};

class LuxuryCarFactory : public CarFactory {
private:
    string brand;

public:
    LuxuryCarFactory(const string& brand) : brand(brand) {}

    shared_ptr<CarInterior> createInterior() override {
        return make_shared<LuxuryCarInterior>();
    }

    shared_ptr<CarExterior> createExterior() override {
        return make_shared<LuxuryCarExterior>();
    }
};

// ==================================================
// Enum for Car Types
// ==================================================
enum class CarType {
    ECONOMY,
    PREMIUM,
    LUXURY
};

// ==================================================
// Step 6: Factory Provider
// ==================================================
class CarFactoryProvider {
public:
    shared_ptr<CarFactory> getFactory(CarType type, const string& brand) {
        switch (type) {
            case CarType::ECONOMY:
                return make_shared<EconomyCarFactory>(brand);

            case CarType::PREMIUM:
            case CarType::LUXURY:
                return make_shared<LuxuryCarFactory>(brand);

            default:
                throw invalid_argument("Unknown car type");
        }
    }
};

// ==================================================
// Step 7: Client Application
// ==================================================
int main() {
    cout << "===== Abstract Factory Design Pattern =====" << endl;

    CarFactoryProvider factoryProvider;

    // Economy Car
    auto economyCar =
        factoryProvider.getFactory(CarType::ECONOMY, "Honda");
    economyCar->produceCompleteVehicle();

    cout << endl;

    // Luxury Car
    auto luxuryCar =
        factoryProvider.getFactory(CarType::LUXURY, "Mercedes");
    luxuryCar->produceCompleteVehicle();

    cout << endl;

    // Premium Car (treated as Luxury)
    auto premiumCar =
        factoryProvider.getFactory(CarType::PREMIUM, "Rolls Royce");
    premiumCar->produceCompleteVehicle();

    return 0;
}
