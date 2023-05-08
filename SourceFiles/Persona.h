#include "Libraries.h"
#pragma once

class Persona
{
public:
    string nombre;
    string apellido;
    int edad;

    //0 = Ninguno, 1 DNI, 2 Carnet Extranjeria, 3 Pasaporte
    int tipoDocumento;

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
    
    Persona()
    {
        this->nombre = "";
        this -> apellido = "";
        this -> edad = NULL;
        this -> tipoDocumento = NULL;
    }

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

