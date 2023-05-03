#include "Libraries.h"
//#include "App.h"
#include "Viajes.h"
#include "Encomienda.h"

int menu();
void opcionViajes(Viajes *TurismoDiasViajes);
void opcionEncomiendas(Encomienda *encomienda);

int main()
{
    Viajes* TurismoDiasViajes = new Viajes();
    Encomienda* encomienda = new Encomienda();

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
            opcionEncomiendas(encomienda);
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

void opcionEncomiendas(Encomienda *encomienda)
{

    char opcionPersonaEmpresa = 'F';
    int opcionSeleccionada;

    while (opcionPersonaEmpresa != 'P' && opcionPersonaEmpresa != 'p' && opcionPersonaEmpresa != 'E' && opcionPersonaEmpresa != 'e' )
    {
        cout << "Esta usted solicitando este servicio como Persona (P) o como Empresa (E): ";
        cin >> opcionPersonaEmpresa;
        if (opcionPersonaEmpresa != 'P' && opcionPersonaEmpresa != 'p' && opcionPersonaEmpresa != 'E' && opcionPersonaEmpresa != 'e')
        {
            cout << "Por favor, ingrese 'P' para persona y 'E' para empresa" << endl;
        }
    }

    opcionSeleccionada = encomienda->menuEncomiendas();

    do{
        switch (opcionSeleccionada)
            {
            case 1:

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