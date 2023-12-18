#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase base para todos los items de la laptop
class Item {
public:
    virtual string GetName() = 0;
    virtual float GetPrice() = 0;
    virtual void GetConfiguration() = 0;
};

// Clases derivadas para cada componente específico
class Processor : public Item {
    virtual string GetName() { return "Processor"; };
    virtual float GetPrice() {return 0.0; };
    virtual void GetConfiguration() { cout << "Processor: " << GetName() << endl; };
};

class IntelI5 : public Processor {
    string GetName(){ return "Intel I5"; };
    float GetPrice(){ return 3000.00; };
    void GetConfiguration(){ cout << "1.50 Ghz with turbo, 2 cores, 4 threads, 8MB cache, RAM 4BG - 8 GB" << endl; };
};

class IntelI7 : public Processor {
    string GetName(){return "Intel i7";};
    float GetPrice(){return 4700.00;};
    void getConfiguration(){cout << "1.6 Ghz, up to 1.99 Ghz, 9na Gen, 4 cpres, 8 threads, 16 Mb cache, RAM 16 GB" << endl;};
};

class Drive : public Item {
    virtual string GetName() { return "Drive"; };
    virtual float GetPrice() {return 0.0; };;
    virtual void GetConfiguration() { };
    };

    class HDD : public Drive {
        string GetName(){ return "HDD"; };
        float GetPrice(){ return 150.00; };
        void GetConfiguration(){ cout << "capacity 1 TB, data transfer 1050 mbits/s" << endl; };
    };

    class SSD : public Drive {
        string GetName(){ return "SSD"; };
        float GetPrice(){ return 270.00; };
        void GetConfiguration(){ cout << "capacity 250 GB, data transfer 1800 mbits/s" << endl; };
    };

class DisplayType : public Item {
    virtual string GetName() { return "DisplayType"; };
    virtual float GetPrice() {return 0.0; };
    virtual void GetConfiguration() {} ;
};

    class Normal : public DisplayType {
        string GetName(){ return "Non-touch screen: "; };
        float GetPrice(){ return 195.00; };
        void GetConfiguration(){ cout << "15.6 inches FHD(192 x 1080 pixels), plane, ...etc" << endl; };
    };

// Clase para representar el color de la laptop
class Color : public Item {
    string colorName;
public:
    Color(string name) : colorName(name) {}
    string GetName() override { return colorName; }
    float GetPrice() override { return 20.0; } // Ejemplo de precio por color
    void GetConfiguration() override { cout << "Color: " << colorName << endl; }
};

// Clase para representar la marca de la laptop
class Brand : public Item {
    string brandName;
public:
    Brand(string name) : brandName(name) {}
    string GetName() override { return brandName; }
    float GetPrice() override { return 50.0; } // Ejemplo de precio por marca
    void GetConfiguration() override { cout << "Brand: " << brandName << endl; }
};

class MonitorPlasma : public Item {
    int size;
public:
    MonitorPlasma(int sz) : size(sz) {}
    string GetName() override { return "Monitor Plasma"; }
    float GetPrice() override { return size * 100; } // El precio aumenta con el tamaño
    void GetConfiguration() override { cout << "Monitor Plasma, " << size << " pulgadas" << endl; }
};

class Printer : public Item {
    string type;
public:
    Printer(string t) : type(t) {}
    string GetName() override { return "Printer " + type; }
    float GetPrice() override { return type == "Laser" ? 800.0 : 400.0; }
    void GetConfiguration() override { cout << "Printer Type: " << type << endl; }
};
// Clase Laptop que contiene los componentes
class Laptop {
    vector<Item*> mLaptopParts;
public:
    void AddParts(Item* item) { mLaptopParts.push_back(item); }
    float GetCost() {
        float cost = 0.0;
        for (auto& item : mLaptopParts) {
            cost += item->GetPrice();
        }
        return cost;
    }
    void GetConfiguration() {
        for (auto& item : mLaptopParts) {
            item->GetConfiguration();
        }
    }
    ~Laptop() {
        for (auto& item : mLaptopParts) {
            delete item;
        }
    }
private : 
    vector <Item*> mLaptopParts;
};



// Clase LaptopBuilder que sigue el patrón Builder
class LaptopBuilder {
public:
    Laptop* BuildBasicLaptop() {
        Laptop* laptop = new Laptop();
        laptop->AddParts(new IntelI5());
        laptop->AddParts(new Normal());
        laptop->AddParts(new HDD());
        return laptop;
    }
    Laptop* BuildAdvancedLaptop() {
        Laptop* laptop = new Laptop();
        laptop->AddParts(new IntelI7());
        laptop->AddParts(new Normal());
        laptop->AddParts(new SSD()); 
        return laptop;
    }
    // Métodos para añadir Color, Brand, MonitorPlasma, Printer, etc.
};

/*class IntelI5 : public Processor {
public:
    string GetName() override { return "Intel I5"; }
    float GetPrice() override { return 200.0; }
    void GetConfiguration() override { cout << "Processor: Intel I5" << endl; }
};

class IntelI7 : public Processor {
public:
    string GetName() override { return "Intel I7"; }
    float GetPrice() override { return 300.0; }
    void GetConfiguration() override { cout << "Processor: Intel I7" << endl; }
};*/

int main() {
    LaptopBuilder builder;
    Laptop* myLaptop = builder.BuildBasicLaptop();
    myLaptop->GetConfiguration();
    cout << "Precio: " << myLaptop->GetCost() << endl;
    delete myLaptop; // No olvides liberar la memoria
    return 0;
}
