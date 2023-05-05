//#include "App.h"
#include "Libraries.h"
#include "Viajes.h"
#include "ControladorEncomiendas.h"
#include "NodoLista.h"
#include "Encomienda.h"
#include "Persona.h"

int menu();
void opcionViajes(Viajes *TurismoDiasViajes);
void opcionEncomienda(ControladorEncomiendas *contEncomienda, NodoLista * listaClientes);

int main()
{
    NodoLista * listaClientes = NULL;
    Viajes* TurismoDiasViajes = new Viajes();
    //Objeto que administra el menú de encomiendas
    ControladorEncomiendas * contEncomienda = new ControladorEncomiendas();

    //Rutas *rutas = new Rutas();

    int opcionElegida;

    do
    {
        opcionElegida = menu();

        switch (opcionElegida)
        {
        case 1:
            clearScreen;
            opcionViajes(TurismoDiasViajes);
            break;
        case 2:
            clearScreen;
            opcionEncomienda(contEncomienda, listaClientes);
            break;
        default:
            cout << "Gracias por elegir nuestra app! :)";
            break;
        }
    } while (opcionElegida != 3);
}

void opcionViajes(Viajes *TurismoDiasViajes)
{
    int opcionSelecionada;
    do
    {
        opcionSelecionada = TurismoDiasViajes->menuViajes();

        switch (opcionSelecionada)
        {
        case 1:
            TurismoDiasViajes->reservaViajes();
            break;
        case 2:
            TurismoDiasViajes->reservaBusquedaViajes();
            break;
        case 4:
            TurismoDiasViajes->escrituraArchivo();
            break;
        default:
            break;
        }
    } while (opcionSelecionada != 3);
    clearScreen;
}

void opcionEncomienda(ControladorEncomiendas *contEncomienda, NodoLista * listaClientes)
{
    int esPrint;
    int opcionSelecionada;
    do
    {
        opcionSelecionada = contEncomienda->menuEncomienda();

        switch (opcionSelecionada)
        {
        case 1:
            //Usa como parametro el objeto persona que devuelve la función "almacenarInfoCliente"
            listaClientes->insertarElementoLista(&listaClientes,contEncomienda->almacenarInfoCliente(listaClientes));
            esPrint = contEncomienda->printClientesEncomiendas(listaClientes);
            if (esPrint == 1){listaClientes->printClientes(listaClientes);}
            //TurismoDiasEncomienda->reservaEncomienda();
            break;
        /*case 2:
            
            break;*/
        /*
        case 4:
            TurismoDiasViajes->escrituraArchivo();
            break;
        */
        default:
            break;
        }
    } while (opcionSelecionada != 3);
    
}

    /*
    void opcionEncomiendas(ControladorEncomiendas *contEncomienda, Rutas* rutas, NodoLista * listaClientes)
    {

        char opcionPersonaEmpresa = 'F';
        int opcionSeleccionada;

        while (opcionPersonaEmpresa != 'P' && opcionPersonaEmpresa != 'p' && opcionPersonaEmpresa != 'E' && opcionPersonaEmpresa != 'e' )
        {
            cout << "Esta usted solicitando este servicio como Persona (P) o como Empresa (E): ";
            cin >> opcionPersonaEmpresa;
            opcionPersonaEmpresa = toupper(opcionPersonaEmpresa);
            if (opcionPersonaEmpresa != 'P' && opcionPersonaEmpresa != 'E')
            {
                cout << "Por favor, ingrese 'P' para persona y 'E' para empresa" << endl;
            }
        }
        //Almacena la información del cliente
        contEncomienda->informacionCliente(opcionPersonaEmpresa);
        //Almacenamos que opción del menú ha elegido el usuario
        opcionSeleccionada = contEncomienda->menuEncomiendas();

        do{
            int rutaElegida;
            switch (opcionSeleccionada)
                {
                case 1:
                    rutaElegida = rutas->selecionarOrigen();
                    rutas->selecionarDestino(rutaElegida);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    break;
                }
        } while (opcionSeleccionada != 3);

        cout << "Los destinos disponibles para encomiendas son: ";
        //TurismoDias->printDestinosEncomiendas();

        //cout << "\nElija, de la lista, el destino de la encomienda (1 - " << TurismoDias->getEncomiendasN() << ")";
        //cin>>opcionDestino;
    }
    */

    int menu()
{
    int opcionSelecionada;
    do
    {
        cout << "Selecione la opcion." << "\n";
        cout << "1. Viajes" << "\n";
        cout << "2. Encomiendas" << "\n";
        cout << "3. Salir" << "\n";

        cin >> opcionSelecionada;

        if (!(opcionSelecionada >= 1 && opcionSelecionada <= 4)) cout << "La opcion seleccionada es incorrecta.\n";
    } while (!(opcionSelecionada >= 1 && opcionSelecionada <= 4));

    return opcionSelecionada;
}

