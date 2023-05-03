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
    int selecionarDestino(int *);
    int selecionarOrigen();
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

int Viajes ::selecionarDestino(int *Origen)
{
    // Convierte de la matriz a un vector con los destinos disponibles para esa ruta especifica
    vector<string> DestinosDisponibles;
    for (int i = 0; i < getSizeDestino(); i++)
    {
        if (getRuta(*Origen, i))
        {
            DestinosDisponibles.push_back(getDestino(i));
        }
    }
    // El usuario seleciona el destino a base del 1 a la cantidad de destinos disponibles
    int opcionElegida;
    do
    {
        cout << "\nElija, de la lista, los destinos disponibles para " << getOrigen(*Origen) << " del (1 - " << getSizeDestino() << " o 0 para regresar al menu de viajes) \n";
        for (int i = 0; i < DestinosDisponibles.size(); i++)
        {
            cout << i + 1 << " " << DestinosDisponibles.at(i) << "\n";
        }
        cin >> opcionElegida;
    } while (!(opcionElegida >= 0 && opcionElegida <= DestinosDisponibles.size()));
    opcionElegida--;

    // Se traduce de la opcion elegida al nombre de destino estandarizado
    for (int i = 0; i < getSizeDestino(); i++)
    {
        if (getDestino(i) == DestinosDisponibles.at(opcionElegida))
        {
            opcionElegida = i;
            break;
        }
    }

    return opcionElegida;
}
int Viajes ::selecionarOrigen()
{
    int opcionElegida;
    do
    {
        cout << "\nElija, de la lista, el origen del viaje (1 - " << getSizeOrigen() << " o 0 para regresar al menu de viajes) \n";
        for (size_t i = 0; i < getSizeOrigen(); i++)
        {
            cout << i + 1 << " " << getOrigen(i) << "\n";
        }
        cin >> opcionElegida;
    } while (!(opcionElegida >= 0 && opcionElegida <= 13));
    return opcionElegida - 1;
}

void Viajes ::reservaViajes()
{
    int Origen, Destino, cantidadUsuarios;

    Origen = selecionarOrigen();
    Destino = selecionarDestino(&Origen);
    cantidadUsuarios = seleccionarCantidadUsuarios(getOrigen(Origen), getDestino(Destino));

    cout << "\n"
         << "Ha selecionado el origen " << getOrigen(Origen);
    cout << "\n"
         << "Ha selecionado el destino " << getDestino(Destino);
}

int Viajes ::seleccionarCantidadUsuarios(string Origen, string Destino)
{
    int cantidadUsuarios;

    do
    {
        cout << "\n Cuantos pasajeros hay en el grupo de " + Origen + " para " + Destino << "\n";
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