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

            if (!(opcionSelecionada >= 1 && opcionSelecionada <= 4))
                cout << "La opcion seleccionada es incorrecta.\n";
            else
                return opcionSelecionada;
        } while (opcionSelecionada != 3);
        return opcionSelecionada;
    }

    Persona * almacenarInfoCliente(NodoLista * lista){
        string nombreP, apellidoP;
        int edadP;
        cout << "Ingrese su nombre: "; cin >> nombreP;
        cout << "Ingrese su apellido: "; cin >> apellidoP;
        cout << "Ingrese su edad: "; cin >> edadP;
        //Con la información dada, se crea un objeto cliente y se devuelve 
        Persona * cliente = new Persona(nombreP, apellidoP, edadP, 'D');
        return cliente;
        //lista->insertarElementoLista(lista, cliente);
    }


    int printClientesEncomiendas(NodoLista * lista){

        int opcion;
        cout << "Desea ver la lista de clientes con encomiendas agendadas? Si = 1 / No = 0" << endl;
        cin >> opcion;
        return opcion;
        
        
    }

};
