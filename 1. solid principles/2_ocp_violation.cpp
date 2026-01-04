#include <iostream>
#include <string>

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

// --------------------------------------
// Invoice class (same as your previous example)
// --------------------------------------
class Invoice {
private:
    Marker marker;
    int quantity;
    int total;

public:
    Invoice(const Marker& marker, int quantity)
        : marker(marker), quantity(quantity), total(0) {}

    void calculateTotal() {
        std::cout << "Calculating total...\n";
        total = marker.price * quantity;
    }
};

// --------------------------------------------------------------
// Responsibility: Managing Database Operations and File Operations
// BAD: This class violates OCP - needs modification for every new
//      kind of save function
// --------------------------------------------------------------
class InvoiceDao {
public:
    Invoice invoice;

    InvoiceDao(const Invoice& invoice) : invoice(invoice) {}

    void saveToDB() {
        // Save into the DB the invoice
        std::cout << "Saving to DB...\n";
    }

    // BAD: This design violates OCP
    // Every time we add a new save function, we need to modify the
    // existing InvoiceDao class
    void saveToFile() {
        // Save into the file
        std::cout << "Saving to file...\n";
    }
};

// --------------------------------------------------------------
// Usage example - showing the problem
// --------------------------------------------------------------
int main() {
    Invoice invoice(Marker("name", "color", 10, 2020), 10);
    invoice.calculateTotal();

    InvoiceDao databaseFileSave(invoice);

    databaseFileSave.saveToDB();    // Save to DB
    databaseFileSave.saveToFile();  // Save to File

    // Problem: If we want to add a new function like saveToMongoDB(),
    // we need to modify InvoiceDao and all its derived classes (if exists)
    // This violates the "closed for modification" part of OCP

    return 0;
}
