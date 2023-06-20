#pragma once
#include <iostream>
using namespace std;

struct valorNodo
{
    string key;
    int tiempoEnvio;
};


template <class T>
class NodoArbol
{
private:
    NodoArbol * l;
    NodoArbol * r;
    valorNodo nodo;
public:
    NodoArbol(){};
    ~NodoArbol(){};

    //n debe ser el primer valor del apellido para ser creado en orden alfabetico
    void insertarValor(NodoArbol *& arbol, string keys, T tiempoEnvio){
        if (arbol == nullptr)
        {
            NodoArbol * newNodo = crearNodo(keys, tiempoEnvio);
            arbol = newNodo;
        }
        else{
            int valorRaiz = arbol->nodo.tiempoEnvio;
            if (tiempoEnvio < valorRaiz)
            {
                insertarValor(arbol->l, keys, tiempoEnvio);
            }
            else{
                insertarValor(arbol->r, keys, tiempoEnvio);
            }       
        }
    }

    NodoArbol* crearNodo(string keys, T tiempoEnvio){
        valorNodo nodoAux;
        nodoAux.key=keys; nodoAux.tiempoEnvio = tiempoEnvio; 
        NodoArbol * newNodo = new NodoArbol();
        newNodo->nodo=nodoAux;
        newNodo->r=nullptr;
        newNodo->l=nullptr;
        return newNodo;
    }

    //Recorre el arbol desde abajo hacia arriba
    void recorrerArbol(NodoArbol *arbol)
{   
    if (arbol == NULL){return;}
    else
    {
        recorrerArbol(arbol->r);
        //Funcion que quiera que haga al recorrer ( de abajo hacia arriba)
        recorrerArbol(arbol->l);
    }
}
};
