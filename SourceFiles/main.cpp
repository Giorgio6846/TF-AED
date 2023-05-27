//#include "App.h"
#include "Libraries.h"
#include "Persona.h"

#if (VER == 1 || VER == 2)
#include "ControladorViajes.h" 
#endif

#if (VER == 1 || VER == 3)
#include "ControladorEncomiendas.h"
#endif

/*
Opciones de Compilacion
1: Release
2: Solo Viajes
3: Solo Encomiendas
*/

int menu();

#if (VER == 1 || VER == 2)
void opcionViajes(ControladorViajes *claseViaje);
#endif

#if (VER == 1 || VER == 3)
void opcionEncomienda(ControladorEncomiendas *claseEncomienda);
#endif

int main()
{
    #if (VER == 1 || VER == 2)
    ControladorViajes *claseViaje = new ControladorViajes();
    #endif

    #if (VER == 1 || VER == 3)
    ControladorEncomiendas *claseEncomienda = new ControladorEncomiendas();
    #endif

    int opcionElegida;

    do
    {
        opcionElegida = menu();

        switch (opcionElegida)
        {
        case 1:
            #if (VER == 1 || VER == 2)
            clearScreen;
            opcionViajes(claseViaje);
            #endif

            break;
        case 2:
            #if (VER == 1 || VER == 3)
            clearScreen;
            opcionEncomienda(claseEncomienda);
            #endif
            
            break;
        default:
            cout << "Gracias por elegir nuestra app! :)";
            break;
        }
    } while (opcionElegida != 3);
}

#if (VER == 1 || VER == 2)
void opcionViajes(ControladorViajes *claseViaje)
{
    int opcionSelecionada;
    do
    {
        opcionSelecionada = claseViaje->menuViajes();

        switch (opcionSelecionada)
        {
        case 1:
            // Invoca la funcion de la clase para reservar el viaje
            claseViaje->reservaViaje();
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
#endif

#if (VER == 1 || VER == 3)
void opcionEncomienda(ControladorEncomiendas *claseEncomienda)
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
#endif

int menu()
{
    int opcionSelecionada;
    do
    {
        clearScreen;
        cout << "Selecione la opcion:" << "\n";
        cout << "1. Viajes" << "\n";
        cout << "2. Encomiendas" << "\n";
        cout << "3. Salir" << "\n";

        cin >> opcionSelecionada;
        //Validando que solo permita numeros del 1 al 3
        if (!(opcionSelecionada >= 1 && opcionSelecionada <= 3)) {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.";
            cont();
        }

    } while (!(opcionSelecionada >= 1 && opcionSelecionada <= 3));

    return opcionSelecionada;
}

