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

    };
    ~Estudiante(){};
};

