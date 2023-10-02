#include <iostream>  // Para std::cout
#include <string>    // Para std::string
// Clase base: Persona
class Persona {
protected:
    std::string nombre;
    int edad;
public:
    Persona(std::string n, int e) : nombre(n), edad(e) {}
    void mostrarDatos() {
        std::cout << "Nombre: " << nombre << "\nEdad: " << edad << std::endl;
    }
};

// Clase derivada: Arquitecto
class Arquitecto : public Persona {
private:
    std::string proyectoActual;
public:
    Arquitecto(std::string n, int e, std::string proyecto) : Persona(n, e), proyectoActual(proyecto) {}
    void mostrarProyecto() {
        std::cout << "Proyecto actual: " << proyectoActual << std::endl;
    }
};

// Clase derivada: Doctor
class Doctor : public Persona {
private:
    std::string especialidad;
public:
    Doctor(std::string n, int e, std::string esp) : Persona(n, e), especialidad(esp) {}
    void mostrarEspecialidad() {
        std::cout << "Especialidad: " << especialidad << std::endl;
    }
};

// Clase derivada: Enfermera
class Enfermera : public Persona {
private:
    std::string hospital;
public:
    Enfermera(std::string n, int e, std::string hosp) : Persona(n, e), hospital(hosp) {}
    void mostrarHospital() {
        std::cout << "Hospital: " << hospital << std::endl;
    }
};

// Clase derivada: Bombero
class Bombero : public Persona {
private:
    std::string estacion;
public:
    Bombero(std::string n, int e, std::string est) : Persona(n, e), estacion(est) {}
    void mostrarEstacion() {
        std::cout << "Estación: " << estacion << std::endl;
    }
};

int main() {

    Arquitecto arquitecto("Juan", 35, "Diseño del nuevo edificio");
    Doctor doctor("María", 42, "Cardiología");
    Enfermera enfermera("Laura", 28, "Hospital General");
    Bombero bombero("Carlos", 30, "Estación 5");

    std::cout << "Datos del Arquitecto:\n";
    arquitecto.mostrarDatos();
    arquitecto.mostrarProyecto();

    std::cout << "\nDatos del Doctor:\n";
    doctor.mostrarDatos();
    doctor.mostrarEspecialidad();

    std::cout << "\nDatos de la Enfermera:\n";
    enfermera.mostrarDatos();
    enfermera.mostrarHospital();

    std::cout << "\nDatos del Bombero:\n";
    bombero.mostrarDatos();
    bombero.mostrarEstacion();

    return 0;
}
