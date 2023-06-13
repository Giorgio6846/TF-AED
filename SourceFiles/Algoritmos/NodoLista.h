#include "../Libraries.h"
#pragma once


template <class T>
class NodoLista
{
private:
    T * elemento;
    NodoLista * next;

public:
    NodoLista()
    {
        next = NULL;
    }
    ~NodoLista(){};

    /*
    void insertarElementoLista(NodoLista **lista, T *elemento)
    {
        //Se crea un nuevo nodo
        //clearScreen;
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
        //cout << "Los datos han sido registrada de manera satisfactoria!" << endl;
    }
    */

    T * getElemento(NodoLista *listaElementos){return listaElementos->elemento;}
    NodoLista * nextElemento(NodoLista *lista){return lista->next;}

void eliminarElemento()
{
    
}

//Listo
void push(NodoLista<T> ** lista, T *objeto)
{
    NodoLista<T> * nuevoNodo = new NodoLista<T>();
    nuevoNodo -> elemento = objeto;

    nuevoNodo -> next = *lista;
    *lista = nuevoNodo;
}

//Listo
void append(NodoLista<T> **lista, T *objeto)
{
    NodoLista<T> * nuevoNodo = new NodoLista<T>();
    NodoLista *ultimo = *lista;

    nuevoNodo ->elemento = objeto;
    nuevoNodo -> next = NULL;

    if(*lista == NULL)
    {
        *lista = nuevoNodo;
    }

    while(ultimo->next != NULL)
    {
        ultimo = ultimo -> next;
    }
    ultimo->next = nuevoNodo;
}

//Listo
int contadorLista(NodoLista<T> *lista)
{
    int contador = 0;
    NodoLista<T> *tmp = lista;
    while(tmp != NULL)
    {
        contador++;
        tmp=tmp->next;
    }
    return contador;
}

//Listo
void insertarElementoPosicion(NodoLista<T> *lista, T *objeto, int pos)
{
    NodoLista<T> *aux = *lista;
    if (pos > contadorLista(lista))
    {
        cout << "La posicion selecionada es mejor a la cantidad de items en la lista";
    }
    else
    {
        NodoLista<T> *nuevoNodo = new NodoLista<T>();
        nuevoNodo->elemento = objeto;
        nuevoNodo->next = *aux->next;
        *aux->next = nuevoNodo;
    }
}

void borrarElemento(NodoLista<T> *&lista, int dato){
    if(lista!=NULL){
        NodoLista<T> *aux_borrar;
        NodoLista<T> *anterior = NULL;
        aux_borrar = lista;

        while(aux_borrar!=NULL && aux_borrar->dato!=dato){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if(aux_borrar==NULL){
            cout<<"El dato no existe en la lista.";
        }
        else if(anterior==NULL){
            lista = lista->siguiente;
            delete aux_borrar;
            cout<<"El elemento se ha eliminado con exito!";
        }
        else{
            anterior->siguiente =  aux_borrar->siguiente;
            delete aux_borrar;         
            cout<<"El elemento se ha eliminado con exito!";
        }
    }
    else{
        cout<<"La lista no contiene ningun elemento.";
    }
}

void busquedaNodo()
{

}

//Listo
T obtenerPosicionNodos(NodoLista<T> *lista)
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