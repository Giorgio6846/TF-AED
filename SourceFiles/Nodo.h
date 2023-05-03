#include "Libraries.h"
#include "Encomienda.h""

class Nodo
{
public:
    Encomienda * encomienda;
    Nodo * next;

public:
    Nodo(){
    Nodo * frente = NULL;
    Nodo * fin = NULL;
    };
    ~Nodo(){};

    //Funcion que verifica si la cola está vacía
    bool colaVacia(Nodo * frente){
        

    }

    void insertarElementoCola(Nodo *& frente, Nodo *& fin, Encomienda * encomiendaCliente){
        
        Nodo * nuevoNodo = new Nodo();
        nuevoNodo->encomienda = encomiendaCliente;
        nuevoNodo->next = NULL;
        
        auto estaVacia = [&](){return (frente == NULL) ? true : false;};

        if (estaVacia()){frente = nuevoNodo;}
        else {fin->next = nuevoNodo;}
        fin = nuevoNodo;
    }


    

};
