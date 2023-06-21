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
    int altura;
public:
    NodoArbol(){};
    ~NodoArbol(){};

    //n debe ser el primer valor del apellido para ser creado en orden alfabetico
    void insertarValor(NodoArbol *& arbol, string keys, T tiempoEnvio){
        if (arbol == nullptr)
        {
            NodoArbol * newNodo = crearNodo(keys, tiempoEnvio);
            arbol = newNodo;
            return;
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
    
    actualizarAltura(arbol);

    int balanceFactor = getNodoAltura(arbol->l) - getNodoAltura(arbol->r);

    // Left-Left Case
    if (balanceFactor > 1 && tiempoEnvio < arbol->l->nodo.tiempoEnvio)
    {
        rotarDerecha(arbol);
    }
    // Right-Right Case
    else if (balanceFactor < -1 && tiempoEnvio > arbol->r->nodo.tiempoEnvio)
    {
        rotarIzquierda(arbol);
    }
    // Left-Right Case
    else if (balanceFactor > 1 && tiempoEnvio > arbol->l->nodo.tiempoEnvio)
    {
        rotarIzquierda(arbol->l);
        rotarDerecha(arbol);
    }
    // Right-Left Case
    else if (balanceFactor < -1 && tiempoEnvio < arbol->r->nodo.tiempoEnvio)
    {
        rotarDerecha(arbol->r);
        rotarIzquierda(arbol);
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

    void rotarDerecha(NodoArbol *& nodo){
        NodoArbol * pivot = nodo->l;
        nodo->l = pivot->r;
        pivot->r = nodo;
        actualizarAltura(nodo);
        actualizarAltura(pivot);
        nodo = pivot;
    }

    void rotarIzquierda(NodoArbol *& nodo){
        NodoArbol *pivot = nodo->l;
        nodo->l = pivot->r;
        pivot->r = nodo;
        actualizarAltura(nodo);
        actualizarAltura(pivot);
        nodo = pivot;
    }

    int getNodoAltura(NodoArbol *nodo){return nodo->altura;}

    void actualizarAltura(NodoArbol * nodo){nodo->altura = max(getNodoAltura(nodo->l), getNodoAltura(nodo->r)) + 1;}

    //Calcula la altura del arbol de manera recursiva
    int calcularNodoAltura(NodoArbol *nodo){
    if (nodo == nullptr) return 0;
    int leftHeight = calculateHeight(nodo->l);
    int rightHeight = calculateHeight(nodo->r);
    return 1 + max(leftHeight, rightHeight);
    }
};
