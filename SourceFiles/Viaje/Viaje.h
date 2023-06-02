#include "../Libraries.h"
#include "../Persona.h"
#include "../Algoritmos/NodoLista.h"
#include "../Bus.h"

class Viaje
{
private:
    int cantidadPasajeros;
    NodoLista<Persona> *listaPasajeros = NULL;
    NodoLista<Bus> *rutaBus = NULL;

    int codigoO, codigoD;
    int Da,Mo,Ye;
    int Ho,Mi;

public:
    Viaje(int codigoO, int codigoD, int cantidadPasajeros);
    ~Viaje();

    void agregarPasajero();
    void informacionPasajeros();
    
    void calculoRuta();
    void generadorBus();    
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

void Viaje :: informacionPasajeros()
{
    int op;
    // Mientras no se llegue al final de lista, mostrar los datos de los clientes almacenados
    clearScreen;

    //listaPasajeros->elemento->informacionPersona();
    //listaPasajeros->next;

    cout << "Presione cualquier tecla para volver al menu de encomiendas!" << endl;
    cont();
}

void Viaje :: calculoRuta()
{

}

void Viaje :: generadorBus()
{
    
}