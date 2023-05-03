#include "Libraries.h"

class Encomienda
{
public:
    /* data */
public:
    Encomienda(/* args */){

        
    };
    ~Encomienda(){};

    int menuEncomiendas(){

    int opcionSeleccionada;
    do
       {
           cout << "Selecione la opcion. \n";
           cout << "1. Agendar una encomienda \n";
           cout << "2. Cancelar una encomienda \n";
           cout << "3. Regresar al menu principal \n";
           cin >> opcionSeleccionada;
           if (!(opcionSeleccionada >= 1 && opcionSeleccionada <= 4))
               cout << "La opcion seleccionada es incorrecta.\n";
       } while (!(opcionSeleccionada >= 1 && opcionSeleccionada <= 4));

    return opcionSeleccionada;

}
};

