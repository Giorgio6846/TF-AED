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
    void informacionPasajeros();
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
    while (listaPasajeros != NULL)
    {
        cout << "Los datos de la persona son: \n";
        cout << "Nombres: " << listaPasajeros->elemento->getNombre() << "\n";
        cout << "Apellidos: " << listaPasajeros->elemento->getApellido() << "\n";
        cout << "Edad: " << listaPasajeros->elemento->getEdad() << "\n";
        cout << "Documento: ";

        switch (listaPasajeros->elemento->getTipoDocumento())
        {
        case 1:
            cout << "DNI " << listaPasajeros->elemento->getDocumento() << "\n";
            break;
        case 2:
            cout << "Carnet de Extranjeria " << listaPasajeros->elemento->getDocumento() << "\n";
            break;
        case 3:
            cout << "Pasaporte " << listaPasajeros->elemento->getDocumento() << "\n";
            break;
        default:
            break;
        }
    cout << "Presione cualquier tecla para volver al menu de encomiendas!" << endl;
    cont();
    }
}