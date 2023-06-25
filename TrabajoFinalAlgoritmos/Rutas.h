#pragma once 
#include "Libraries.h"

class Rutas
{
private:
    vector<string> lugares{"Lima", "Chimbote", "Trujillo", "Pacasmayo", "Cajamarca", "Chepen", "Chiclayo", "Piura", "Jaen", "Cajabamba", "Moyobamba", "Tarapoto"};

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

    int getSizeLugares() {return lugares.size(); }
    string getLugar(int N) {return lugares.at(N); }

    bool getRuta(int pos, int N){return rutas[pos][N]; }

    int accesoRutaDisponible(int x, int y);
    int accesoTiempoRuta(int x, int y);

    int selecionarOrigen();
    int selecionarDestino(int Origen);

};

int Rutas :: selecionarOrigen()
{
    int opcionElegida;
    do
    {
        clearScreen;
        cout << "Elija, de la lista, el origen del viaje (01 - " << getSizeLugares() << " o 00 para regresar al menu de viajes) \n";
        for (size_t i = 00; i < getSizeLugares(); i++)
        {
            cout << i + 01 << " " << getLugar(i) << "\n";
        }
        cin >> opcionElegida;
        if (!(opcionElegida >= 00 && opcionElegida <= getSizeLugares() + 1))
        {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.";
            cont();
        }
    } while (!(opcionElegida >= 00 && opcionElegida <= getSizeLugares() + 1));
    return opcionElegida - 01;
}

// Selecciona el Destino
int Rutas ::selecionarDestino(int Origen)
{
    int opcionElegida;
    do
    {
        clearScreen;
        cout << "Elija, de la lista, el destino del viaje (01 - " << getSizeLugares() << " o 00 para regresar al menu de viajes) \n";
        for (size_t i = 00; i < getSizeLugares(); i++)
        {
            cout << i + 01 << " " << getLugar(i) << "\n";
        }
        cin >> opcionElegida;
        if (!(opcionElegida >= 00 && opcionElegida <= getSizeLugares() + 1) || (opcionElegida == (Origen + 1)) )
        {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.";
            cont();
        }
    } while (!(opcionElegida >= 00 && opcionElegida <= getSizeLugares() + 1) || (opcionElegida == (Origen + 1)));
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
