#include "Libraries.h"
#include "Rutas.h"
#include "Persona.h"
#include "NodoLista.h"

class ControladorEncomiendas: public Rutas
{
public:
    ControladorEncomiendas(){};
    ~ControladorEncomiendas(){};

    void reservaEncomienda(){

    int Origen, Destino, cantidadUsuarios;

    Origen = Rutas :: selecionarOrigen();
    Destino = Rutas :: selecionarDestino(Origen);

    cout << "\n Ha selecionado el origen " << Rutas :: getOrigen(Origen);
    cout << "\n Ha selecionado el destino " << Rutas :: getDestino(Destino);
    }
    
    int menuEncomienda(){
        int opcionSelecionada;
        do{
            cout << "Selecione la opcion. \n";
            cout << "1. Agendar una encomienda \n";
            cout << "2. Eliminar una encomienda \n";
            cout << "3. Regresar al menu principal \n";
            
            cin >> opcionSelecionada;

            if (!(opcionSelecionada >= 1 && opcionSelecionada <= 4)){
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout << "La opcion seleccionada es incorrecta.";
                getChar();
            }
            else
                return opcionSelecionada;
        } while (opcionSelecionada != 3);
        return opcionSelecionada;
    }

    Persona * almacenarInfoCliente(NodoLista<Persona> * lista){
        clearScreen;
        string nombreP, apellidoP;
        int edadP;
        cout << "Ingrese su nombre: "; cin >> nombreP;
        cout << "Ingrese su apellido: "; cin >> apellidoP;

        do
        {
            cout << "Ingrese su edad: "; cin >> edadP;

            if (!(edadP >= 18 && edadP <= 120)) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "El valor ingresado es invalido.\n";
            }   

        } while (!(edadP >= 18 && edadP <= 120));

        //Con la información dada, se crea un objeto cliente y se devuelve 
        Persona * cliente = new Persona(nombreP, apellidoP, edadP, 'D');
        return cliente;
    }


    int printClientesEncomiendas(NodoLista<Persona> * lista){
        int opcion;
        cout << "Desea ver sus datos en la lista de clientes? Si = 1 / No = 0" << endl;
        cin >> opcion;
        return opcion;
    }

};
