#include "../Rutas.h"
#include "Viaje.h"
#include "../Algoritmos/NodoArbolComplexv2.h"
#include "../Algoritmos/Grafo.h"

/*
Lima, Chimbote, Trujillo, Pacasmayo, Cajamarca, Chepen, Chiclayo, Piura, Jaen, Cajabamba, Moyobamba, Tarapoto
*/

class ControladorViajes : public Rutas
{
private:
    NodoLista<Viaje> *listaCompras = NULL;
    NodoLista<Bus> *listaBuses = NULL;
    Grafo<NodoLista<Bus>, int, Bus> *grafoRutas = new Grafo<NodoLista<Bus>, int, Bus>;

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

    void generacionGrafo();
    
    void funciontmp();
};

ControladorViajes::ControladorViajes(/* args */)
{
}

ControladorViajes::~ControladorViajes()
{
}

void ControladorViajes ::escrituraArchivo()
{
}

void ControladorViajes ::reservaViaje()
{
    int Origen, Destino, cantidadUsuarios;
    string ruta;

    Origen = Rutas ::selecionarOrigen();
    Destino = Rutas ::selecionarDestino(Origen);
    cantidadUsuarios = seleccionarCantidadUsuarios(getOrigen(Origen), getDestino(Destino));

    Viaje *NuevaReserva = new Viaje(Origen, Destino, cantidadUsuarios);
    NuevaReserva->agregarPasajero();

    listaCompras->push(&listaCompras, NuevaReserva);

    cout << "\n Ha selecionado el origen " << Rutas ::getOrigen(Origen);
    cout << "\n Ha selecionado el destino " << Rutas ::getDestino(Destino);
    cout << "\n";
}

int ControladorViajes ::seleccionarCantidadUsuarios(string Origen, string Destino)
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

void ControladorViajes ::reservaBusquedaViajes()
{
    int contador;
    // listaCompras->elemento->informacionPasajeros();
    if (listaCompras != NULL)
    {
        while (listaCompras != NULL)
        {
            cout << "Encomienda numero " << contador << endl;
            listaCompras->getElemento(listaCompras)->informacionPasajeros();
            contador++;
            listaCompras = listaCompras->nextElemento(listaCompras);
        }
    }
    else
    {
        cout << "No existen encomiendas por el momento!" << endl;
    }
}

int ControladorViajes ::menuViajes()
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

void ControladorViajes :: generacionGrafo()
{
    for (int i = 0; i < getSizeLugares(); i++)
    {
        grafoRutas -> agregarVertice(i);
    }

    for (int i = 0; i < getSizeOrigen(); i++)
    {
        for (int j = 0; j < getSizeDestino(); j++)
        {
            if (accesoRutaDisponible(i,j) != 0)
            {
                NodoLista<Bus> *listaBus = NULL;
                for (int k = 0; k <= 3; k++)
                {
                    Bus *tmp = new Bus(i, j, accesoTiempoRuta(i,j));
                    listaBus->push(&listaBus,tmp);
                }
                grafoRutas->agregarArcoVertice(i,j,accesoTiempoRuta(i,j),listaBus);
            }
        }
    }
}



void ControladorViajes :: funciontmp()
{
    grafoRutas->RutaFinal(1, 10, 10);
}