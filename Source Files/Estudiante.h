#include "Libraries.h"

class Estudiante
{
public:
    string nombre, apellido;
    int edad;
    char tipoDocumento;
public:
    Estudiante(string nombre, string apellido, int edad, char tipoDocumento){
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> edad = edad;
    this -> tipoDocumento = tipoDocumento;
    };
    ~Estudiante(){};

    void setNombre(string nombre){this->nombre = nombre;}
    void setApellido(string apellido){this->apellido = apellido;}
    void setEdad(int edad){this->edad = edad;}
    void setTipoDocumento(char tipoDocumento){this->tipoDocumento = tipoDocumento;}

    string getNombre(){return this->nombre;}
    string getApellido(){return this->apellido;}
    int getEdad(){return this->edad;}
    char getTipoDocumento(){return this->tipoDocumento;}
};

