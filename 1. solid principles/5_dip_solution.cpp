#include <iostream>
#include <string>
using namespace std;

// ======================== INTERFACES ========================

// Abstraction for Keyboard
class Keyboard {
public:
    virtual void getSpecifications() = 0;
    virtual ~Keyboard() = default;
};

// Abstraction for Mouse
class Mouse {
public:
    virtual void getSpecifications() = 0;
    virtual ~Mouse() = default;
};

// ======================== LOW-LEVEL MODULES ========================

// Wired Keyboard
class WiredKeyboard : public Keyboard {
private:
    string connectionType;
    string company;
    string modelVersion;
    string color;

public:
    WiredKeyboard(string connectionType, string company, string modelVersion, string color)
        : connectionType(connectionType), company(company),
          modelVersion(modelVersion), color(color) {}

    void getSpecifications() override {
        cout << "===> Wired Keyboard\n";
        cout << "Connection Type: " << connectionType << "\n";
        cout << "Company: " << company << "\n";
        cout << "Model Version: " << modelVersion << "\n";
        cout << "Color: " << color << "\n";
    }
};

// Bluetooth Keyboard
class BluetoothKeyboard : public Keyboard {
private:
    string connectionType;
    string company;
    string modelVersion;
    string color;

public:
    BluetoothKeyboard(string connectionType, string company, string modelVersion, string color)
        : connectionType(connectionType), company(company),
          modelVersion(modelVersion), color(color) {}

    void getSpecifications() override {
        cout << "===> Bluetooth Keyboard\n";
        cout << "Connection Type: " << connectionType << "\n";
        cout << "Company: " << company << "\n";
        cout << "Model Version: " << modelVersion << "\n";
        cout << "Color: " << color << "\n";
    }
};

// Wired Mouse
class WiredMouse : public Mouse {
private:
    string connectionType;
    string company;
    string modelVersion;
    string color;

public:
    WiredMouse(string connectionType, string company, string modelVersion, string color)
        : connectionType(connectionType), company(company),
          modelVersion(modelVersion), color(color) {}

    void getSpecifications() override {
        cout << "===> Wired Mouse\n";
        cout << "Connection Type: " << connectionType << "\n";
        cout << "Company: " << company << "\n";
        cout << "Model Version: " << modelVersion << "\n";
        cout << "Color: " << color << "\n";
    }
};

// Bluetooth Mouse
class BluetoothMouse : public Mouse {
private:
    string connectionType;
    string company;
    string modelVersion;
    string color;

public:
    BluetoothMouse(string connectionType, string company, string modelVersion, string color)
        : connectionType(connectionType), company(company),
          modelVersion(modelVersion), color(color) {}

    void getSpecifications() override {
        cout << "===> Bluetooth Mouse\n";
        cout << "Connection Type: " << connectionType << "\n";
        cout << "Company: " << company << "\n";
        cout << "Model Version: " << modelVersion << "\n";
        cout << "Color: " << color << "\n";
    }
};

// ======================== FOLLOWING DIP ========================
// High-level module uses abstraction

class MacBook {
private:
    Keyboard* keyboard;
    Mouse* mouse;

public:
    // Dependency injection through constructor
    MacBook(Mouse* mouse, Keyboard* keyboard)
        : keyboard(keyboard), mouse(mouse) {}

    Mouse* getMouse() {
        return mouse;
    }

    Keyboard* getKeyboard() {
        return keyboard;
    }
};

// ======================== USAGE EXAMPLE ========================
// Following DIP

int main() {

    // create keyboard and mouse objects
    WiredKeyboard wiredKeyboard("USB", "Dell", "F602", "Grey");
    WiredMouse wiredMouse("USB", "Dell", "F602", "Grey");

    BluetoothKeyboard bluetoothKeyboard("Bluetooth", "Logitech", "G102", "Black");
    BluetoothMouse bluetoothMouse("Bluetooth", "Logitech", "G102", "Black");

    // Can easily create macbooks with different combinations of keyboard and mouse

    // create macbook with wired keyboard and mouse
    MacBook macBookWithWiredParts(&wiredMouse, &wiredKeyboard);
    macBookWithWiredParts.getKeyboard()->getSpecifications();
    macBookWithWiredParts.getMouse()->getSpecifications();

    cout << "------------------------------\n";

    // create macbook with bluetooth keyboard and mouse
    MacBook macBookWithBluetoothParts(&bluetoothMouse, &bluetoothKeyboard);
    macBookWithBluetoothParts.getKeyboard()->getSpecifications();
    macBookWithBluetoothParts.getMouse()->getSpecifications();

    return 0;
}
