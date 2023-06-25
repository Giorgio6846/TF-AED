#include "Libraries.h"
#pragma once

class Persona
{
public:
    string nombre, apellido;
    int edad, contador; // contador para generar un ranking basado en cuantos pedidos ha hecho el cliente
    // 0 = Ninguno, 1 DNI, 2 Carnet Extranjeria, 3 Pasaporte
    int tipoDocumento;
    string documento;

public:
    Persona(string nombre, string apellido, int edad, char tipoDocumento)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->edad = edad;
        this->tipoDocumento = tipoDocumento;
        this->contador = 0;
    };

    Persona(string nombre, string apellido, int edad, char tipoDocumento, string documento)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->edad = edad;
        this->tipoDocumento = tipoDocumento;
        this->contador = 0;
        this->documento = documento;
    };

    Persona()
    {
        this->nombre = "";
        this->apellido = "";
        this->edad = 0;
        this->tipoDocumento = 0;
        this->documento = "";
    }

    ~Persona(){};

    void setNombre(string nombre) { this->nombre = nombre; }
    void setApellido(string apellido) { this->apellido = apellido; }
    void setEdad(int edad) { this->edad = edad; }
    void setTipoDocumentoyDocumento(char tipoDocumento) { this->tipoDocumento = tipoDocumento; }
    void setDocumento(string documento){this->documento = documento;}

    void typeNombre();
    void typeApellido();
    void typeEdad();
    void typeTipoDocumentoyDocumento();

    string getNombre() { return this->nombre; }
    string getApellido() { return this->apellido; }
    int getEdad() { return this->edad; }
    char getTipoDocumento() { return this->tipoDocumento; }
    string getDocumento() { return this->documento; }
    int getContador() { return this->contador; }
    string getKey() { return this->nombre + this->apellido + this->documento; }

    void typePersona();
    void randomPersona();
    void informacionPersona();
};

void Persona ::typeNombre()
{
    string nombreP;
    bool val;
    do
    {
        cout << "Ingrese su nombre: ";
        cin >> nombreP;
        for (int i = 0; i < nombreP.length(); i++)
        {
            if (!(isdigit(nombreP[i])))
            {
                val = true;
            }
            else
            {
                val = false;
            }
        }
        if (val == false)
        {
            cout << "El nombre ingresado es invalido.\n";
        }
    } while (val == false);

    this->nombre = nombreP;
}

void Persona ::typeApellido()
{
    string apellidosP;
    bool val;

    do
    {
        cout << "Ingrese su apellido paterno: ";
        cin >> apellidosP;
        for (int i = 0; i < apellidosP.length(); i++)
        {
            if (!(isdigit(apellidosP[i])))
            {
                val = true;
            }
            else
            {
                val = false;
            }
        }
        if (val == false)
        {
            cout << "El apellido ingresado es invalido.\n";
        }
    } while (val == false);

    /*
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
    */

    this->apellido = apellidosP;
}

void Persona ::typeEdad()
{
    int edadP;

    do
    {
        cout << "Edad: ";
        cin >> edadP;
        if (!(edadP >= 1 && edadP <= 120))
        {
            ClearKeyboard();
            cout << "La edad no es valida";
        }
    } while (!(edadP >= 1 && edadP <= 120));

    this->edad = edadP;
}

void Persona ::typeTipoDocumentoyDocumento()
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

    this->tipoDocumento = tipoDocumentoP;

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
            if (!val)
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
            if (!val)
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
            if (!val)
            {
                ClearKeyboard();
                cout << "Pasaporte Incorrecto. \n";
            }
        } while (!val);
        break;
    default:
        break;
    }

    this->documento = documentoP;
}

void Persona ::typePersona()
{
    clearScreen;
    cout << "Ingrese los datos de la persona: \n";
    ClearKeyboard();
    typeNombre();
    ClearKeyboard();
    typeApellido();
    ClearKeyboard();
    typeEdad();
    ClearKeyboard();
    typeTipoDocumentoyDocumento();

    clearScreen;
    cout << "Los datos de la persona son: \n";
    cout << "Nombre: " << this->nombre << "\n";
    cout << "Apellido: " << this->apellido << "\n";
    cout << "Edad: " << this->edad << "\n";
    cout << "Tipo de documento: ";

    switch (this->tipoDocumento)
    {
    case 1:
        cout << "DNI"
             << "\n";
        cout << "Nro: " << this->documento << "\n";
        break;
    case 2:
        cout << "Carnet de Extranjeria "
             << "\n";
        cout << "Nro: " << this->documento << "\n";
        break;
    case 3:
        cout << "Pasaporte"
             << "\n";
        cout << "Nro: " << this->documento << "\n";
        break;
    default:
        break;
    }

    int verDat;
    int camDat;

    do
    {
        cout << "Desea cambiar algun dato. (1: Si, 2: No): ";
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
                clearScreen;
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

void Persona ::randomPersona()
{
    string pathApellidos = "InformacionDatos/apellidos-es.txt";
    string pathNombres = "InformacionDatos/nombres-propios-es.txt";

    string cantidadNombres;
    string cantidadApellidos;

    int i = 0;
    int datTemp1, datTemp2;
    string temp;

    ifstream nombresFile(pathNombres, ios::in);
    getline(nombresFile, cantidadNombres);

    datTemp1 = rand() % stoi(cantidadNombres);
    datTemp2 = rand() % stoi(cantidadNombres);

    this->nombre = "";
    i = 0;

    do
    {
        getline(nombresFile, temp);

        if (i == datTemp1 || i == datTemp2)
        {
            this->nombre = temp + " " + this->nombre;
        }
        i++;
    } while ((i <= datTemp1) || (i <= datTemp2));

    nombresFile.close();

    ifstream apellidosFile(pathApellidos, ios::in);
    getline(apellidosFile, cantidadApellidos);

    datTemp1 = rand() % stoi(cantidadApellidos);
    datTemp2 = rand() % stoi(cantidadApellidos);

    this->apellido = "";
    i = 0;

    do
    {
        getline(apellidosFile, temp);

        if (i == datTemp1 || i == datTemp2)
        {
            this->apellido = temp + " " + this->apellido;
        }
        i++;
    } while ((i <= datTemp1) || (i <= datTemp2));

    apellidosFile.close();

    this->edad = 0;
    this->edad = rand() % 80 + 18;

    this->tipoDocumento = 0;
    this->tipoDocumento = rand() % 3 + 1;

    this->documento = "";
    switch (this->tipoDocumento)
    {
    case 1:
        for (int i = 1; i <= 8; i++)
        {
            this->documento = to_string(randDigit((i == 1) * 1)) + this->documento;
        }
        break;

    case 2:
        for (int i = 1; i <= 9; i++)
        {
            this->documento = to_string(randDigit((i == 1) * 1)) + this->documento;
        }
        break;

    case 3:
        for (int i = 1; i <= 8; i++)
        {
            this->documento = to_string(randDigit((i == 1) * 1)) + this->documento;
        }
        break;

    default:
        break;
    }
}

void Persona ::informacionPersona()
{
    clearScreen;
    cout << "Los datos de la persona son: \n";
    cout << "Nombre: " << this->nombre << "\n";
    cout << "Apellido: " << this->apellido << "\n";
    cout << "Edad: " << this->edad << "\n";


    switch (this->tipoDocumento)
    {
    case 1:
        cout << "DNI: " << this->documento << "\n";
        break;
    case 2:
        cout << "Carnet de Extranjeria "
             << "\n";
        cout << this->documento << "\n";
        break;
    case 3:
        cout << "Pasaporte"
             << "\n";
        cout << this->documento << "\n";
        break;
    default:
        break;
    }
}