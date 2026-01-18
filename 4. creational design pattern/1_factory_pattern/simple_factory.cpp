#include <iostream>
#include <memory>

using namespace std;

// ------------------------------------
// Step 1: Define the Product Interface
// ------------------------------------
class Shape {
public:
    virtual void computeArea() = 0;
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

// ------------------------------------
// Step 2: Concrete Product Classes
// ------------------------------------
class Circle : public Shape {
public:
    void computeArea() override {
        cout << "Inside Circle::computeArea() method." << endl;
    }

    void draw() override {
        cout << "Inside Circle::draw() method." << endl;
    }
};

class Rectangle : public Shape {
public:
    void computeArea() override {
        cout << "Inside Rectangle::computeArea() method." << endl;
    }

    void draw() override {
        cout << "Inside Rectangle::draw() method." << endl;
    }
};

class Square : public Shape {
public:
    void computeArea() override {
        cout << "Inside Square::computeArea() method." << endl;
    }

    void draw() override {
        cout << "Inside Square::draw() method." << endl;
    }
};

// ------------------------------------
// Step 3: Enum to represent Shape Types
// ------------------------------------
enum class ShapeType {
    CIRCLE,
    RECTANGLE,
    SQUARE
};

// ------------------------------------
// Step 4: Simple Factory Class
// ------------------------------------
class ShapeFactory {
public:
    static shared_ptr<Shape> createShapeInstance(ShapeType shapeType) {
        switch (shapeType) {
            case ShapeType::CIRCLE:
                return make_shared<Circle>();
            case ShapeType::RECTANGLE:
                return make_shared<Rectangle>();
            case ShapeType::SQUARE:
                return make_shared<Square>();
            default:
                return nullptr;
        }
    }
};

// ------------------------------------
// Step 5: Simple Factory Demo (Client Code)
// ------------------------------------
int main() {
    cout << "======= Simple Factory Design Pattern ======" << endl;

    // set the type you want
    ShapeType shapeType = ShapeType::SQUARE;

    // get the shape
    shared_ptr<Shape> shape =
        ShapeFactory::createShapeInstance(shapeType);

    shape->draw();
    shape->computeArea();

    return 0;
}