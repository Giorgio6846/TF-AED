#include "Libraries.h"

class Persona
{
public:
    string nombre;
    string apellido;
    int edad;
    char tipoDocumento;

    string DNI;
    string CarnetExtranjeria;
    string Pasaporte;

public:
    Persona(string nombre, string apellido, int edad, char tipoDocumento)
    {
        this -> nombre = nombre;
        this -> apellido = apellido;
        this -> edad = edad;
        this -> tipoDocumento = tipoDocumento;
    };
    
    ~Persona(){};

    void setNombre(string nombre){this->nombre = nombre;}
    void setApellido(string apellido){this->apellido = apellido;}
    void setEdad(int edad){this->edad = edad;}
    void setTipoDocumento(char tipoDocumento){this->tipoDocumento = tipoDocumento;}

    string getNombre(){return this->nombre;}
    string getApellido(){return this->apellido;}
    int getEdad(){return this->edad;}
    char getTipoDocumento(){return this->tipoDocumento;}
};

