#include "Rutas.h"
#include "Viaje.h"

/*
Lima, Chimbote, Trujillo, Pacasmayo, Cajamarca, Chepen, Chiclayo, Piura, Jaen, Cajabamba, Moyobamba, Tarapoto
*/

class ControladorViajes : public Rutas
{
private:
    NodoLista<Viaje> *listaCompras = NULL;

public:
    ControladorViajes(/* args */);
    ~ControladorViajes();

    // Funciones usuario
    int seleccionarCantidadUsuarios(string, string);

    // Opcion seleccion
    int menuViajes();
    void reservaViaje();
    void reservaBusquedaViajes();

    void escrituraArchivo();
};

ControladorViajes::ControladorViajes(/* args */)
{
}

ControladorViajes::~ControladorViajes()
{
}

void ControladorViajes :: escrituraArchivo()
{
}

void ControladorViajes :: reservaViaje()
{
    int Origen, Destino, cantidadUsuarios;

    Origen = Rutas ::selecionarOrigen();
    Destino = Rutas ::selecionarDestino(Origen);
    cantidadUsuarios = seleccionarCantidadUsuarios(getOrigen(Origen), getDestino(Destino));

    Viaje *NuevaReserva = new Viaje(Origen, Destino, cantidadUsuarios);
    NuevaReserva->agregarPasajero();

    listaCompras->insertarElementoLista(&listaCompras, NuevaReserva);

    cout << "\n Ha selecionado el origen " << Rutas ::getOrigen(Origen);
    cout << "\n Ha selecionado el destino " << Rutas ::getDestino(Destino);
    cout << "\n";
}

int ControladorViajes :: seleccionarCantidadUsuarios(string Origen, string Destino)
{
    int cantidadUsuarios;

    do
    {
        cout << "\n Cuantos pasajeros son en el grupo de " + Origen + " con destino a  " + Destino << "\n";
        cin >> cantidadUsuarios;
        if (!(cantidadUsuarios >= 1 && cantidadUsuarios <= 50))
        {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.\n";
        }
    } while (!(cantidadUsuarios >= 1 && cantidadUsuarios <= 50));
    return cantidadUsuarios;
}

void ControladorViajes :: reservaBusquedaViajes()
{
}

int ControladorViajes :: menuViajes()
{
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