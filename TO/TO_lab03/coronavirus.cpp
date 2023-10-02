#include <iostream>

// Clase base para Transmisibilidad
class Transmisibilidad {
public:
    void mostrarTransmisibilidad() {
        std::cout << "Esta cepa tiene alta transmisibilidad." << std::endl;
    }
};

// Clase base para Resistencia a Vacunas
class ResistenciaVacunas {
public:
    void mostrarResistencia() {
        std::cout << "Esta cepa muestra resistencia a ciertas vacunas." << std::endl;
    }
};

// Clase Cepa que hereda de Transmisibilidad y Resistencia a Vacunas
class Cepa : public Transmisibilidad, public ResistenciaVacunas {
    std::string nombre;

public:
    Cepa(std::string n) : nombre(n) {}

    void mostrarNombre() {
        std::cout << "Cepa: " << nombre << std::endl;
    }
};

int main() {
    Cepa varianteDelta("Delta");
    varianteDelta.mostrarNombre();
    varianteDelta.mostrarTransmisibilidad();
    varianteDelta.mostrarResistencia();

    return 0;
}
