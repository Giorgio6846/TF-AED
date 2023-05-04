#include "Libraries.h"
#include "Persona.h"
#pragma once
class NodoLista
{
public:

    Persona * cliente;
    NodoLista * next;

public:
    NodoLista(){};
    ~NodoLista(){};
    
    void insertarElementoLista(NodoLista *&lista, Persona * cliente){
        //Se crea un nuevo nodo
        NodoLista * nuevoNodo = new NodoLista();
        nuevoNodo->cliente = cliente;
        //Lo pone al inicio
        NodoLista * aux1 = lista;
        NodoLista * aux2;
        //Hace que ahora el inicio apunte a nuevoNodo

        while (aux1 != NULL)
        {
            aux2 = aux1;
            aux1 = aux1->next;
        }
        
        if (lista == aux1)
        {
            lista = nuevoNodo;
            nuevoNodo->next = aux1;
        }
        else
        {
            aux2->next  = nuevoNodo;
            nuevoNodo->next = aux1;
        }
        cout << "Su datos han sido registrada de manera satisfactoria!" << endl;
        }


    void printClientes(NodoLista* lista){

        NodoLista * aux = new NodoLista();
        aux = lista;
        //Mientas que la lista no llegue a su fin -> imprimir nombre del cliente
        while (aux != NULL)
        {
            cout << "Edad: " << aux->cliente->getEdad() << endl;
            cout << "" << endl;
            aux = aux->next;
        }
    }
};




