#pragma once
#include "../Encomienda/Encomienda.h"
#include "../Libraries.h"

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

    T * getElemento(NodoLista *listaElementos){return elemento;}
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
        return NULL;
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

    while(nextElemento(ultimo) != NULL)                                                                                                   
    {
        ultimo = nextElemento(ultimo);
    }
    ultimo->next = nuevoNodo;
}

//Listo
int contadorLista(NodoLista<T> *lista)
{
    int contador = 0;
    NodoLista<T> *tmp = lista;
    for (; tmp != NULL; tmp = nextElemento(tmp))
    {
        contador++;
    }
    return contador;
}

//Listo
void insertarElementoPosicion(NodoLista<T> **lista, T *objeto, int pos)
{
   NodoLista *nodo;
   nodo->elemento = objeto;
   nodo->next = NULL;

    if (!(pos >= 0 && pos <= contadorLista(*lista)))
    {
    }
    if (pos == 0)
    {
    push(lista, objeto);
    }
    else if(pos == contadorLista(*lista))
    {
    append(lista, objeto);
    }
    else
    {
        NodoLista *tmp = *lista;
        for (int contador = 0; (tmp != NULL) && (contador <= pos); tmp = nextElemento(tmp))
        {
                if (contador == pos)
                {
                    nodo -> next = tmp -> next;
                    tmp-> next  = nodo;
                }
                contador++;
        }
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

//Hace swap del valor del elemento pero la idea es de la direccion de memoria
//Mas tarde implementarlo
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
        cout << "La lista se encuentra vacía" << endl;
    }
}

//Listo
T *obtenerPosicionElemento(NodoLista<T> **lista, int pos)
{
    if (lista == NULL)
    {
        cout << "La lista esta vacia";
        return NULL;
    }
    
    NodoLista<T> *tmp = *lista;
    if (pos <= contadorLista(tmp))
    {
        for (int contador = 0; (tmp != NULL) && (contador <= pos); tmp = nextElemento(tmp))
        {
            if (contador == pos)
            {
                    return tmp->elemento;
            }
            contador++;
        }
    }
    cout << "La posicion selecionada es mayor a la cantidad de items en la lista";
    return NULL;
}

//Max y Min Heap
int parent(NodoLista<T> *lista) { return (contadorLista(&lista) - 1) / 2; }
int left(NodoLista<T> *lista) { return 2 * contadorLista(&lista) + 1;     }
int right(NodoLista<T> *lista) { return 2 * contadorLista(&lista) + 2;    }

};