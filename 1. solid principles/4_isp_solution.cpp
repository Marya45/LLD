#include <iostream>
using namespace std;

/* 
 * GOOD: This follows ISP - Multiple focused interfaces following ISP 
 */
class ChefTasks {
public:
    virtual void prepareFood() = 0;
    virtual void decideMenu() = 0;
    virtual ~ChefTasks() = default;
};

/* 
 * GOOD: This follows ISP - Multiple focused interfaces following ISP 
 */
class WaiterTasks {
public:
    virtual void serveFoodAndDrinks() = 0;
    virtual void takeOrder() = 0;
    virtual ~WaiterTasks() = default;
};

/* 
 * GOOD: This follows ISP - Multiple focused interfaces following ISP 
 */
class MaintenanceTasks {
public:
    virtual void cleanTheKitchen() = 0;
    virtual void reStockGroceries() = 0;
    virtual ~MaintenanceTasks() = default;
};

/* 
 * GOOD: This class follows ISP
 * Now classes only implement what they actually need - Clean implementations
 */
class Chef : public ChefTasks {
public:
    void prepareFood() override {
        cout << "Preparing food..." << endl;
    }

    void decideMenu() override {
        cout << "Deciding menu..." << endl;
    }
};

/* 
 * GOOD: This class follows ISP
 * Now classes only implement what they actually need - Clean implementations
 */
class Waiter : public WaiterTasks {
public:
    void serveFoodAndDrinks() override {
        cout << "Serving food and drinks..." << endl;
    }

    void takeOrder() override {
        cout << "Taking order..." << endl;
    }
};

/* 
 * Usage example - Following ISP 
 */
int main() {
    // Create the objects
    // Now classes only implement what they actually support
    Chef chef;
    Waiter waiter;

    // Use the objects
    // These work perfectly - no forced implementations
    chef.prepareFood();
    chef.decideMenu();

    // These work perfectly - no forced implementations
    waiter.takeOrder();
    waiter.serveFoodAndDrinks();

    return 0;
}
