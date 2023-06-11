#include <iostream>
using namespace std;

class NodoArbol
{
private:
    NodoArbol * l;
    NodoArbol * r;
    int n;
public:
    NodoArbol(){};
    ~NodoArbol(){};

    //n debe ser el primer valor del apellido para ser creado en orden alfabetico
    void insertarValor(NodoArbol *& arbol, int n){
        if (arbol == nullptr)
        {
            NodoArbol * newNodo = crearNodo(n);
            arbol = newNodo;
        }
        else{
            int valorRaiz = arbol->n;
            if (n < valorRaiz)
            {
                insertarValor(arbol->l, n);
            }
            else{
                insertarValor(arbol->r, n);
            }       
        }
    }

    NodoArbol* crearNodo(int n){
        NodoArbol * newNodo = new NodoArbol();
        newNodo->n=n;
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
