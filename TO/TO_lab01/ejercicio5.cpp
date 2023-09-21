#include <iostream>
#include <string>

class CitaMedica {
private:
    std::string fechaHora;
    std::string tipoAtencion;
    std::string numeroAsegurado;

public:
    CitaMedica(std::string fechaHora, std::string tipoAtencion, std::string numeroAsegurado) {
        setFechaHora(fechaHora);
        setTipoAtencion(tipoAtencion);
        setNumeroAsegurado(numeroAsegurado);
    }

    void setFechaHora(std::string fechaHora) {
        this->fechaHora = fechaHora;
    }

    void setTipoAtencion(std::string tipoAtencion) {
        this->tipoAtencion = tipoAtencion;
    }

    void setNumeroAsegurado(std::string numeroAsegurado) {
        this->numeroAsegurado = numeroAsegurado;
    }

    std::string getFechaHora() const {
        return fechaHora;
    }

    std::string getTipoAtencion() const {
        return tipoAtencion;
    }

    std::string getNumeroAsegurado() const {
        return numeroAsegurado;
    }

    void mostrarDetalles() const {
        std::cout << "Fecha/Hora de la Cita: " << getFechaHora() << std::endl;
        std::cout << "Tipo de Atencion: " << getTipoAtencion() << std::endl;
        std::cout << "Numero del Asegurado: " << getNumeroAsegurado() << std::endl;
    }
};

int main() {
    CitaMedica cita("2023-09-15 14:30", "Consulta General", "1234");
    cita.mostrarDetalles();

    return 0;
}