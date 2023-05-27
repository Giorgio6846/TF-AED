#include "Libraries.h"
#pragma once

class Persona
{
public:
    string nombre, apellido;
    int edad;

    //0 = Ninguno, 1 DNI, 2 Carnet Extranjeria, 3 Pasaporte
    int tipoDocumento;

    string documento;

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
        this -> documento = "";
    }

    ~Persona(){};

    void setNombre(string nombre){this->nombre = nombre;}
    void setApellido(string apellido){this->apellido = apellido;}
    void setEdad(int edad){this->edad = edad;}
    void setTipoDocumentoyDocumento(char tipoDocumento){this->tipoDocumento = tipoDocumento;}

    void typeNombre();
    void typeApellido();
    void typeEdad();
    void typeTipoDocumentoyDocumento();

    string getNombre(){return this->nombre;}
    string getApellido(){return this->apellido;}
    int getEdad(){return this->edad;}
    char getTipoDocumento(){return this->tipoDocumento;}
    string getDocumento() { return this->documento; }

    void typePersona();
};

    void Persona :: typeNombre()
    {
        string nombreP;
        bool val;
        do
        {
            cout << "Nombres: ";
            val = 1;
            for (int i = 0; i < nombre.size(); i++)
            {
                cout << "Nombres: ";
                cin >> nombreP;
                if (!( ( (int(toupper(nombre[i])) >= 65 && int(toupper(nombre[i])) <= 90) || (int(nombre[i]) >= 48 && int(nombre[i]) <= 57) ) || int(nombre[i]) == 32))
                {
                    ClearKeyboard();
                    val = 0;
                }
            }
            if (val == 0)
            {
                cout << "Los nombres ingresados son incorrectos. Solo se aceptan letras y numeros";
            }
            
        } while (val == 0);

        this->nombre = nombreP;
    }

    void Persona :: typeApellido()
    {
        string apellidosP;
        bool val;
        do
        {
            cout << "Apellido: ";
            val = 1;
            for (int i = 0; i < nombre.size(); i++)
            {
                cout << "Apellido: ";
                cin >> apellidosP;
                if (!(((int(toupper(nombre[i])) >= 65 && int(toupper(nombre[i])) <= 90) || (int(nombre[i]) >= 48 && int(nombre[i]) <= 57)) || int(nombre[i]) == 32))
                {
                    ClearKeyboard();
                    val = 0;
                }
            }
            if (val == 0)
            {
                cout << "Los apellidos ingresados son incorrectos. Solo se aceptan letras y numeros";
            }

        } while (val == 0);

        this -> apellido = apellidosP;
    }

    void Persona :: typeEdad()
    {
        int edadP;

        do
        {
            cout << "Edad: ";
            cin >> edadP;
            if(!(edad >= 0 && edad <= 120))
            {
                ClearKeyboard();
                cout << "La edad no es valida";
            }
        } while (!(edad >= 0 && edad <= 120));

        this->edad = edadP;
    }

    void Persona :: typeTipoDocumentoyDocumento()
    {
        int tipoDocumentoP;
        string documentoP;
        bool val;
        do
        {
            cout << "Tipo de documento (1: DNI, 2: Carnet de Extranjeria & 3: Pasaporte): ";
            cin >> tipoDocumentoP;

            if (!(tipoDocumentoP >= 1 && tipoDocumentoP <= 3))
            {
                ClearKeyboard();
                cout << "Opcion errorea. Ingrese de nuevo el tipo de documento. \n";
            }
        } while (!(tipoDocumentoP >= 1 && tipoDocumentoP <= 3));

        this -> tipoDocumento = tipoDocumentoP;

        switch (tipoDocumentoP)
        {
        case 1:
            do
            {
                cout << "Ingrese el DNI del pasajero: ";
                cin >> documentoP;
                val = documentoP.size() == 8;
                if (val)
                {
                    for (int i = 0; i < documentoP.size(); i++)
                    {
                        if (!(int(documentoP[i]) >= 48 && int(documentoP[i]) <= 57))
                        {
                            val = 0;
                        }
                    }
                }
                if(!val)
                {
                    ClearKeyboard();
                    cout << "DNI Incorrecto.\n";
                }
            } while (!val);
            break;
        case 2:
            do
            {
                cout << "Ingrese el Carnet de Extranjeria del pasajero: ";
                cin >> documentoP;
                val = documentoP.size() == 9;
                if (val)
                {
                    for (int i = 0; i < documentoP.size(); i++)
                    {
                        if (!(int(documentoP[i]) >= 48 && int(documentoP[i]) <= 57))
                        {
                            val = 0;
                        }
                    }
                }
                if(!val)
                {
                    ClearKeyboard();
                    cout << "Carnet de Extranjeria Incorrecta. \n";
                }
            } while (!val);
            break;
        case 3:
            do
            {
                cout << "Ingrese el Pasaporte del pasajero: ";
                cin >> documentoP;
                val = documentoP.size() == 8;
                if (val)
                {
                    for (int i = 0; i < documentoP.size(); i++)
                    {
                        if (!(int(documentoP[i]) >= 48 && int(documentoP[i]) <= 57))
                        {
                            val = 0;
                        }
                    }
                }
                if(!val)
                {
                    ClearKeyboard();
                    cout << "Pasaporte Incorrecto. \n";
                }
            } while (!val);
            break;
        default:
            break;
        }

        this-> documento = documentoP;

    }


void Persona :: typePersona()
{
    cout << "Ingrese los datos de la persona: \n";
    ClearKeyboard();
    typeNombre();
    ClearKeyboard();
    typeApellido();
    ClearKeyboard();
    typeEdad();
    ClearKeyboard();
    typeTipoDocumentoyDocumento();

    cout << "Los datos de la persona son: \n";
    cout << "Nombres: " << this->nombre << "\n";
    cout << "Apellidos: " << this->apellido << "\n";
    cout << "Edad: " << this->edad << "\n";
    cout << "Documento: ";
    
    switch (this->tipoDocumento)
    {
    case 1:
        cout << "DNI " << this->documento << "\n";
        break;
    case 2:
        cout << "Carnet de Extranjeria " << this->documento << "\n";
        break;
    case 3:
        cout << "Pasaporte " << this->documento << "\n";
        break;
    default:
        break;
    }

    int verDat;
    int camDat;

    do
    {
        cout << "Desea cambiar algun dato. (1: Si, 2: No)";
        cin >> verDat;

        if (!(verDat >= 1 && verDat <= 2))
        {
                ClearKeyboard();
                cout << "La opcion ingresada es incorrecta. \n";
        }

        if (verDat == 1)
        {
            do
            {
                cout << "Selecione el dato a cambiar. \n";
                
                cout << "1. Nombre \n";
                cout << "2. Apellido \n";
                cout << "3. Edad \n";
                cout << "4. Tipo de documento y documento \n";

                cin >> camDat;
                if (!(camDat >= 1 && camDat <= 4))
                {
                    ClearKeyboard();
                    cout << "La opcion ingresada es incorrecta. \n";
                }
            } while (!(camDat >= 1 && camDat <= 4));

            switch (camDat)
            {
            case 1:
                typeNombre();
                break;
            case 2:
                typeApellido();
                break;
            case 3:
                typeEdad();
                break;
            case 4:
                typeTipoDocumentoyDocumento();
                break;

            default:
                break;
            }
        }
    } while (!(verDat >= 1 && verDat <= 2));
}