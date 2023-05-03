#include "Libraries.h"
#include "Persona.h"

class ControladorViajes
{
private:
    int cantidadPasajeros;
    vector<Persona> Pasajero;
    int codigoO, codigoD;

public:
    ControladorViajes(int codigoO, int codigoD, int cantidadPasajeros);
    ~ControladorViajes();
    void agregarPasajero(); 
    void informacionPasajero();
};

ControladorViajes::ControladorViajes(int codigoO, int codigoD, int cantidadPasajeros)
{
    this -> codigoO = codigoO;
    this -> codigoD = codigoD;
    this -> cantidadPasajeros = cantidadPasajeros;
}

ControladorViajes::~ControladorViajes()
{
}

void ControladorViajes :: agregarPasajero()
{


    for (int i = 0; i <= cantidadPasajeros; i++)
    {

    }
    
}