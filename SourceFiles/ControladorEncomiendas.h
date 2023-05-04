#include "Libraries.h"
#include "Persona.h"

class ControladorEncomiendas
{
public:
    ControladorEncomiendas(){};
    ~ControladorEncomiendas(){};

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
