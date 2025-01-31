#pragma once
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
    ~NodoLista()
    {
        elemento = NULL;
        delete elemento;

        next = NULL;
        delete next;
    }

    T * getElemento(){return elemento;}
    NodoLista * nextElemento(NodoLista *lista){return lista->next;}

//Listo
void push(NodoLista<T> ** lista, T *objeto)
{
    NodoLista<T> * nuevoNodo = new NodoLista<T>();
    nuevoNodo -> elemento = objeto;

    nuevoNodo -> next = *lista;
    *lista = nuevoNodo;
}

NodoLista<T> * duplicadoLista(NodoLista<T> * original)
{
    
    //Copia del NodoLista Origen
    NodoLista<T> * tmpO = original;
    NodoLista<T>* duplicado = NULL;
    //NodoLista Copia
    //NodoLista<T> *copiaTmp = NULL;
    for (; tmpO != NULL; tmpO = tmpO->nextElemento(tmpO))
    {
        duplicado->appendDir(&duplicado, tmpO->getElemento());
    }
    //*copia = copiaTmp;

    //copiaTmp = NULL;
    //delete copiaTmp;
    
    tmpO = NULL;
    delete tmpO;
    

    //NodoLista<T>* duplicado = new NodoLIsta<T>();
    //duplicado ->
    return duplicado;
}

//Listo
void appendDir(NodoLista<T>** lista, T* objeto)
{
    NodoLista<T>* nuevoNodo = new NodoLista<T>;
    //NodoLista<T>* nuevoNodo;

    nuevoNodo->elemento = objeto;
    nuevoNodo->next = *lista;

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
    else
    {
        while (nextElemento(ultimo) != NULL)
        {
            ultimo = nextElemento(ultimo);
        }
        ultimo->next = nuevoNodo;
    } 
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

    tmp = NULL;
    delete tmp;
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
        tmp = NULL;
        delete tmp;
    }
}

//Se requiere la dirección del dato, más no el valor en sí.
void borrarElemento(NodoLista<T> *&lista, T dato){
    // Lambda que verifica si el elemento es igual al dato
    auto Esigual = [](T *elemento, T dato) { return *elemento == dato; };

    if(lista!=NULL){
        NodoLista<T> *aux_borrar;
        NodoLista<T> *anterior = NULL;
        aux_borrar = lista;

        while (aux_borrar != NULL && !isEqual(aux_borrar->elemento, dato))
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

void SwapElementosDireccion(NodoLista<T> *&lista, T * x, T * y)
{   
    auto swapPointers = [](T *elementX, T *elementY) {
        T * aux = elementX;
        elementX = elementY;
        elementY = aux;
        return aux;
    };

    if (lista != NULL)
    {
        if (x == y)
        {
            return;
        }
        NodoLista<T> *prevX = NULL;
        NodoLista<T> *currentX = lista;
        NodoLista<T> *prevY = NULL;
        NodoLista<T> *currentY = lista;

        while ((currentX->elemento) != x)
        {
            // Sabemos siempre quien sería el nodo anterior al que buscamos
            prevX = currentX;
            currentX = currentX->next;
        }
        while ((currentY->elemento) != y)
        {
            // Sabemos siempre quien sería el nodo anterior al que buscamos
            prevY = currentY;
            currentY = currentY->next;
        }
        // Si alguno de los dos valores no existe, no se hace el cambio
        if ((currentX->elemento) == NULL || (currentY->elemento) == NULL)
        {
            cout << "Uno de los elementos dados no existen en la lista" << endl;
            return;
        }
        // Cambiamos los valores
        T * aux = swapPointers(currentX->elemento, currentY->elemento);
    }
    else
    {
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
    tmp = NULL;
    delete tmp;

    cout << "La posicion selecionada es mayor a la cantidad de items en la lista";
    return NULL;
}
};  