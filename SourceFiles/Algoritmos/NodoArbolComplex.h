#include "../Libraries.h"

template <class T>
class NodoArbolComplex
{
private:
    NodoArbolComplex * left;
    NodoArbolComplex * right;
    int n;
    T data;
    
    /*
    NodoArbolComplex *crearNodo(int n, T data)
    {
        NodoArbolComplex *newNodo = new NodoArbolComplex<T>();
        newNodo->n = n;
        newNodo->data = data;
        newNodo->right = nullptr;
        newNodo->left = nullptr;
        return newNodo;
    }
    */

public:
    NodoArbolComplex()
    {
    }
    ~NodoArbolComplex(){};

    int getN(){return n;}
    T getData(){return data;}

    void deleteNodo(NodoArbolComplex<T> *nodo)
    {
        if (nodo)
        {
            if(nodo->left) deleteNodo(nodo->left);
            if(nodo->right) deleteNodo(nodo->right);
        }
        delete nodo;
    }

    //n debe ser el primer valor del apellido para ser creado en orden alfabetico
    NodoArbolComplex * insertarValor(NodoArbolComplex *nodo, int n, T data)
    {
        
        if (nodo == NULL)    
        {
            nodo = new NodoArbolComplex();
            n = n;
            data = data;
            nodo -> left = NULL;
            nodo -> right = NULL;

            //arbol = crearNodo(n, data);
        }
        else{
            if (n < nodo->n)
            {
                nodo->left = insertarValor(nodo->left, n, data);
            }
            else
            {
                nodo->right = insertarValor(nodo->right, n, data);
            }       
        }
    return nodo;
    }
/*
    NodoArbolComplex *remover(NodoArbolComplex<T> *&arbol, int n)
    {
        NodoArbolComplex<T> * tmp;
        if(arbol == NULL)
        {
            return NULL;
        }
        else if(n < arbol->n)
        {
            arbol->left = remover(arbol, n);
        }
        else if(n > arbol->n)
        {
            arbol->right = remover(arbol,n);
        }
        else
        {
            tmp = arbol;
            if (arbol -> left == NULL)
            {
                arbol = arbol->right;
            }
            else if(arbol->right == NULL)
            {
                arbol = arbol -> left;
            }
            delete tmp;
        }

        return arbol;
    }
*/
    //Recorre el arbol desde abajo hacia arriba
    void recorrerArbol(NodoArbolComplex *nodo)
    {
    if (nodo == NULL){}
    else
    {
        recorrerArbol(nodo->right);
        //Funcion que quiera que haga al recorrer ( de abajo hacia arriba)
        recorrerArbol(nodo->left);
    }
    }

    NodoArbolComplex buscar(NodoArbolComplex *nodo, int n)
    {
        if (nodo == NULL)
        {
            return NULL;
        }
        else if(n < nodo->n)
        {
            return buscar(nodo->left, n);
        }
        else if(n > nodo->n)
        {
            return buscar(nodo->right,n);
        }
        
    }

    T buscarNodoArbol(NodoArbolComplex *nodo, int val)
    {
        if(nodo == NULL)
        {
            return NULL;
        }
        //else if (this -> n == n)
        //{
        //    return this->data;
        //}
        else if (n == val)
        {
            return data;
        }
        else if (val < n)
        {
           return buscarNodoArbol(nodo->left, val);
        }
        else if (val > n)
        {
           return buscarNodoArbol(nodo->right, val);
        }
        return NULL;
        
        /*

        if(raiz == NULL || raiz -> n == n)
        {
            return raiz;
        }
        if(raiz -> n < n)
        {
            return buscarNodoArbol(raiz->right, n);
        }
        return buscarNodoArbol(raiz->left, n);
        */
        /*

        if (raiz->n == n)
        {
            return data;
        }
        if (raiz == NULL)
        {
            return raiz;
        }
        else
        {
            recorrerArbol(raiz->right);
            // Funcion que quiera que haga al recorrer ( de abajo hacia arriba)
            recorrerArbol(raiz->left);
        }
        */
    }
};
