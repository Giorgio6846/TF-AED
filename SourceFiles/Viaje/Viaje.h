#include "../Libraries.h"
#include "../Persona.h"
#include "../Algoritmos/NodoLista.h"
#include "../VehiculoTransporte.h"
#include "../Algoritmos/Grafo.h"

struct precioPersona
{
    int Precio;
    Persona * personaViaje = new Persona;
};

class Viaje
{
private:
    int cantidadPasajeros;
    NodoLista<precioPersona> *listaPasajeros = NULL;
    TotalRuta<Bus> *TRtmp;

    int codigoO,codigoD;

public:
    Viaje(int codigoO, int codigoD, int cantidadPasajeros, TotalRuta<Bus> *busTmp);
    ~Viaje();

    void agregarPasajero();
    void setRutaBus(TotalRuta<Bus> *busTmp) { TRtmp = busTmp; }
};

Viaje::Viaje(int codigoO, int codigoD, int cantidadPasajeros, TotalRuta<Bus> *busTmp)
{
    this->codigoO = codigoO;
    this->codigoD = codigoD;
    this->cantidadPasajeros = cantidadPasajeros;

    TRtmp = busTmp;    
}

Viaje::~Viaje()
{
}

void Viaje :: agregarPasajero()
{
    for (int i = 0; i <= cantidadPasajeros - 1; i++)
    {
        precioPersona * personaCosto = new precioPersona();
        
        #if RAD == 0
        personaCosto->personaViaje->typePersona();
        #elif RAD == 1
        personaCosto->personaViaje->randomPersona();
        #endif

        listaPasajeros->push(&listaPasajeros, personaCosto);
    }
}