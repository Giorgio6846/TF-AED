#pragma once

#include "../Rutas.h"

#include "Viaje.h"
#include "../ControladorDataSet.h"

class ControladorViajes : public ControladorDataSet
{
private:
public:
    ControladorViajes();
    ~ControladorViajes();

    // Opcion seleccion
    int menuViajes();
    void reservaViaje();
    void reservaBusquedaViajes();

    //Generacion de grafo
    void generacionGrafo();
};

ControladorViajes::ControladorViajes(/* args */)
{
}

ControladorViajes::~ControladorViajes()
{
}

void ControladorViajes ::reservaViaje()
{
    int Origen = Rutas :: selecionarOrigen();
    if (Origen == -1 )  return;

    int Destino = selecionarDestino(Origen);
    if (Destino == -1)  return;

    TotalRuta<Bus> *TRtmp = grafoRutasV->rutaFinal(Origen, Destino,1);
    Viaje * nuevaReserva = new Viaje(Origen, Destino, TRtmp);

    nuevaReserva -> agregarPasajero();
    nuevaReserva -> mostrarBuses();
    nuevaReserva -> seleccionarAsientos();

    hashTableViajes.insert(nuevaReserva->pasajero->getKey(),nuevaReserva);
}

void ControladorViajes ::reservaBusquedaViajes()
{
   if (hashTableViajes.isEmpty())
   {
       cout << "No hay encomiendas registradas!" << endl;
       cont();
   }
   else
   {
       clearScreen;
       string codigo;
       cout << "Ingrese su DNI" << endl;
       cin >> codigo;
       clearScreen;
       hashTableViajes.buscarViaje(codigo);
   }
}

int ControladorViajes ::menuViajes()
{
    clearScreen;
    int opcionSelecionada;
    do
    {
        cout << "Selecione la opcion. \n";
        cout << "1. Reservar su viaje \n";
        cout << "2. Buscar una reserva \n";
        cout << "3. Regresar al menu principal \n";
        cin >> opcionSelecionada;

        if (!(opcionSelecionada >= 1 && opcionSelecionada <= 4))
        {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.\n";
        }
    } while (!(opcionSelecionada >= 1 && opcionSelecionada <= 4));
    return opcionSelecionada;
}