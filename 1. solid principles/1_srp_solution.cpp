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

// Responsibility: Managing Invoice data only
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
};

class InvoiceDB {
private:
    Invoice invoice;
public:
    InvoiceDB(const Invoice& invoice) : invoice(invoice) {}
    // Responsibility 2: Database Operations
    void saveToDB() {
        // Save the data into DB
        std::cout << "Saving to DB...\n";
    }
};

class InvoicePrinter {
private:
    Invoice invoice;
public:
    InvoicePrinter(const Invoice& invoice) : invoice(invoice) {}
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

    InvoiceDB db(invoice);
    db.saveToDB();

    InvoicePrinter printer(invoice);
    printer.printInvoice();

    return 0;
}