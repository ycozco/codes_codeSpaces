// Componentes básicos del automóvil como clases
class Door {
    string color;
public:
    Door(const string& color) : color(color) {}
    // Métodos para configurar y obtener información de la puerta...
};

class Engine {
    // Atributos del motor y métodos...
};

// Otros componentes como Wheel, Seat, Mirror...

// Clase para representar el automóvil completo
class Car {
    vector<unique_ptr<Item>> parts;
public:
    // Métodos para agregar componentes al automóvil
    void AddPart(unique_ptr<Item> part) {
        parts.push_back(move(part));
    }
    // Método para obtener la configuración del automóvil...
};

// Interfaz Builder
class ICarBuilder {
public:
    virtual void BuildDoor(string color) = 0;
    virtual void BuildEngine() = 0;
    // Otros métodos para construir partes...
    virtual unique_ptr<Car> GetCar() = 0;
    virtual ~ICarBuilder() {}
};

// Implementación concreta del Builder
class CarBuilder : public ICarBuilder {
    unique_ptr<Car> car;
public:
    CarBuilder() { car = make_unique<Car>(); }
    void BuildDoor(string color) override { car->AddPart(make_unique<Door>(color)); }
    void BuildEngine() override { /*...*/ }
    // Implementación de otros métodos...
    unique_ptr<Car> GetCar() override { return move(car); }
};

// Director que usa el Builder para crear el automóvil
class CarDirector {
public:
    unique_ptr<Car> ConstructCar(ICarBuilder& builder, const map<string, string>& features) {
        builder.BuildEngine(); // Todos los coches tienen motor, por ejemplo
        if (features.count("doorColor")) {
            builder.BuildDoor(features.at("doorColor"));
        }
        // Añadir más partes basadas en las características...
        return builder.GetCar();
    }
};
