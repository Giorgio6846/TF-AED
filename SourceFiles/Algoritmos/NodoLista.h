#include "../Libraries.h"
#pragma once
#include "../Encomienda/Encomienda.h"


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

    Encomienda * getElementoEncomienda(NodoLista<Encomienda> *listaElemento, string valor){
        NodoLista<Encomienda> * aux = listaElemento;
        while (aux->next != NULL)
        {
            if (aux->elemento->getCodigo() == valor)
            {
                return aux->elemento;
            }
            aux = aux->next;
        }
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
    for (; tmp != NULL; tmp=tmp->next)
    {
        contador++;
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

//Se requiere la dirección del dato, más no el valor en sí.
void borrarElemento(NodoLista<T> *&lista, T dato){
    if(lista!=NULL){
        NodoLista<T> *aux_borrar;
        NodoLista<T> *anterior = NULL;
        aux_borrar = lista;

        while (aux_borrar != NULL && *(aux_borrar->elemento) != dato)
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->next;
        }
        if(aux_borrar==NULL){
            cout<<"El dato no existe en la lista.";
        }
        else if(anterior==NULL){
            lista = lista->next;
            delete aux_borrar;
            cout<<"El elemento se ha eliminado con exito!";
        }
        else{
            anterior->next = aux_borrar->next;
            delete aux_borrar;         
            cout<<"El elemento se ha eliminado con exito!";
        }
    }
    else{
        cout<<"La lista no contiene ningun elemento.";
    }
}

void SwapElementos(NodoLista<T> *&lista, T x, T y)
{
    if (lista !=NULL)
    {
        if(x==y){return;}
        NodoLista<T> * prevX = NULL; NodoLista<T> * currentX = lista; 
        NodoLista<T> * prevY = NULL; NodoLista<T> *currentY = lista;

        while (*(currentX->elemento) != x)
        {
            //Sabemos siempre quien sería el nodo anterior al que buscamos
            prevX = currentX;
            currentX = currentX->next;
        }
        while (*(currentY->elemento) != y)
        {
            //Sabemos siempre quien sería el nodo anterior al que buscamos
            prevY = currentY;
            currentY = currentY->next;
        }
        //Si alguno de los dos valores no existe, no se hace el cambio
        if ((currentX->elemento) == NULL || (currentY->elemento) == NULL){cout << "Uno de los elementos dados no existen en la lista" << endl; return;}
        //Cambiamos los valores
        T aux1; T aux2;
        aux1 = *(currentY->elemento); 
        aux2 = *(currentX->elemento);

        prevX = prevX->next; *(prevX->elemento) = aux1;
        prevY = prevY->next; *(prevY->elemento) = aux2;
    }
    else{
        cout << "La lista se encuentra vacía brothesito!; pero fresh, agregalo dos elementos y ya" << endl;
    }
    

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