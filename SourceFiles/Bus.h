#pragma once
#include "Libraries.h"
#include "Persona.h"
#include "Algoritmos/HashTable.h"

struct Asiento
{
    string ubicacion;
    char clase;
};

/*

El bus va a tiene 60 asientos
Estos son categorizados por clase: A, B y C
Dependiendo de la clase el costo del precio es mayor
1  2  3  4  5  6  7  8  9  10
A  A  B  B  B  B  C  C  C  C
A  A  B  B  B  B  C  C  C  C
A  A  B  B  B  B  C  C  C  C
A  A  B  B  B  B  C  C  C  C
A  A  B  B  B  B  C  C  C  C
A  A  B  B  B  B  C  C  C  C
*/

class Bus
{
private:
    vector<vector<Asiento>> distribucionAsientos;
    int Origen;
    int Destino;
    
    int tiempoEstimado;

    int columnaAsiento = 6;
    int filaAsiento = 10;

public:
    Bus(int Origen, int Destino)
    {
        this -> Origen = Origen;
        this -> Destino = Destino;
    }
    ~Bus(){}

    void mostrarAsientos();
    void generarAsientos();
    void generarBus();
};

void Bus::mostrarAsientos()
{
    for(int i = 0; i < distribucionAsientos.size(); i++)
    {
        for(int j = 0; j < distribucionAsientos[i].size();j++)
        {
            cout << distribucionAsientos[i][j].ubicacion << " " << distribucionAsientos[i][j].clase << " ";
        }
        cout << "\n";
    }
}

void Bus::generarAsientos()
{
    string ubicacion;
    char clase;

    for (int i = 0; i < filaAsiento; i++)
    {
        vector<Asiento> Fil;
        for (int j = 0; j < columnaAsiento; j++)
        {
            ubicacion = char(65 + j) + to_string(i+1);
            clase = char((i <= 2) * 0 + (i >= 3 && i <= 6) * 1 + (i >= 7) * 2 + 65);

            Fil.push_back(Asiento());
            Fil[j].clase = clase;
            Fil[j].ubicacion = ubicacion;
        }
        distribucionAsientos.push_back(Fil);
    }
}