#include "../Libraries.h"
#include "../Persona.h"
#include "../Algoritmos/NodoLista.h"

class Viaje
{
private:
    int cantidadPasajeros;
    NodoLista<Persona> *listaPasajeros = NULL;
    int codigoO, codigoD;

public:
    Viaje(int codigoO, int codigoD, int cantidadPasajeros);
    ~Viaje();

    void agregarPasajero();
    void informacionPasajero();
};

Viaje::Viaje(int codigoO, int codigoD, int cantidadPasajeros)
{
    this->codigoO = codigoO;
    this->codigoD = codigoD;
    this->cantidadPasajeros = cantidadPasajeros;
}

Viaje::~Viaje()
{
}

void Viaje :: agregarPasajero()
{
    for (int i = 0; i <= cantidadPasajeros - 1; i++)
    {
        Persona *cliente = new Persona();

        #if RAD == 0
        cliente->typePersona();
        #elif RAD == 1
        cliente->randomPersona();
        #endif

        listaPasajeros->insertarElementoLista(&listaPasajeros, cliente);
    }
}

void Viaje :: informacionPasajero()
{

}