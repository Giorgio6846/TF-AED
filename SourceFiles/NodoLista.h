#include "Libraries.h"
#include "Persona.h"
#pragma once
class NodoLista
{
public:

    Persona * cliente;
    NodoLista * next;

public:
    NodoLista(){

    NodoLista * head = NULL;
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
            cout << lista->cliente->getEdad() << endl;
            lista = lista->next;
        }
    }
};




