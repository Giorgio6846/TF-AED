#include "Libraries.h"
#pragma once

class Persona
{
public:
    string nombre, apellido;
    int edad;

    //0 = Ninguno, 1 DNI, 2 Carnet Extranjeria, 3 Pasaporte
    int tipoDocumento;

    string DNI, CarnetExtranjeria, Pasaporte;

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
        this -> nombre = "";
        this -> apellido = "";
        this -> edad = 0;
        this -> tipoDocumento = 0;
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

    void setPersona();
};

void Persona :: setPersona()
{
    string nombreP, apellidoP;
    int edadP, tipoDocumentoP;
    string DNIP, CarnetExtranjeriaP, PasaporteP;

    cout << "Ingrese los datos del pasajero";
    
    //do
    //{
        cout << "Nombres: ";
        cin >> nombreP;
        /* code */
    //} while (/* condition */);

    //do
    //{
        cout << "Apellidos: ";
        cin >> apellidoP;
        /* code */
    //} while (/* condition */);

    //do
    //{
        cout << "Edad: ";
        cin >> edadP;
        /* code */
    //} while (/* condition */);

    //do
    //{
        cout << "Tipo de documento (1: DNI, 2: Carnet de Extranjeria & 3: Pasaporte): ";
        cin >> tipoDocumentoP;
        /* code */
    //} while (/* condition */);

    switch (tipoDocumentoP)
    {
    case 1:
        //do
        //{
            cout << "Ingrese el DNI del pasajero: ";
            cin >> DNIP;
            /* code */
        //} while (/* condition */);
        
        break;
    case 2:
        //do
        //{
            cout << "Ingrese el Carnet de Extranjeria del pasajero: ";
            cin >> CarnetExtranjeriaP;
            /* code */
        //} while (/* condition */);

        break;
    case 3:
        //do
        //{
            cout << "Ingrese el Pasaporte del pasajero: ";
            cin >> PasaporteP;
            /* code */
        //} while (/* condition */);

        break;
    default:
        break;
    }
}