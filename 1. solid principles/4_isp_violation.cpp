#include <iostream>
#include <stdexcept>

// ------------------------------------------------------------
// BAD: This class violates ISP
// This is a fat interface
// One large interface forcing all implementers to define unused methods
// ------------------------------------------------------------
class RestaurantEmployee {
public:
    virtual void prepareFood() = 0;
    virtual void decideMenu() = 0;
    virtual void serveFoodAndDrinks() = 0;
    virtual void takeOrder() = 0;
    virtual void cleanTheKitchen() = 0;

    virtual ~RestaurantEmployee() = default;
};

// ------------------------------------------------------------
// BAD: This class violates ISP (clients shouldn't depend on unused interfaces)
// Bloated class with empty or error-throwing methods
// This Waiter is forced to implement methods it doesn't need
// ------------------------------------------------------------
class Waiter : public RestaurantEmployee {
public:
    void takeOrder() override {
        std::cout << "Taking order..." << std::endl;
    }

    void serveFoodAndDrinks() override {
        std::cout << "Serving food and drinks..." << std::endl;
    }

    void cleanTheKitchen() override {
        // Forced to implement but doesn't make sense for a waiter
        throw std::logic_error("Detail Message: Waiter cannot clean the kitchen!");
    }

    void prepareFood() override {
        // Forced to implement but doesn't make sense for a waiter
        throw std::logic_error("Detail Message: Waiter cannot prepare food!");
    }

    void decideMenu() override {
        // Forced to implement but doesn't make sense for a waiter
        throw std::logic_error("Detail Message: Waiter cannot decide the menu!");
    }
};

// ------------------------------------------------------------
// Usage example - showing the problem
// ------------------------------------------------------------
int main() {
    Waiter waiter;

    // Works fine
    waiter.takeOrder();
    waiter.serveFoodAndDrinks();

    // These will throw exceptions
    try {
        waiter.prepareFood(); // forced implementation
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        waiter.decideMenu(); // forced implementation
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        waiter.cleanTheKitchen(); // forced implementation
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
