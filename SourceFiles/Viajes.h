#include "Rutas.h"
#include "ControladorViajes.h"

    /*
    Lima, Chimbote, Trujillo, Pacasmayo, Cajamarca, Chepen, Chiclayo, Piura, Jaen, Cajabamba, Moyobamba, Tarapoto
    */
class Viajes : public Rutas
{
private:
    vector<ControladorViajes> Pasajes;

public:
    Viajes(){};
    ~Viajes(){};

    // Funciones usuario

    int seleccionarCantidadUsuarios(string, string);

    // Opcion seleccion
    int menuViajes();
    void reservaViajes();
    void reservaBusquedaViajes();

    void escrituraArchivo();
};

void Viajes ::escrituraArchivo()
{
}

void Viajes ::reservaViajes()
{
    int Origen, Destino, cantidadUsuarios;

    Origen = Rutas :: selecionarOrigen();
    Destino = Rutas :: selecionarDestino(Origen);
    cantidadUsuarios = seleccionarCantidadUsuarios(getOrigen(Origen), getDestino(Destino));

    cout << "\n Ha selecionado el origen " << Rutas :: getOrigen(Origen);
    cout << "\n Ha selecionado el destino " << Rutas :: getDestino(Destino);
    cout << "\n";
}

int Viajes ::seleccionarCantidadUsuarios(string Origen, string Destino)
{
    int cantidadUsuarios;

    do
    {
        cout << "\n Cuantos pasajeros son en el grupo de " + Origen + " para " + Destino << "\n";
        cin >> cantidadUsuarios;
    } while (!(cantidadUsuarios >= 1 && cantidadUsuarios <= 50));

    return cantidadUsuarios;
}

void Viajes ::reservaBusquedaViajes()
{
}

int Viajes ::menuViajes()
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
            cout << "La opcion seleccionada es incorrecta.\n";
    } while (!(opcionSelecionada >= 1 && opcionSelecionada <= 4));

    return opcionSelecionada;
}