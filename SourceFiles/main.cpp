#include "Libraries.h"
//#include "App.h"
#include "Viajes.h"

int menu();
void opcionViajes(Viajes *TurismoDiasViajes);
void opcionEncomiendas();

int main()
{
    Viajes* TurismoDiasViajes = new Viajes();

    switch (menu())
    {
        case 1:
            opcionViajes(TurismoDiasViajes);
            break;
        case 2:
            opcionEncomiendas();
            break;
        default:
            break;
    }
}

void opcionViajes(Viajes *TurismoDiasViajes)
{
    TurismoDiasViajes->selecionarDestino();
}

void opcionEncomiendas()
{
    char opcionViajeEncomienda, opcionPersonaEmpresa;

    cout << "Esta usted solicitando este servicio como Persona (P) o como Empresa (E): ";
    cin >> opcionPersonaEmpresa;

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

        if (!(opcionSelecionada >= 1 && opcionSelecionada <= 3)) cout << "La opcion seleccionada es incorrecta.\n";
    } while (!(opcionSelecionada >= 1 && opcionSelecionada <= 3));

    return opcionSelecionada;
}