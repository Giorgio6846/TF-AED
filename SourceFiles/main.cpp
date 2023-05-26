//#include "App.h"
#include "Libraries.h"
#include "Viajes.h"
#include "Encomienda.h"
#include "Persona.h"

int menu();
void opcionViajes(Viajes *claseViaje);
void opcionEncomienda(Encomienda *claseEncomienda);

int main()
{
    Viajes *claseViaje = new Viajes();
    Encomienda *claseEncomienda = new Encomienda();

    int opcionElegida;

    do
    {
        opcionElegida = menu();

        switch (opcionElegida)
        {
        case 1:
            clearScreen;
            opcionViajes(claseViaje);
            break;
        case 2:
            clearScreen;
            opcionEncomienda(claseEncomienda);
            break;
        default:
            cout << "Gracias por elegir nuestra app! :)";
            break;
        }
    } while (opcionElegida != 3);
}

void opcionViajes(Viajes *claseViaje)
{
    int opcionSelecionada;
    do
    {
        opcionSelecionada = claseViaje->menuViajes();

        switch (opcionSelecionada)
        {
        case 1:
            // Invoca la funcion de la clase para reservar el viaje
            claseViaje->reservaViajes();
            break;
        case 2:
            // Invoca la funcion de la clase para buscar un viaje reservado
            claseViaje->reservaBusquedaViajes();
            break;
        case 4:
            // Invoca la funcion de la clase para realizar la escritura de archivos
            claseViaje->escrituraArchivo();
            break;
        default:
            break;
        }
    } while (opcionSelecionada != 3);
    clearScreen;
}

void opcionEncomienda(Encomienda *claseEncomienda)
{
    int opcionSelecionada;

    do
    {
        opcionSelecionada = claseEncomienda->menuEncomienda();

        switch (opcionSelecionada)
        {
        case 1:
                //Invoca la clase para agendar la encomienda
                claseEncomienda ->agendarEncomienda();
            break;

        case 2:
            //Eliminar una encomienda del sistema
            break;

        default:
            break;
        }
    } while (opcionSelecionada != 3);
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
        //Validando que solo permita numeros del 1 al 3
        if (!(opcionSelecionada >= 1 && opcionSelecionada <= 4)) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "La opcion seleccionada es incorrecta.\n";
        }

    } while (!(opcionSelecionada >= 1 && opcionSelecionada <= 4));

    return opcionSelecionada;
}

