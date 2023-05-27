#include "Libraries.h"
#include "Persona.h"
#include "NodoLista.h"

class ControladorViajes
{
private:
    int cantidadPasajeros;
    NodoLista<Persona> *listaPasajeros = NULL;
    int codigoO, codigoD;

public:
    ControladorViajes(int codigoO, int codigoD, int cantidadPasajeros);
    ~ControladorViajes();
    void agregarPasajero();
    void informacionPasajero();
};

ControladorViajes::ControladorViajes(int codigoO, int codigoD, int cantidadPasajeros)
{
    this->codigoO = codigoO;
    this->codigoD = codigoD;
    this->cantidadPasajeros = cantidadPasajeros;
}

ControladorViajes::~ControladorViajes()
{
}

void ControladorViajes ::informacionPasajero()
{
}

void ControladorViajes ::agregarPasajero()
{
    for (int i = 0; i <= cantidadPasajeros - 1; i++)
    {
        Persona *cliente = new Persona();
        cliente->typePersona();

        listaPasajeros->insertarElementoLista(&listaPasajeros, cliente);
    }
}