#include "Libraries.h"
#include "Persona.h"

class NodoLista
{
public:
    Persona * cliente;
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
        lista = nuevoNodo
};
