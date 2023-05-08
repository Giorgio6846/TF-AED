#include "Libraries.h"
#include "Rutas.h"

#include "ControladorEncomiendas.h"

class Encomienda
{
private:
    NodoLista * listaClientes = NULL;
    int esPrint;
    //Objeto que administra el menú de encomiendas
    ControladorEncomiendas *contEncomienda = new ControladorEncomiendas();

public:
    Encomienda(/* args */){};
    ~Encomienda(){};

    // Opcion seleccion
    int menuEncomienda();
    void agendarEncomienda();
    void reservaBusquedaEncomienda();
};

int Encomienda::menuEncomienda()
{
    int opcionSelecionada;
    do
    {
        cout << "Selecione la opcion. \n";
        cout << "1. Agendar una encomienda \n";
        cout << "2. Eliminar una encomienda \n";
        cout << "3. Regresar al menu principal \n";

        cin >> opcionSelecionada;

        if (!(opcionSelecionada >= 1 && opcionSelecionada <= 4))
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "La opcion seleccionada es incorrecta.\n";
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
        listaClientes->printClientes(listaClientes);
    }
}
