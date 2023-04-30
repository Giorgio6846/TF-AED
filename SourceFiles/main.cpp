#include "Libraries.h"
//#include "App.h"
#include "Viajes.h"

int main()
{

//App * TurismoDias = new App();
Viajes*  TurismoDiasViajes = new Viajes();

char opcionViajeEncomienda, opcionPersonaEmpresa;

cout << "Deseas agendar un viaje o una encomienda? Viaje = V / Encomienda = E : ";
cin >> opcionViajeEncomienda;

if (opcionViajeEncomienda == 'V')
{

    TurismoDiasViajes -> selecionarDestino();

    //cout << "Los destinos disponibles para viaje son: ";
    //TurismoDias->printDestinosViajes();

    
}
else
{
    cout << "Esta usted solicitando este servicio como Persona (P) o como Empresa (E): ";
    cin >> opcionPersonaEmpresa;

    //cout << "Los destinos disponibles para encomiendas son: ";
    //TurismoDias->printDestinosEncomiendas();
    
    //cout << "\nElija, de la lista, el destino de la encomienda (1 - " << TurismoDias->getEncomiendasN() << ")";
    //cin>>opcionDestino;    
}
}
