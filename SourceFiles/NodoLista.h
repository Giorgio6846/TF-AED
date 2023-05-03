#include "Libraries.h"
#include "Persona.h"

class NodoLista
{
public:

    TIPO cliente;
    NodoLista * next;

public:
    NodoLista(){
    NodoLista * lista = NULL;
    };
    ~NodoLista(){};
    
    void insertarElementoLista(NodoLista *& lista, Persona * cliente){
        //Se crea un nuevo nodo
        NodoLista * nuevoNodo = new NodoLista();
        nuevoNodo->cliente = cliente;
        //Lo pone al inicio
        nuevoNodo->next= lista;
        //Hace que ahora el inicio apunte a nuevoNodo
        lista = nuevoNodo;
        }

    void printClientes(NodoLista* lista){
        //Mientas que la lista no llegue a su fin -> imprimir nombre del cliente
        while (lista != NULL)
        {
            cout << lista->cliente << endl;
            lista = lista->next;
        }
    }
};




