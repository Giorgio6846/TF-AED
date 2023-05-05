#include "Libraries.h"
#include "Encomienda.h"

class NodoCola
{
public:
    Encomienda * encomienda;
    NodoCola * next;

public:
    NodoCola(){
    NodoCola * frente = NULL;
    NodoCola * fin = NULL;
    };
    ~NodoCola(){};


    void insertarElementoCola(NodoCola *& frente, NodoCola *& fin, Encomienda * encomiendaCliente){
        
        //Creación del nuevo nodo
        NodoCola * nuevoNodo = new NodoCola();
        //Asignación del valor al nuevo nodo
        nuevoNodo->encomienda = encomiendaCliente;
        //Al ser una cola, el ultimo elemento apunta a NULL
        nuevoNodo->next = NULL;
        //Función lambda que evalua si la cola está vacía
        auto estaVacia = [&](){return (frente == NULL) ? true : false;};
        if (estaVacia()){frente = nuevoNodo;}
        else {fin->next = nuevoNodo;}
        fin = nuevoNodo;
    }


    

};
