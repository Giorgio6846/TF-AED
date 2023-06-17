#pragma once
#include "../Libraries.h"
#include "NodoLista.h"

template <class T>
class NodoArbolComplexv2
{
private:
    struct nodo
    {
        int n;
        T data;
        NodoLista<nodo> *nodos;
    };

    nodo *raiz;

    nodo *limpiarArbol(nodo *t)
    {
        if (t == NULL)
            return NULL;
        else
        {
            for (; t->nodos != NULL; t->nodos = (t->nodos)->nextElemento(t->nodos))
            {
                limpiarArbol(t->nodos->getElemento(t->nodos));
            }
        }
        delete t;
    }

    nodo *insertar(nodo *t, int n, T data)
    {
        if (t == NULL)
        {
            t = new nodo;
            t->data = data;
            t->n = n;
            t->nodos = NULL;
        }
        
        return t;

        else if (n < t->n)
        {
            t->left = insertar(t->left, n, data);
        }
        else if (n > t->n)
        {
            t->right = insertar(t->right, n, data);
        }
        return t;
    }

    nodo *buscar(nodo *t, int n)
    {
        if (t == NULL)
        {
            return NULL;
        }
        else if (n < t->n)
        {
            return buscar(t->left, n);
        }
        else if (n > t->n)
        {
            return buscar(t->right, n);
        }
        else
        {
            return t;
        }
    }

public:
    NodoArbolComplexv2(/* args */)
    {
    }
    ~NodoArbolComplexv2()
    {
        raiz = limpiarArbol(raiz);
    }

    void remover(int n)
    {
        raiz = remover(n, raiz);
    }

    void insertar(int n, T data)
    {
        raiz = insertar(raiz, n, data);
    }

    T buscar(int n)
    {
        nodo *tmp = new nodo;
        tmp = buscar(raiz, n);
        return tmp->data;
    }
};
