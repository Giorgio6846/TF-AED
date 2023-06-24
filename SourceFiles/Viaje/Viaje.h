#pragma once
#include "../Libraries.h"

#include "../Persona.h"
#include "../Algoritmos/NodoLista.h"
#include "../VehiculoTransporte.h"
#include "../Algoritmos/Grafo.h"
#include "../Rutas.h"

struct PersonaInf
{
    int Precio;
    Persona *personaViaje = new Persona;
};

class Viaje : public Rutas
{
private:
    int cantidadPasajeros;
    NodoLista<PersonaInf> *listaPasajeros = NULL;
    TotalRuta<Bus> *TRtmp;

    int codigoO,codigoD;

public:
    Viaje(int codigoO, int codigoD, int cantidadPasajeros, TotalRuta<Bus> *busTmp);
    Viaje(int codigoO, int codigoD, NodoLista<PersonaInf> *piTMP, TotalRuta<Bus> *busTmp);
    ~Viaje();

    void agregarPasajero();
    void setRutaBus(TotalRuta<Bus> *busTmp) { TRtmp = busTmp; }
    void mostrarAsientos();
    void seleccionarAsientos();
    void mostrarBuses();
    void AsientoPersona(PersonaInf *pTMP);
};

Viaje::Viaje(int codigoO, int codigoD, int cantidadPasajeros, TotalRuta<Bus> *busTmp)
{
    this->codigoO = codigoO;
    this->codigoD = codigoD;
    this->cantidadPasajeros = cantidadPasajeros;

    TRtmp = busTmp;    
}

Viaje::Viaje(int codigoO, int codigoD, NodoLista<PersonaInf> * piTMP, TotalRuta<Bus> *busTmp)
{
    this->codigoO = codigoO;
    this->codigoD = codigoD;
    this->cantidadPasajeros = cantidadPasajeros;

    TRtmp = busTmp;
}

Viaje::~Viaje()
{
}

void Viaje ::mostrarAsientos()
{
  
}

void Viaje :: agregarPasajero()
{
    for (int i = 0; i <= cantidadPasajeros - 1; i++)
    {
        PersonaInf * personaGrupo = new PersonaInf();

        #if RAD == 0
        personaGrupo->personaViaje->typePersona();
        #elif RAD == 1
        personaGrupo->personaViaje->randomPersona();
        #endif

        listaPasajeros->push(&listaPasajeros, personaGrupo);
    }
}

void Viaje :: mostrarBuses()
{
    cout << "\n";
    cout << "Los buses para su destino son: " << "\n";
    NodoLista<Bus> * nlbusTMP = TRtmp->rutaAlDestino;
    Bus * busTMP = NULL;
    for (int i = 1; nlbusTMP != NULL; nlbusTMP = nlbusTMP->nextElemento(nlbusTMP))
    {
        busTMP = nlbusTMP -> getElemento(nlbusTMP);
        cout << "Bus " << i << ": " << getLugar(busTMP->getOrigen()) << " con destino a " << getLugar(busTMP->getDestino()) << "\n";
        i++;
    }
    cont();
}

void Viaje ::seleccionarAsientos()
{
    NodoLista<Bus> *nlbusTMP = TRtmp->rutaAlDestino;
    Bus *busTMP = NULL;
    for (int i = 1; nlbusTMP != NULL; nlbusTMP = nlbusTMP->nextElemento(nlbusTMP))
    {
        busTMP = nlbusTMP->getElemento(nlbusTMP);
        cout << "Selecione los asientos para el bus " << i << " "<< getLugar(busTMP->getOrigen()) << " con destino a " << getLugar(busTMP->getDestino()) << "\n";
        cout << "Letra A al C: Clase A; D al G: Clase B; y H al J: Clase C\n" << "El precio afecta dependiendo de la clase selecionada\n\n";
        busTMP->mostrarAsientos();

        i++;
    }
}

void Viaje :: AsientoPersona(PersonaInf * pTMP)
{

}