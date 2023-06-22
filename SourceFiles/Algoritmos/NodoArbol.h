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
    NodoArbol(){
        l = NULL; r = NULL;
    };
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
    
    //balancear el arbol
    balancear(arbol);
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


  
    //imprimir valores en orden
    void imprimirEnOrden(NodoArbol* nodo) {
        if (nodo == nullptr) {
            return;
        }
        imprimirEnOrden(nodo->l);
        cout << "DNI asignada a la encomienda: " << getKeyDNI(nodo->nodo.key) <<endl;
        cout << "Tiempo estimado de viaje: " << (nodo->nodo.tiempoEnvio)/60 <<" horas" <<endl;
        imprimirEnOrden(nodo->r);
    }
    //Extrae solo la parte numérica de la KEY
    string getKeyDNI(string key){
        string dniKey = "";
        for (int i = 0; i < key.length() ; i++)
        {
            if (key[i] >= 48 && key[i] <=57 ){dniKey += key[i];}   
        }
        return dniKey;
    }

    //Calcula la altura del arbol de manera recursiva
    int calcularNodoAltura(NodoArbol *nodo){
        if (nodo == nullptr) return 0;
        int leftHeight = calcularNodoAltura(nodo->l);
        int rightHeight = calcularNodoAltura(nodo->r);
        return 1 + max(leftHeight, rightHeight);
    }

  //Funcion para balancear el arbol
    void balancear(NodoArbol *& arbol){
        int balance = calcularNodoAltura(arbol->l) - calcularNodoAltura(arbol->r);
        if (balance > 1){
          //rotacion izquierda
        }
        else if (balance < -1){
          //rotacion derecha
        }
    }
};
