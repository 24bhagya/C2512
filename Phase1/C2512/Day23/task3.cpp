//`Instrument and Guitar`
//`Base Class:` `Instrument`  
// Fields: `type`, `material`  
// Pure Virtual Behaviors: `play()`, `tune()`  
//`Derived Class:` `Guitar`  
// Fields: `stringCount`, `electric`  

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

// Base Class : Instrument
class Instrument {
protected:
    char* type;
    char* material;

public:
    Instrument(const char* instrumentType, const char* instrumentMaterial) {
        type = new char[strlen(instrumentType) + 1];
        strcpy(type, instrumentType);

        material = new char[strlen(instrumentMaterial) + 1];
        strcpy(material, instrumentMaterial);

        cout << "Instrument constructor called with type " << type << " and material " << material << endl;
    }

    virtual ~Instrument() {
        cout << "Instrument destructor called for type " << type << endl;
        delete[] type;
        delete[] material;
    }

    virtual void play() const = 0;  // Pure virtual method
    virtual void tune() const = 0;  // Pure virtual method
};

// Derived Class : Guitar
class Guitar : public Instrument {
private:
    int* stringCount;
    bool* electric;

public:
    Guitar(const char* instrumentType, const char* instrumentMaterial, int strings, bool isElectric)
        : Instrument(instrumentType, instrumentMaterial) {
        stringCount = new int(strings);
        electric = new bool(isElectric);

        cout << "Guitar constructor called with string count " << *stringCount << " and electric status " 
             << (*electric ? "Yes" : "No") << endl;
    }

    ~Guitar() override {
        cout << "Guitar destructor called for string count " << *stringCount << endl;
        delete stringCount;
        delete electric;
    }

    void play() const override {
        cout << "Playing guitar with " << *stringCount << " strings and made of " << material << endl;
    }

    void tune() const override {
        cout << "Tuning the guitar made of " << material << " with " << *stringCount << " strings." << endl;
    }
};

int main() {
    // Static Object
    cout << "Static Object:\n";
    Instrument* staticGuitar = new Guitar("Guitar", "Wood", 6, true);

    staticGuitar->play();
    staticGuitar->tune();
    delete staticGuitar;

    // Dynamic Objects
    cout << "\nDynamic Objects:\n";
    Instrument* dynamicGuitar1 = new Guitar("Electric Guitar", "Metal", 7, true);
    Instrument* dynamicGuitar2 = new Guitar("Acoustic Guitar", "Wood", 6, false);

    dynamicGuitar1->play();
    dynamicGuitar1->tune();

    dynamicGuitar2->play();
    dynamicGuitar2->tune();

    delete dynamicGuitar1;
    delete dynamicGuitar2;

    return 0;
}
