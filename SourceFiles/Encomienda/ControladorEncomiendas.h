#include "../Libraries.h"
#include "../Rutas.h"
#include "../Persona.h"

//Algoritmos
#include "../Algoritmos/NodoLista.h"
#include "../Algoritmos/NodoArbol.h"

#include "objetoEncomienda.h"
#include "Encomienda.h"

class ControladorEncomiendas: public Rutas
{
    private:
        NodoLista<Persona> *listaClientes;
        NodoLista<objetoEncomienda> * listaObjetos;
        NodoLista<Encomienda> * listaEncomienda;
        int esPrint;
public:
    ControladorEncomiendas(){
        this->listaClientes = NULL;
        this->listaObjetos = NULL;
        this->listaEncomienda = NULL;
    };
    ~ControladorEncomiendas(){};

    void printInfoEncomiendas(){
        int contador = 1;
        //Se crea un auxiliar para no alterar los punteros de la lista original
        NodoLista<Encomienda> * aux = listaEncomienda;
        if (aux!= NULL)
        {
            while (aux != NULL)
        {
            cout << "Encomienda numero " << contador << endl;
            cout << "Propietario: " << aux->getElemento(aux)->cliente->getNombre() << " " << aux->getElemento(aux)->cliente->getApellido() <<endl;
            cout << "Categoria del producto: " << aux->getElemento(aux)->objeto->getCategoria() << endl;
            cout << "Peso (Kg): " << aux->getElemento(aux)->getPeso();
            cout << "Fragil: ";
            if (aux->getElemento(aux)->objeto->getEsFragil())
            {
                cout << "SI" << endl;
            }
            else{cout << "NO" << endl;}  
            contador++;
            aux = aux->nextElemento(aux);
        }
        }
        else
        {
            cout << "No existen encomiendas por el momento!" << endl;
            cont();
        }
    }

    void agendarEncomiendaFinal(){
        while (listaClientes != NULL && listaObjetos!= NULL)
        {
           Encomienda * encomiendaFinal = new Encomienda(listaClientes->getElemento(listaClientes), listaObjetos->getElemento(listaObjetos));
           listaClientes = listaClientes->nextElemento(listaClientes);
           listaObjetos = listaObjetos->nextElemento(listaObjetos);
           listaEncomienda->push(&listaEncomienda, encomiendaFinal);
        }           
    }
    
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
            clearScreen;
            cout << "Selecione la opcion: \n";
            cout << "1. Agendar una encomienda \n";
            cout << "2. Mostrar lista de encomiendas \n";
            //cout << "3. Ranking de clientes \n";
            cout << "3. Regresar al menu principal \n";
            
            cin >> opcionSelecionada;

            if (!(opcionSelecionada >= 1 && opcionSelecionada <= 4)){
                ClearKeyboard();
                cout << "La opcion seleccionada es incorrecta.";
                cont();
            }
            else
                return opcionSelecionada;
        } while (opcionSelecionada != 3);
        return opcionSelecionada;
    }

    //Para hacer funcionar esta función, se necesita primero el HashTable
    void arbolRankingEncomiendas(NodoArbol * arbol, int cantEncomiendas){

    }

    void agendarCliente()
    {
        listaClientes->push(&listaClientes, almacenarInfoCliente(listaClientes));
        if (printClientesEncomiendas() == 1)
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
            lista->getElemento(lista)->informacionPersona();
            lista = lista->nextElemento(lista);
        }
        cout << "Presione cualquier tecla para volver al menu de encomiendas!" << endl;
        cont();
    }

    Persona * almacenarInfoCliente(NodoLista<Persona> * lista){
        clearScreen;
        string nombreP, apellidoP;
        int edadP;
        bool validar;

        Persona * cliente = new Persona();

        #if RAD == 0
                    cliente->typePersona();
        #elif RAD == 1
                    cliente->randomPersona();
        #endif

        return cliente;
    }

    int printClientesEncomiendas(){
        int opcion;
        cout << "Desea ver sus datos en la lista de clientes? Si = 1 / No = 0" << endl;
        cin >> opcion;
        return opcion;
    }

    objetoEncomienda * almacenarInfoObjeto(){
        string categoria;
        int opcion;
        float peso;
        char esFragil;

        do
        {
            clearScreen;

            cout << "De que categoria es su objeto a encomendar?: " << endl;
            cout << "1- Tecnologia"<< endl;
            cout << "2- Salud"<< endl;
            cout << "3- Vestimenta"<< endl;

            cin >> opcion;

            if (!(opcion >= 1 && opcion <= 3)) {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.";
            cont();
            
        }
        } while (!(opcion >= 1 && opcion <= 3));
        
        switch (opcion)
        {
        case 1: categoria = "Tecnologia";break;
        case 2: categoria = "Salud";break;
        case 3: categoria = "Vestimenta";break;
        }

        do
        {
            clearScreen;

            cout << "Cual es el peso aproximado(Kg) de su objeto?"<< endl;
            cin >> peso;

            if (!(peso >= 0.01 && peso <= 30)) {
            ClearKeyboard();
            cout << "El valor ingresado es invalido.\n";
            cont();

            }   
        } while (!(peso >= 0.01 && peso <= 30));

        do
        {
            clearScreen;

            cout << "Es su objeto considero fragil?: S = SI / N = NO "<< endl;
            cin >> esFragil;

            esFragil = toupper(esFragil);

            if (!(int(esFragil) == 78 || int(esFragil) == 83)) {
            ClearKeyboard();
            cout << "El valor ingresado es invalido.\n";
            cont();

            }   
        } while (!(int(esFragil) == 78 || int(esFragil) == 83));

        objetoEncomienda * objeto = new objetoEncomienda(categoria, peso, esFragil);
        return objeto;
    }

    void agendarObjeto(){
        listaObjetos->push(&listaObjetos, almacenarInfoObjeto());
    }
};
