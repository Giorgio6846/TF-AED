#pragma once 
#include "Libraries.h"

class Rutas
{
private:
    
    vector<string> origen{"Lima", "Chimbote", "Trujillo", "Pacasmayo", "Cajamarca", "Chepen", "Chiclayo", "Piura", "Jaen", "Cajabamba", "Moyobamba", "Tarapoto"};
    vector<string> destino{"Lima", "Chimbote", "Trujillo", "Pacasmayo", "Cajamarca", "Chepen", "Chiclayo", "Piura", "Jaen", "Cajabamba", "Moyobamba", "Tarapoto"};

    bool rutas[12][12] = {
        /*Lima*/      {0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0},
        /*Chimbote*/  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*Trujillo*/  {1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        /*Pacasmayo*/ {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        /*Cajamarca*/ {0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1},
        /*Chepen*/    {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        /*Chiclayo*/  {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
        /*Piura*/     {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        /*Jaen*/      {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        /*Cajabamba*/ {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
        /*Moyobamba*/ {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        /*Tarapoto*/  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    };

public:
    Rutas(/* args */){};
    ~Rutas(){};

    int selecionarDestino(int );
    int selecionarOrigen();

    int getSizeDestino() { return destino.size(); }
    string getDestino(int N) { return destino.at(N); }

    int getSizeOrigen() { return origen.size(); }
    string getOrigen(int N) { return origen.at(N); }

    bool getRuta(int pos, int N){return rutas[pos][N]; }
};

// Selecciona el Destino
int Rutas ::selecionarDestino(int Origen)
{
    // Convierte de la matriz a un vector con los destinos disponibles para esa ruta especifica
    vector<string> DestinosDisponibles;
    for (int i = 0; i < getSizeDestino(); i++)
    {
        if (getRuta(Origen, i))
        {
            DestinosDisponibles.push_back(getDestino(i));
        }
    }
    // El usuario seleciona el destino a base del 1 a la cantidad de destinos disponibles
    int opcionElegida;
    do
    {
        cout << "\nElija, de la lista, los destinos disponibles para " << getOrigen(Origen) << " del (1 - " << getSizeDestino() << " o 0 para regresar al menu de viajes) \n";
        for (int i = 0; i < DestinosDisponibles.size(); i++)
        {
            cout << i + 1 << " " << DestinosDisponibles.at(i) << "\n";
        }
        cin >> opcionElegida;
    if (!(opcionElegida >= 0 && opcionElegida <= DestinosDisponibles.size()))
    {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "La opcion seleccionada es incorrecta.";
        getch();
    }
        
    } while (!(opcionElegida >= 0 && opcionElegida <= DestinosDisponibles.size()));
    opcionElegida--;

    // Se traduce de la opcion elegida al nombre de destino estandarizado
    for (int i = 0; i < getSizeDestino(); i++)
    {
        if (getDestino(i) == DestinosDisponibles.at(opcionElegida))
        {
            opcionElegida = i;
            break;
        }
    }
    return opcionElegida;
}

//Selecciona el Origen
int Rutas ::selecionarOrigen()
{
    int opcionElegida;
    do
    {
        cout << "\nElija, de la lista, el origen del viaje (1 - " << getSizeOrigen() << " o 0 para regresar al menu de viajes) \n";
        for (size_t i = 0; i < getSizeOrigen(); i++)
        {
            cout << i + 1 << " " << getOrigen(i) << "\n";
        }
        cin >> opcionElegida;
        if (!(opcionElegida >= 0 && opcionElegida <= 13))
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "La opcion seleccionada es incorrecta.";
            getch();
        }
    } while (!(opcionElegida >= 0 && opcionElegida <= 13));
    return opcionElegida - 1;
}