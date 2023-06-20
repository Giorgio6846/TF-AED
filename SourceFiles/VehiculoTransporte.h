#pragma once 
#include "Libraries.h"
#include "Persona.h"
#include "Algoritmos/HashTable.h"

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

class VehiculoTransporte
{
private:
    int Origen;
    int Destino;

    int tiempoEstimado;

    int cantidadDisponible;

public:
    VehiculoTransporte(int Origen = 0, int Destino = 0, int tiempoEstimado = 0)
    {
        this -> Origen = Origen;
        this->Destino = Destino;
        this->tiempoEstimado = tiempoEstimado;
    }
    ~VehiculoTransporte(){}

    int getOrigen(){ return this-> Origen; }
    void setOrigen(int Origen) {  this->Origen = Origen; }

    int getDestino(){ return this -> Destino; }
    void setDestino(int Destino) { this->Destino = Destino; }

    int gettiempoEstimado(){ return this-> tiempoEstimado; }
    void settiempoEstimado(int tiempoEstimado){ this -> tiempoEstimado = tiempoEstimado; }

    int getCantidadDisponible(){ return this -> cantidadDisponible; }
    void setCantidadDisponible(int cantidadDisponible) {  this->cantidadDisponible = cantidadDisponible; }
};

/*

Cambiar a HashTable
Este puede ser organizado a base del asiento
Por ejemplo: A10 este es organizado por A y despues en la posicion A es organizado de menor a mayor

*/

struct Asiento
{
    string ubicacion;
    char claseAsiento;
    Persona * usuarioPersona;
};

class Bus : public VehiculoTransporte
{
private:
        vector<vector<Asiento>> distribucionAsientos;

        int columnaAsiento = 10;
        int filaAsiento = 6;

        //Bus asientos
        HashTable<Asiento> busAsientos;

    public:
        Bus(int Origen, int Destino, int tiempoEstimado) : VehiculoTransporte(Origen, Destino, tiempoEstimado)
        {
        setOrigen(Origen);
        setDestino(Destino);
        settiempoEstimado(tiempoEstimado);
        setCantidadDisponible(columnaAsiento * filaAsiento);

        busAsientos.setSize(columnaAsiento);
        generarAsientos();
    }
    ~Bus(){}

    void mostrarAsientos();
    void generarAsientos();

    //Terminar
    void agregarPasajero()
    {

        setCantidadDisponible(getCantidadDisponible() - 1);
    }
};

void Bus::mostrarAsientos()
{
    /*
    for (int i = 0; i < distribucionAsientos.size(); i++)
    {
        for (int j = 0; j < distribucionAsientos[i].size(); j++)
        {
            cout << distribucionAsientos[i][j].ubicacion << " " << distribucionAsientos[i][j].clase << " ";
        }
        cout << "\n";
    }
    */
}

void Bus::generarAsientos()
{

    for (int i = 0; i < filaAsiento; i++)
    {
        for (int j = 0; j < columnaAsiento; j++)
        {
            Asiento * asientoTMP = new Asiento;
            asientoTMP-> ubicacion = char(65 + j) + to_string(i + 1);
            asientoTMP->claseAsiento = char((i <= 2) * 0 + (i >= 3 && i <= 6) * 1 + (i >= 7) * 2 + 65);

            busAsientos.insert(asientoTMP->ubicacion, asientoTMP);
        }
    }
    
/*
    string ubicacion;
    char clase;

    for (int i = 0; i < filaAsiento; i++)
    {
        vector<Asiento> Fil;
        for (int j = 0; j < columnaAsiento; j++)
        {
            ubicacion = char(65 + j) + to_string(i + 1);
            clase = char((i <= 2) * 0 + (i >= 3 && i <= 6) * 1 + (i >= 7) * 2 + 65);

            Fil.push_back(Asiento());
            Fil[j].clase = clase;
            Fil[j].ubicacion = ubicacion;
        }
        distribucionAsientos.push_back(Fil);
    }
*/
}

class Camion : public VehiculoTransporte
{
private:
    /* data */
public:
    Camion(int Origen, int Destino, int tiempoEstimado) : VehiculoTransporte(Origen,  Destino, tiempoEstimado)
    {
        setOrigen(Origen);
        setDestino(Destino);
        settiempoEstimado(tiempoEstimado);
    }
    ~Camion(){}
};


