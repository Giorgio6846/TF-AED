#include "Libraries.h"
#include "Persona.h"

class ControladorEncomiendas
{
public:
    ControladorEncomiendas(){};
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

    Persona informacionCliente(char tipoCliente){
        string nombreP, apellidoP;
        int edadP;
        cout << "Ingrese su nombre: "; cin >> nombreP;
        cout << "Ingrese su apellido: "; cin >> apellidoP;
        cout << "Ingrese su edad: "; cin >> edadP;
        //Con la información dada, se crea un objeto cliente
        Persona * cliente = new Persona(nombreP, apellidoP, edadP, 'D');
        return *cliente;
    }
};
