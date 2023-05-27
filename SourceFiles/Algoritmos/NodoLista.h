#include "../Libraries.h"
#pragma once

template <class T>
class NodoLista
{
public:
    T * elemento;
    NodoLista * next;

public:
    NodoLista(){};
    ~NodoLista(){};

    void insertarElementoLista(NodoLista **lista, T *elemento)
    {
        //Se crea un nuevo nodo
        clearScreen;
        NodoLista * nuevoNodo = new NodoLista();
        nuevoNodo->elemento = elemento;
        //El ultimo nodo siempre apunta a NULL
        nuevoNodo->next = NULL;
        //Si la lista está ya vacia, podemos insertar el nuevo nodo directamente
        if (*lista == NULL){*lista = nuevoNodo;}
        else
        {
            //Creamos un auxiliar para iterar y detectar cuando llegó al final de la lista
            NodoLista * aux = *lista;
            while (aux->next != NULL){aux = aux->next;}
            aux->next = nuevoNodo;
        }
        cout << "Los datos han sido registrada de manera satisfactoria!" << endl;
    }

    T * getElemento(NodoLista *listaElementos){return listaElementos->elemento;}
};