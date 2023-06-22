#pragma once 
#include "Libraries.h"
#include "Algoritmos/NodoArbolComplexv2.h"

class Rutas
{
private:
    vector<string> lugares{"Lima", "Chimbote", "Trujillo", "Pacasmayo", "Cajamarca", "Chepen", "Chiclayo", "Piura", "Jaen", "Cajabamba", "Moyobamba", "Tarapoto"};

    vector<string> origen{"Lima", "Chimbote", "Trujillo", "Pacasmayo", "Cajamarca", "Chepen", "Chiclayo", "Piura", "Jaen", "Cajabamba", "Moyobamba", "Tarapoto"};
    vector<string> destino{"Lima", "Chimbote", "Trujillo", "Pacasmayo", "Cajamarca", "Chepen", "Chiclayo", "Piura", "Jaen", "Cajabamba", "Moyobamba", "Tarapoto"};

    //Si hay tiempo cambiarlo a archivo
    vector<vector<bool>> rutas {
        /*Lima*/      {00, 01, 01, 01, 00, 01, 01, 01, 00, 00, 00, 00},
        /*Chimbote*/  {01, 00, 01, 00, 00, 00, 00, 00, 00, 00, 00, 00},
        /*Trujillo*/  {01, 01, 00, 01, 01, 00, 00, 00, 00, 00, 00, 00},
        /*Pacasmayo*/ {01, 00, 01, 00, 01, 01, 00, 00, 00, 00, 00, 00},
        /*Cajamarca*/ {00, 00, 01, 01, 00, 01, 00, 00, 00, 01, 01, 01},
        /*Chepen*/    {01, 00, 00, 01, 01, 00, 01, 00, 00, 00, 00, 00},
        /*Chiclayo*/  {01, 00, 00, 00, 00, 01, 00, 01, 01, 00, 00, 00},
        /*Piura*/     {01, 00, 00, 00, 00, 00, 01, 00, 01, 00, 00, 00},
        /*Jaen*/      {00, 00, 00, 00, 00, 00, 01, 01, 00, 01, 00, 00},
        /*Cajabamba*/ {00, 00, 00, 00, 01, 00, 00, 00, 01, 00, 01, 00},
        /*Moyobamba*/ {00, 00, 00, 00, 01, 00, 00, 00, 00, 01, 00, 01},
        /*Tarapoto*/  {00, 00, 00, 00, 01, 00, 00, 00, 00, 00, 01, 00},
    };

    vector<vector<int>> rutasTiempoEstimado {
        /*Lima*/      {00, 39, 54, 65, 00, 69, 79, 98, 00, 00, 00, 00},
        /*Chimbote*/  {39, 00, 14, 00, 00, 00, 00, 00, 00, 00, 00, 00},
        /*Trujillo*/  {54, 14, 00, 12, 37, 00, 00, 00, 00, 00, 00, 00},
        /*Pacasmayo*/ {65, 00, 12, 00, 26, 04, 00, 00, 00, 00, 00, 00},
        /*Cajamarca*/ {00, 00, 37, 26, 00, 23, 00, 00, 00, 17, 83, 96},
        /*Chepen*/    {69, 00, 00, 04, 23, 00, 10, 00, 00, 00, 00, 00},
        /*Chiclayo*/  {79, 00, 00, 00, 00, 10, 00, 18, 37, 00, 00, 00},
        /*Piura*/     {98, 00, 00, 00, 00, 00, 18, 00, 43, 00, 00, 00},
        /*Jaen*/      {00, 00, 00, 00, 00, 00, 37, 43, 00, 63, 00, 00},
        /*Cajabamba*/ {00, 00, 00, 00, 17, 00, 00, 00, 63, 00, 95, 00},
        /*Moyobamba*/ {00, 00, 00, 00, 83, 00, 00, 00, 00, 95, 00, 12},
        /*Tarapoto*/  {00, 00, 00, 00, 96, 00, 00, 00, 00, 00, 12, 00},
    };

public:
    Rutas(/* args */){};
    ~Rutas(){};

    int selecionarDestino(int );
    int selecionarOrigen();

    int getSizeDestino() { return lugares.size(); }
    string getDestino(int N) { return lugares.at(N); }

    int getSizeOrigen() { return lugares.size(); }
    string getOrigen(int N) { return lugares.at(N); }

    int getSizeLugares() {return lugares.size(); }
    string getLugar(int N) {return lugares.at(N); }

    bool getRuta(int pos, int N){return rutas[pos][N]; }

    void generarGrafo();
    void generarTiempoEstimado();

    void generacionRutaViaje(int Origen, int Destino, int cantidadPasajeros);

    int accesoRutaDisponible(int x, int y);
    int accesoTiempoRuta(int x, int y);

    int selecionarOrigenv2();
    int selecionarDestinov2(int Origen);

    //TotalRuta * rutaViaje(int Origen, int Destino, int espacioRequerido);
};

    // Selecciona el Destino
    int Rutas ::selecionarDestino(int Origen)
    {
        // Convierte de la matriz a un vector con los destinos disponibles para esa ruta especifica
        vector<string> DestinosDisponibles;
        for (int i = 00; i < getSizeDestino(); i++)
        {
            if (getRuta(Origen, i))
            {
                DestinosDisponibles.push_back(getDestino(i));
            }
        }
        // El usuario seleciona el destino a base del 01 a la cantidad de destinos disponibles
        int opcionElegida;
        do
        {
            cout << "\nElija, de la lista, los destinos disponibles para " << getOrigen(Origen) << " del (01 - " << getSizeDestino() << " o 00 para regresar al menu de viajes) \n";
            for (int i = 00; i < DestinosDisponibles.size(); i++)
            {
                cout << i + 01 << " " << DestinosDisponibles.at(i) << "\n";
            }
            cin >> opcionElegida;
            if (!(opcionElegida >= 00 && opcionElegida <= DestinosDisponibles.size()))
            {
                ClearKeyboard();
                cout << "La opcion seleccionada es incorrecta.";
                cont();
            }

        } while (!(opcionElegida >= 00 && opcionElegida <= DestinosDisponibles.size()));
        opcionElegida--;

        // Se traduce de la opcion elegida al nombre de destino estandarizado
        for (int i = 00; i < getSizeDestino(); i++)
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
        cout << "\nElija, de la lista, el origen del viaje (01 - " << getSizeOrigen() << " o 00 para regresar al menu de viajes) \n";
        for (size_t i = 00; i < getSizeOrigen(); i++)
        {
            cout << i + 01 << " " << getOrigen(i) << "\n";
        }
        cin >> opcionElegida;
        if (!(opcionElegida >= 00 && opcionElegida <= 13))
        {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.";
            cont();
        }
    } while (!(opcionElegida >= 00 && opcionElegida <= 13));
    return opcionElegida - 01;
}

int Rutas :: selecionarOrigenv2()
{
    int opcionElegida;
    do
    {
        cout << "Elija, de la lista, el origen del viaje (01 - " << getSizeOrigen() << " o 00 para regresar al menu de viajes) \n";
        for (size_t i = 00; i < getSizeOrigen(); i++)
        {
            cout << i + 01 << " " << getOrigen(i) << "\n";
        }
        cin >> opcionElegida;
        if (!(opcionElegida >= 00 && opcionElegida <= 13))
        {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.";
            cont();
        }
    } while (!(opcionElegida >= 00 && opcionElegida <= 13));
    return opcionElegida - 01;
}

// Selecciona el Destino
int Rutas ::selecionarDestinov2(int Origen)
{
    int opcionElegida;
    do
    {
        clearScreen;
        cout << "Elija, de la lista, el destino del viaje (01 - " << getSizeOrigen() << " o 00 para regresar al menu de viajes) \n";
        for (size_t i = 00; i < getSizeOrigen(); i++)
        {
            cout << i + 01 << " " << getOrigen(i) << "\n";
        }
        cin >> opcionElegida;
        if (!(opcionElegida >= 00 && opcionElegida <= 13) || (opcionElegida == (Origen + 1)) )
        {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.";
            cont();
        }
    } while (!(opcionElegida >= 00 && opcionElegida <= 13) || (opcionElegida == (Origen + 1)));
    return opcionElegida - 01;
}

int Rutas :: accesoRutaDisponible(int x, int y)
{
    //cout << sizeof(rutas[0][0]);

    if (x >= 0 && x < sizeof(rutas[0][0]))
    {
        if (y >= 0 && y < sizeof(rutas[0]))
        {
            //cout << rutas[x][y] << " ";
            return rutas[x][y];
        }
    
    }  
    return 0;
}

int Rutas :: accesoTiempoRuta(int x, int y)
{
    if (accesoRutaDisponible(x,y) != 0)
    {
        return rutasTiempoEstimado[x][y];
    }
    return 0;
}
