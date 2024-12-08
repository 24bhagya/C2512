// Example 10: `Food Production`
//`Base Class:` Food `{field: expirationDate, behavior: consume()}`
//`Derived Class 1:` Dairy `{field: fatContent, behavior: refrigerate()}`
//`Derived Class 2:` Bakery `{field: flourType, behavior: bake()}`
//`Final Derived Class:` Cheesecake `{field: layerCount, behavior: serve()}`

#include <iostream>
#include <string>

// Base Class: Food
class Food {
protected:
    std::string expirationDate;

public:
    // Constructor of Food
    Food(const std::string& expirationDate)
        : expirationDate(expirationDate) {  
        std::cout << "Food constructor called with expiration date: " << expirationDate << std::endl;
    }

    // Destructor of Food
    virtual ~Food() {
        std::cout << "Food destructor called." << std::endl;
    }

    void consume() {
        std::cout << "Consuming food before expiration date: " << expirationDate << std::endl;
    }
};

// Derived Class: Dairy
class Dairy : virtual public Food {
private:
    std::string fatContent;

public:
    // Constructor of Dairy
    Dairy(const std::string& expirationDate, const std::string& fatContent)
        : Food(expirationDate), fatContent(fatContent) {  
        std::cout << "Dairy constructor called with fat content: " << fatContent << std::endl;
    }

    // Destructor of Dairy
    virtual ~Dairy() {
        std::cout << "Dairy destructor called." << std::endl;
    }

    void refrigerate() {
        std::cout << "Refrigerating dairy product with fat content: " << fatContent << std::endl;
    }
};

// Derived Class: Bakery
class Bakery : virtual public Food {
private:
    std::string flourType;

public:
    // Constructor of Bakery
    Bakery(const std::string& expirationDate, const std::string& flourType)
        : Food(expirationDate), flourType(flourType) {  
        std::cout << "Bakery constructor called with flour type: " << flourType << std::endl;
    }

    // Destructor of Bakery
    virtual ~Bakery() {
        std::cout << "Bakery destructor called." << std::endl;
    }

    void bake() {
        std::cout << "Baking using flour type: " << flourType << std::endl;
    }
};

// Final Derived Class: Cheesecake
class Cheesecake : public Dairy, public Bakery {
private:
    std::string flavor;

public:
    // Constructor of Cheesecake
    Cheesecake(const std::string& expirationDate, const std::string& fatContent, const std::string& flourType, const std::string& flavor)
        : Food(expirationDate), Dairy(expirationDate, fatContent), Bakery(expirationDate, flourType), flavor(flavor) {  
        std::cout << "Cheesecake constructor called with flavor: " << flavor << std::endl;
    }

    // Destructor of Cheesecake
    ~Cheesecake() {
        std::cout << "Cheesecake destructor called." << std::endl;
    }

    void serve() {
        std::cout << "Serving cheesecake with flavor: " << flavor << std::endl;
    }
};

int main() {
    // Create a static object
    Cheesecake cheesecake("2024-12-31", "Full Cream", "All Purpose", "Strawberry");
    
    cheesecake.consume();
    cheesecake.refrigerate();
    cheesecake.bake();
    cheesecake.serve();

    // Create a dynamic object
    Cheesecake* cheesecakePtr = new Cheesecake("2024-12-31", "Low Fat", "Whole Wheat", "Chocolate");

    cheesecakePtr->consume();
    cheesecakePtr->refrigerate();
    cheesecakePtr->bake();
    cheesecakePtr->serve();

    delete cheesecakePtr;

    return 0;
}
