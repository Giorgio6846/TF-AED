#include "Libraries.h"

#include "Origen.h"
#include "Destino.h"
#include "ControladorViajes.h"
/*
Lima, Chimbote, Trujillo, Pacasmayo, Cajamarca, Chepen, Chiclayo, Piura, Jaen, Cajabamba, Moyobamba, Tarapoto
*/

class Viajes : public Origen, public Destino
{
private:
    bool rutas[12][12] = {
        /*Lima*/      {0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0},
        /*Chimbote*/  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*Trujillo*/  {1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        /*Pacasmayo*/ {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        /*Cajamarca*/ {0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1},
        /*Chepen*/    {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        /*Chiclayo*/  {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
        /*Piura*/     {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        /*Jaen*/      {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        /*Cajabamba*/ {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
        /*Moyobamba*/ {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        /*Tarapoto*/  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    };

    vector<ControladorViajes> Pasajes;

public:
    Viajes(){};
    ~Viajes(){};

    int menuViajes();
    int selecionarDestino(int *Origen);
    int selecionarOrigen();
    
    void reservaViajes();
    void reservaBusquedaViajes();
    void escrituraArchivo();
};

void Viajes :: escrituraArchivo()
{

}

int Viajes ::selecionarDestino(int *Origen)
{
    //Convierte de la matriz a un vector con los destinos disponibles para esa ruta especifica
    vector<string> DestinosDisponibles;
    for (int i = 0; i < getSizeDestino(); i++)
    {
        if (rutas[*Origen][i])
        {
            DestinosDisponibles.push_back(getDestino(i));
        }
    }

    //El usuario seleciona el destino a base del 1 a la cantidad de destinos disponibles
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
     
    //Se traduce de la opcion elegida al nombre de destino estandarizado
    for (int i = 0; i < getSizeDestino(); i++)
    {
        if(getDestino(i) == DestinosDisponibles.at(opcionElegida))
        {
            opcionElegida = i;
            break;
        } 
    }
    
    return opcionElegida;
}   

int Viajes :: selecionarOrigen()
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

    return opcionElegida-1;
}

void Viajes :: reservaViajes()
{
    int Origen, Destino;

    Origen = selecionarOrigen();

    Destino = selecionarDestino(&Origen);

    cout << "\n" << "Ha selecionado el origen " << getOrigen(Origen);
    cout << "\n" << "Ha selecionado el destino " << getDestino(Destino);
}

void Viajes ::reservaBusquedaViajes()
{

}

int Viajes :: menuViajes()
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