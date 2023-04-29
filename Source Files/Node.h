#include "Libraries.h"
#include "Persona.h"

class Node
{
public:
    Persona * persona;
    Node * next;

public:
    Node(){};
    ~Node(){};

    void insertarLista(Node *& lista, Persona * persona ){

    Node * nuevoNodo = new Node();
    nuevoNodo->persona = persona;
    Node * aux = lista;

    

    }

};
