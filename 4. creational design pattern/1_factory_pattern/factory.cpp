#include <iostream>
#include <memory>

using namespace std;

// ------------------------------------
// Step 1: Product Interface
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
// Step 3: Abstract Creator Class
// ------------------------------------
class ShapeFactory {
public:
    // Factory Method
    virtual shared_ptr<Shape> createShape() = 0;
    virtual ~ShapeFactory() = default;
};

// ------------------------------------
// Step 4: Concrete Creator Classes
// ------------------------------------
class CircleCreator : public ShapeFactory {
public:
    shared_ptr<Shape> createShape() override {
        return make_shared<Circle>();
    }
};

class RectangleCreator : public ShapeFactory {
public:
    shared_ptr<Shape> createShape() override {
        return make_shared<Rectangle>();
    }
};

class SquareCreator : public ShapeFactory {
public:
    shared_ptr<Shape> createShape() override {
        return make_shared<Square>();
    }
};

// ------------------------------------
// Enum to represent Shape Types
// ------------------------------------
enum class ShapeType {
    CIRCLE,
    RECTANGLE,
    SQUARE
};

// ------------------------------------
// Step 5: Client Code Demonstration
// ------------------------------------
shared_ptr<Shape> getShapeInstance(ShapeType shapeType) {

    shared_ptr<ShapeFactory> factory;

    switch (shapeType) {
        case ShapeType::CIRCLE:
            factory = make_shared<CircleCreator>();
            break;

        case ShapeType::RECTANGLE:
            factory = make_shared<RectangleCreator>();
            break;

        case ShapeType::SQUARE:
            factory = make_shared<SquareCreator>();
            break;

        default:
            return nullptr;
    }

    return factory->createShape();
}

int main() {
    cout << "======= Factory Method Design Pattern ======" << endl;

    // set the type you want
    ShapeType shapeType = ShapeType::SQUARE;

    // get the shape
    shared_ptr<Shape> shape = getShapeInstance(shapeType);

    // perform operations
    shape->draw();
    shape->computeArea();

    return 0;
}
