#pragma once

#include "../Rutas.h"

#include "Viaje.h"
#include "../ControladorDataSet.h"

/*
Lima, Chimbote, Trujillo, Pacasmayo, Cajamarca, Chepen, Chiclayo, Piura, Jaen, Cajabamba, Moyobamba, Tarapoto
*/

class ControladorViajes : public ControladorDataSet
{
private:
    //La lista de compras de los usuarios
    NodoLista<Viaje> *listaCompras = NULL;

public:
    ControladorViajes();
    ~ControladorViajes();

    // Funciones usuario
    int seleccionarCantidadUsuarios(string, string);

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

    int cantidadUsuarios = seleccionarCantidadUsuarios(getLugar(Origen), getLugar(Destino));
    TotalRuta<Bus> *TRtmp = grafoRutasV->rutaFinal(Origen, Destino, cantidadUsuarios);
    Viaje * nuevaReserva = new Viaje(Origen, Destino, cantidadUsuarios, TRtmp);

    nuevaReserva -> agregarPasajero();
    nuevaReserva -> mostrarBuses();
    nuevaReserva -> seleccionarAsientos();
    listaCompras->push(&listaCompras, nuevaReserva);
}

int ControladorViajes ::seleccionarCantidadUsuarios(string Origen, string Destino)
{
    /*
    int cantidadUsuarios;
    do
    {
        clearScreen;
        cout << "Cuantos pasajeros son para la ruta de " + Origen + " con destino a  " + Destino << "\n";
        cin >> cantidadUsuarios;
        if (!(cantidadUsuarios >= 1 && cantidadUsuarios <= 50))
        {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.\n";
        }
    } while (!(cantidadUsuarios >= 1 && cantidadUsuarios <= 50));
    return cantidadUsuarios;
    */
   return 1;
}

void ControladorViajes ::reservaBusquedaViajes()
{
    /*
    int contador;
    // listaCompras->elemento->informacionPasajeros();
    if (listaCompras != NULL)
    {
        while (listaCompras != NULL)
        {
            cout << "Encomienda numero " << contador << endl;
            //listaCompras->getElemento(listaCompras)->informacionPasajeros();
            contador++;
            listaCompras = listaCompras->nextElemento(listaCompras);
        }
    }
    else
    {
        cout << "No existen encomiendas por el momento!" << endl;
    }
    */
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