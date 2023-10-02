#include <iostream>
#include <string>

// Clase base para las cepas
class CepaBase {
public:
    std::string nombre;
    virtual void caracteristicasCepa() const {
        std::cout << "Soy la cepa Base" << std::endl;
    }
    void mostrarCepa() {
        std::cout << nombre << std::endl;
        caracteristicasCepa();
    }
};

// Clases de cepas individuales heredando de la clase base
class CepaOriginal : public CepaBase {
public:
    CepaOriginal() {
        nombre = "Cepa Original";
    }
    void caracteristicasCepa() const override {
        std::cout << "Tambien conocida como tipo salvaje o cepa ancestral, se refiere a la primera variante del virus que se identifico en los primeros casos de COVID-19 en diciembre de 2019 en la ciudad de Wuhan," << std::endl;
    }
};

class CepaD614G : public CepaBase {
public:
    CepaD614G() {
        nombre = "Cepa D614G";
    }
    void caracteristicasCepa() const override {
        std::cout << "Esta mutacion involucra un cambio en el aminoacido en la posicion 614 de la proteina de pico de la espiga del virus, donde el aspartato (D) se reemplaza por glicina (G)" << std::endl;
    }
};

class CepaAlpha : public CepaBase {
public:
    CepaAlpha() {
        nombre = "Cepa Alpha";
    }
    void caracteristicasCepa() const override {
        std::cout << "Tambien conocida como B.1.1.7, ha sido identificada en numerosos paises de todo el mundo" << std::endl;
    }
};

class CepaBeta : public CepaBase {
public:
    CepaBeta() {
        nombre = "Cepa Beta";
    }
    void caracteristicasCepa() const override {
        std::cout << "Tambien conocida como B.1.351 , fue identificada por primera vez en Sudafrica en mayo de 2020" << std::endl;
    }
};

class CepaDelta : public CepaBase {
public:
    CepaDelta() {
        nombre = "Cepa Delta";
    }
    void caracteristicasCepa() const override {
        std::cout << "Tambien conocida como B.1.617.2,  Fue identificada por primera vez en India en octubre de 2020 y desde entonces se ha propagado a nivel mundial" << std::endl;
    }
};

class CepaLambda : public CepaBase {
public:
    CepaLambda() {
        nombre = "Cepa Lambda";
    }
    void caracteristicasCepa() const override {
        std::cout << "Tambien conocida como C.37, Fue identificada por primera vez en Peru en agosto de 2020 y posteriormente se ha propagado a otros países de America del Sur y a nivel global" << std::endl;
    }
};

class CepaOmicrom : public CepaBase {
public:
    CepaOmicrom() {
        nombre = "Cepa Omicrom";
    }
    void caracteristicasCepa() const override {
        std::cout << "nombre cientifico es B.1.1.529. La variante omicron, es mas contagiosa y dificil de identificar, pero menos mortal que otras variantes de la enfermedad." << std::endl;
    }
};

// Clase que hereda múltiples cepas
class Coronavirus : public CepaOriginal, public CepaD614G, public CepaAlpha, public CepaBeta, public CepaDelta, public CepaLambda, public CepaOmicrom {
public:
};

int main() {
    Coronavirus covid19;
    
    covid19.CepaOriginal::mostrarCepa();
    covid19.CepaD614G::mostrarCepa();
    covid19.CepaAlpha::mostrarCepa();
    covid19.CepaBeta::mostrarCepa();
    covid19.CepaDelta::mostrarCepa();
    covid19.CepaLambda::mostrarCepa();
    covid19.CepaOmicrom::mostrarCepa();
    return 0;
}
