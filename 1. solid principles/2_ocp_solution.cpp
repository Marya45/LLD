#include <iostream>
#include <string>

class Marker {
public:
    std::string name;
    std::string color;
    int price;
    int year;

    Marker(std::string name, std::string color, int price, int year)
        : name(name), color(color), price(price), year(year) {}
};

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

// ----------------------------------------------------------
// GOOD: Following OCP using interfaces and polymorphism
// ----------------------------------------------------------

class InvoiceDao {
public:
    virtual void save() = 0;  // pure virtual = interface method
    virtual ~InvoiceDao() {}  // virtual destructor for safety
};

// ----------------------------------------------------------
// Concrete implementation for DatabaseInvoiceDao
// ----------------------------------------------------------
class DatabaseInvoiceDao : public InvoiceDao {
private:
    Invoice invoice;

public:
    DatabaseInvoiceDao(const Invoice& invoice) : invoice(invoice) {}
    // “This function overrides a virtual function from the base class.”
    // If you accidentally mistype the method name or signature using override, compiler will generate an error.
    void save() override {
        // Save into the DB the invoice
        std::cout << "Saving to DB...\n";
    }
};

// ----------------------------------------------------------
// Concrete implementation for FileInvoiceDao
// NEW File Save Operation: An extension without modification!
// ----------------------------------------------------------
class FileInvoiceDao : public InvoiceDao {
private:
    Invoice invoice;

public:
    FileInvoiceDao(const Invoice& invoice) : invoice(invoice) {}

    void save() override {
        // Save into the file the invoice
        std::cout << "Saving to file...\n";
    }
};

// ----------------------------------------------------------
// Usage demonstrating OCP compliance
// ----------------------------------------------------------
int main() {
    Invoice invoice(Marker("name", "color", 10, 2020), 10);
    invoice.calculateTotal();

    InvoiceDao* databaseInvoiceDao = new DatabaseInvoiceDao(invoice);
    databaseInvoiceDao->save(); // Save to DB

    InvoiceDao* fileInvoiceDao = new FileInvoiceDao(invoice);
    fileInvoiceDao->save(); // Save to File

    // The system is:
    // - OPEN for extension (new save functions can be added)
    // - CLOSED for modification (existing code remains unchanged)

    delete databaseInvoiceDao;
    delete fileInvoiceDao;

    return 0;
}
