#include <iostream>
#include <memory>
#include <string>

using namespace std;

// ------------------------------------
// Step 1: Component Interface
// ------------------------------------
class BasePizza {
public:
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~BasePizza() = default;
};

// ------------------------------------
// Step 2: Concrete Components
// ------------------------------------
class PlainPizza : public BasePizza {
public:
    string getDescription() const override {
        return "Plain Pizza";
    }

    double getCost() const override {
        return 200.0;
    }
};

class Farmhouse : public BasePizza {
public:
    string getDescription() const override {
        return "Farmhouse Pizza";
    }

    double getCost() const override {
        return 300.0;
    }
};

class TandooriPaneerDelight : public BasePizza {
public:
    string getDescription() const override {
        return "Tandoori Paneer Delight Pizza";
    }

    double getCost() const override {
        return 400.0;
    }
};

class ChickenDominator : public BasePizza {
public:
    string getDescription() const override {
        return "Chicken Dominator Pizza";
    }

    double getCost() const override {
        return 500.0;
    }
};

// ------------------------------------
// Step 3: Abstract Decorator
// ------------------------------------
class ToppingDecorator : public BasePizza {
protected:
    shared_ptr<BasePizza> pizza;

public:
    ToppingDecorator(shared_ptr<BasePizza> pizza)
        : pizza(pizza) {}
};

// ------------------------------------
// Step 4: Concrete Decorators
// ------------------------------------
class ExtraCheeseTopping : public ToppingDecorator {
public:
    ExtraCheeseTopping(shared_ptr<BasePizza> pizza)
        : ToppingDecorator(pizza) {}

    string getDescription() const override {
        return pizza->getDescription() + " + Extra Cheese";
    }

    double getCost() const override {
        return pizza->getCost() + 20.0;
    }
};

class VeggiesTopping : public ToppingDecorator {
public:
    VeggiesTopping(shared_ptr<BasePizza> pizza)
        : ToppingDecorator(pizza) {}

    string getDescription() const override {
        return pizza->getDescription() + " + Veggies";
    }

    double getCost() const override {
        return pizza->getCost() + 30.0;
    }
};

class MushroomTopping : public ToppingDecorator {
public:
    MushroomTopping(shared_ptr<BasePizza> pizza)
        : ToppingDecorator(pizza) {}

    string getDescription() const override {
        return pizza->getDescription() + " + Mushroom";
    }

    double getCost() const override {
        return pizza->getCost() + 40.0;
    }
};

class PepperoniTopping : public ToppingDecorator {
public:
    PepperoniTopping(shared_ptr<BasePizza> pizza)
        : ToppingDecorator(pizza) {}

    string getDescription() const override {
        return pizza->getDescription() + " + Pepperoni";
    }

    double getCost() const override {
        return pizza->getCost() + 50.0;
    }
};

int main() {
    cout << "======= Decorator Design Pattern ======" << endl;

    auto pizza1 = make_shared<PlainPizza>();
    cout << "Order 1: " << pizza1->getDescription()
         << " = Rs." << pizza1->getCost() << endl;

    auto pizza2 = make_shared<ExtraCheeseTopping>(
                    make_shared<PlainPizza>());
    cout << "Order 2: " << pizza2->getDescription()
         << " = Rs." << pizza2->getCost() << endl;

    auto pizza3 = make_shared<VeggiesTopping>(
                    make_shared<ExtraCheeseTopping>(
                        make_shared<PlainPizza>()));
    cout << "Order 3: " << pizza3->getDescription()
         << " = Rs." << pizza3->getCost() << endl;

    auto pizza4 = make_shared<PepperoniTopping>(
                    make_shared<ExtraCheeseTopping>(
                        make_shared<PlainPizza>()));
    cout << "Order 4: " << pizza4->getDescription()
         << " = Rs." << pizza4->getCost() << endl;

    auto pizza5 = make_shared<MushroomTopping>(
                    make_shared<PepperoniTopping>(
                        make_shared<ExtraCheeseTopping>(
                            make_shared<PlainPizza>())));
    cout << "Order 5: " << pizza5->getDescription()
         << " = Rs." << pizza5->getCost() << endl;

    auto pizza6 = make_shared<Farmhouse>();
    cout << "Order 6: " << pizza6->getDescription()
         << " = Rs." << pizza6->getCost() << endl;

    auto pizza7 = make_shared<MushroomTopping>(
                    make_shared<ExtraCheeseTopping>(
                        make_shared<Farmhouse>()));
    cout << "Order 7: " << pizza7->getDescription()
         << " = Rs." << pizza7->getCost() << endl;

    auto pizza8 = make_shared<TandooriPaneerDelight>();
    cout << "Order 8: " << pizza8->getDescription()
         << " = Rs." << pizza8->getCost() << endl;

    auto pizza9 = make_shared<ChickenDominator>();
    cout << "Order 9: " << pizza9->getDescription()
         << " = Rs." << pizza9->getCost() << endl;

    auto pizza10 = make_shared<MushroomTopping>(
                     make_shared<ChickenDominator>());
    cout << "Order 10: " << pizza10->getDescription()
         << " = Rs." << pizza10->getCost() << endl;

    return 0;
}
