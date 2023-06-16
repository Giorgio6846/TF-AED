#pragma once
 
#include "NodoLista.h"
#include "../Libraries.h"

template <class T>
struct dato
{
    int valor;
    T * dato;
};



template <class T>
class minHeap
{
private:
    dato<T>;
public:
    minHeap();
    ~minHeap();
};