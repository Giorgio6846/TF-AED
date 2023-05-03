//#include "App.h"
#include "Libraries.h"
#include "Viajes.h"
#include "ControladorEncomiendas.h"
#include "NodoLista.h"

int menu();
void opcionViajes(Viajes *TurismoDiasViajes);
void opcionEncomiendas(ControladorEncomiendas *contEncomienda, Rutas * rutas, NodoLista * listaClientes);

int main()
{
    NodoLista * listaClientes = new NodoLista();
    Viajes* TurismoDiasViajes = new Viajes();
    ControladorEncomiendas * contEncomienda = new ControladorEncomiendas();
    Rutas * rutas = new Rutas();

    int opcionElegida;

    do
    {
        opcionElegida = menu();

        switch (opcionElegida)
        {
        case 1:
            opcionViajes(TurismoDiasViajes);
            break;
        case 2:
            opcionEncomiendas(contEncomienda, rutas, listaClientes);
            break;
        default:
            cout << "Gracias por elegir nuestra app! :)";
            break;
        }
    } while (opcionElegida != 3);
}

void opcionViajes(Viajes *TurismoDiasViajes)
{
    int opcionViajeSelecionada;
    do
    {
        opcionViajeSelecionada = TurismoDiasViajes->menuViajes();

        switch (opcionViajeSelecionada)
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
    } while (opcionViajeSelecionada == 3);
}

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