#include "Libraries.h"
#include "App.h"

int main(){

App * TurismoDias = new App();

char opcion;

cout << "Deseas agendar un viaje o una encomienda? Viaje = V / Encomienda = E : ";
cin >> opcion;
if (opcion == 'V')
{
    cout << "Los destinos disponibles para viaje son: ";
    TurismoDias->printDestinosViajes();
}
else
{
    cout << "Los destinos disponibles para encomiendas son: ";
    TurismoDias->printDestinosEncomiendas();
}


}