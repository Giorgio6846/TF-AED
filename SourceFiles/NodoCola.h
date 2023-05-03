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
        
        NodoCola * nuevoNodo = new NodoCola();
        nuevoNodo->encomienda = encomiendaCliente;
        nuevoNodo->next = NULL;
        
        //Función lambda que evalua si la cola está vacía
        auto estaVacia = [&](){return (frente == NULL) ? true : false;};

        if (estaVacia()){frente = nuevoNodo;}
        else {fin->next = nuevoNodo;}
        fin = nuevoNodo;
    }


    

};
