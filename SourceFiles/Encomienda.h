#include "Libraries.h"
#include "Rutas.h"

#include "ControladorEncomiendas.h"

class Encomienda
{
private:
    NodoLista<Persona> *listaClientes = NULL;
    int esPrint;
    //Objeto que administra el menú de encomiendas
    ControladorEncomiendas *contEncomienda = new ControladorEncomiendas();

public:
    Encomienda(/* args */){};
    ~Encomienda(){};

    // Opcion seleccion
    int menuEncomienda();
    void agendarEncomienda();
    void eliminarEncomienda();
    void reservaBusquedaEncomienda();
    void printClientes(NodoLista<Persona> *lista);
};

int Encomienda::menuEncomienda()
{
    int opcionSelecionada;
    do
    {
        clearScreen;
        cout << "Selecione la opcion. \n";
        cout << "1. Agendar una encomienda \n";
        cout << "2. Eliminar una encomienda \n";
        cout << "3. Regresar al menu principal \n";
        
        cin >> opcionSelecionada;

        if (!(opcionSelecionada >= 1 && opcionSelecionada <= 3))
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "La opcion seleccionada es incorrecta.";
            cont();
        }
        else
            return opcionSelecionada;
    } while (opcionSelecionada != 3);
    return opcionSelecionada;
}

void Encomienda::agendarEncomienda()
{
    listaClientes->insertarElementoLista(&listaClientes, contEncomienda->almacenarInfoCliente(listaClientes));
    esPrint = contEncomienda->printClientesEncomiendas(listaClientes);
    if (esPrint == 1)
    {
        printClientes(listaClientes);
    }
}

void Encomienda::eliminarEncomienda()
{


}

void Encomienda::printClientes(NodoLista<Persona> *lista)
{
    int op;
    // Mientras no se llegue al final de lista, mostrar los datos de los clientes almacenados
    clearScreen;
    while (lista != NULL)
    {
        cout << "Nombre: " << lista->elemento->getNombre() << endl;
        cout << "Apellido: " << lista->elemento->getApellido() << endl;
        cout << "Edad: " << lista->elemento->getEdad() << endl;
        cout <<endl;
        lista = lista->next;
    }
    cout << "Presione cualquier tecla para volver al menu de encomiendas!" << endl;
    cont();
}