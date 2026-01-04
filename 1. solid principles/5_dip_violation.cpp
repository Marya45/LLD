#include <iostream>
#include <string>
using namespace std;

// ======================== INTERFACES ========================

// Keyboard interface
class Keyboard {
public:
    virtual void getSpecifications() = 0;
    virtual ~Keyboard() = default;
};

// Mouse interface
class Mouse {
public:
    virtual void getSpecifications() = 0;
    virtual ~Mouse() = default;
};

// ======================== LOW-LEVEL MODULES ========================
// Concrete implementations

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


// ================================================================
// VIOLATION OF DIP
// High-level module directly depending on low-level module
// ================================================================

class MacBook {
private:
    WiredKeyboard* keyboard; // tight coupling
    WiredMouse* mouse;       // tight coupling

public:
    // Direct dependency on concrete classes
    MacBook(WiredKeyboard* wiredKeyboard, WiredMouse* wiredMouse)
        : keyboard(wiredKeyboard), mouse(wiredMouse) {}

    Mouse* getMouse() {
        return mouse;
    }

    Keyboard* getKeyboard() {
        return keyboard;
    }
};


// ======================== DEMO ========================

int main() {

    // create keyboard and mouse objects
    WiredKeyboard wiredKeyboard("USB", "Dell", "F602", "Grey");
    WiredMouse wiredMouse("USB", "Dell", "F602", "Grey");

    BluetoothKeyboard bluetoothKeyboard("Bluetooth", "Logitech", "G102", "Black");
    BluetoothMouse bluetoothMouse("Bluetooth", "Logitech", "G102", "Black");

    // create macbook
    MacBook macBookWithWiredParts(&wiredKeyboard, &wiredMouse);
    macBookWithWiredParts.getKeyboard()->getSpecifications();
    macBookWithWiredParts.getMouse()->getSpecifications();

    // create macbook with bluetooth keyboard and mouse
    // MacBook macBookWithBluetoothParts = MacBook(&bluetoothKeyboard, &bluetoothMouse);
    // cannot create macbook with bluetooth keyboard and mouse because
    // macbook depends on wired keyboard and mouse - tight coupling - violation of DIP

    return 0;
}
