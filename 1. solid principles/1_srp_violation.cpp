#include <iostream>
#include <string>

// Marker class (same as Java)
class Marker {
public:
    std::string name;
    std::string color;
    int price;
    int year;

    Marker(std::string name, std::string color, int price, int year) {
        this->name = name;
        this->color = color;
        this->price = price;
        this->year = year;
    }
};

// BAD: This class violates SRP by having multiple responsibilities
class Invoice {
private:
    Marker marker;
    int quantity;
    int total;

public:
    Invoice(const Marker& marker, int quantity)
        : marker(marker), quantity(quantity), total(0) {}

    // Responsibility 1: Calculate the total (business logic)
    void calculateTotal() {
        std::cout << "Calculating total...\n";
        total = marker.price * quantity;
    }

    // Responsibility 2: Database Operations
    void saveToDB() {
        // Save the data into DB
        std::cout << "Saving to DB...\n";
    }

    // Responsibility 3: Print the Invoice
    void printInvoice() {
        // Print the Invoice
        std::cout << "Printing Invoice...\n";
    }
};

// Usage example
int main() {
    Invoice invoice(Marker("name", "color", 10, 2020), 10);

    invoice.calculateTotal();
    invoice.saveToDB();
    invoice.printInvoice();

    return 0;
}