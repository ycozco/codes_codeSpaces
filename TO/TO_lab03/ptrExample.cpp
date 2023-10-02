#include <iostream>
#include <memory>

class Persona {
public:
    Persona(std::string n) : nombre(n) {}
    void saludar() {
        std::cout << "Hola, soy " << nombre << std::endl;
    }

private:
    std::string nombre;
};

int main() {
    // Uso de unique_ptr
    std::unique_ptr<Persona> personaPtr = std::make_unique<Persona>("Juan");
    personaPtr->saludar();

    // Uso de shared_ptr
    std::shared_ptr<Persona> personaCompartida1 = std::make_shared<Persona>("María");
    std::shared_ptr<Persona> personaCompartida2 = personaCompartida1; // Compartiendo el recurso
    personaCompartida1->saludar();
    personaCompartida2->saludar();

    // Uso de weak_ptr
    std::shared_ptr<Persona> personaCompartida3 = std::make_shared<Persona>("Pedro");
    std::weak_ptr<Persona> personaDebil = personaCompartida3; // Creación de un weak_ptr
    if (auto lockedPtr = personaDebil.lock()) {
        // Verificar si el objeto aún existe antes de acceder a él
        lockedPtr->saludar();
    } else {
        std::cout << "La persona referenciada por el weak_ptr ya no existe." << std::endl;
    }

    return 0;
}
