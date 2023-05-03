#include "Libraries.h"

class ControladorEncomiendas
{
private:
    /* data */
public:
    ControladorEncomiendas(/* args */){



    };
    ~ControladorEncomiendas(){};


    int menuEncomiendas(){

    int opcionSelecionada;
    do
    {
        cout << "Selecione la opcion. \n";
        cout << "1. Agendar una encomienda \n";
        cout << "2. Eliminar una encomienda \n";
        cout << "3. Regresar al menu principal \n";

        cin >> opcionSelecionada;

        if (!(opcionSelecionada >= 1 && opcionSelecionada <= 4))
            cout << "La opcion seleccionada es incorrecta.\n";
        else return opcionSelecionada;
    } while (opcionSelecionada != 3);

    return opcionSelecionada;
    }
};
