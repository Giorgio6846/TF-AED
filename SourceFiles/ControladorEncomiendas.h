#include "Libraries.h"
#include "Rutas.h"
#include "Persona.h"
#include "Algoritmos/NodoLista.h"

class ControladorEncomiendas: public Rutas
{
    private:
        NodoLista<Persona> *listaClientes;
        int esPrint;
public:
    ControladorEncomiendas(){
        this->listaClientes = NULL;
    };
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
                //cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout << "La opcion seleccionada es incorrecta.";
                cont();
            }
            else
                return opcionSelecionada;
        } while (opcionSelecionada != 3);
        return opcionSelecionada;
    }

    void agendarEncomienda()
    {
        listaClientes->insertarElementoLista(&listaClientes, almacenarInfoCliente(listaClientes));
        esPrint = printClientesEncomiendas(listaClientes);
        if (esPrint == 1)
        {
            printClientes(listaClientes);
        }
    }

    void printClientes(NodoLista<Persona> *lista)
    {
        int op;
        // Mientras no se llegue al final de lista, mostrar los datos de los clientes almacenados
        clearScreen;
        while (lista != NULL)
        {
            cout << "Nombre: " << lista->elemento->getNombre() << endl;
            cout << "Apellido: " << lista->elemento->getApellido() << endl;
            cout << "Edad: " << lista->elemento->getEdad() << endl;
            cout <<endl;
            lista = lista->next;
        }
        cout << "Presione cualquier tecla para volver al menu de encomiendas!" << endl;
        cont();
    }

    Persona * almacenarInfoCliente(NodoLista<Persona> * lista){
        clearScreen;
        string nombreP, apellidoP;
        int edadP;
        bool validar;

        do{
        cout << "Ingrese su nombre: "; cin >> nombreP;
        for (int i = 0; i < nombreP.length(); i++)
        {
            if(!(isdigit(nombreP[i]))){
            validar=true;
            }else
            {
            validar=false;
            }
        }if (validar==false){
                cout << "El nombre ingresado es invalido.\n";
                }
        } while (validar==false);

        do{
        cout << "Ingrese su apellido: "; cin >> apellidoP;
        for (int i = 0; i < apellidoP.length(); i++)
        {
            if(!(isdigit(apellidoP[i]))){
            validar=true;
            }else
            {
            validar=false;
            }
        }if (validar==false){
                cout << "El apellido ingresado es invalido.\n";
                }
        } while (validar==false);

        do
        {
            cout << "Ingrese su edad: "; cin >> edadP;

            if (!(edadP >= 0 && edadP <= 120)) {
            cin.clear();
            //cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "El valor ingresado es invalido.\n";
            }   

        } while (!(edadP >= 0 && edadP <= 120));

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
