#include "../Libraries.h"
#pragma once

template <class T>
class NodoLista
{
public:
    T * elemento;
    NodoLista * next;

public:
    NodoLista()
    {
        next = NULL;
    }
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

void insertarElementoInicio(T *objeto)
{
    NodoLista<T> * nuevoNodo = new NodoLista<T>();
    nuevoNodo -> elemento = objeto;
    if (next == NULL)
    {
        nuevoNodo -> next = NULL;
    }
    else
    {
        nuevoNodo -> next = next;
    }
    next = nuevoNodo;
}

void insertarElementoFinal(NodoLista<T> *lista, T *objeto)
{
    NodoLista<T> * nuevoNodo = new NodoLista<T>();
    nuevoNodo -> elemento = objeto;
    nuevoNodo -> next = NULL;
    if (next == NULL)
    {
        next = nuevoNodo;
    }
    else
    {
        NodoLista<T> *aux = *lista;
        while (aux -> next != NULL)
        {
             aux = aux -> next;
        }
        aux -> next = nuevoNodo;
    }
}

void insertarElementoPosicion(NodoLista<T> *lista, T *objeto, int pos)
{
    NodoLista<T> *aux = *lista;
    int i = 0;
    while (i < pos)
    {
        *aux -> next;
        if(*aux == NULL)
        {
            cout << "La posicion selecionada es mejor a la cantidad de items en la lista";
        }
        i++;
    }
    
    NodoLista<T> * nuevoNodo = new NodoLista<T>();
    nuevoNodo -> elemento = objeto;
    nuevoNodo -> next = *aux -> next;
    *aux -> next = nuevoNodo;
}

void eliminarNodoPosicion()
{

}

void busquedaNodo()
{

}

T obtenerPosicionNodos(NodoLista *lista)
{
    if (*lista == NULL)
    {
        cout << "La lista esta vacia";
        return NULL;
    }
    else
    {
        NodoLista * aux = *lista;
    }
}

};