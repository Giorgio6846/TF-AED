#include "Libraries.h"
#include "Persona.h"
#pragma once
class NodoLista
{
public:

    Persona * cliente;
    NodoLista * next;

public:
    NodoLista(){};
    ~NodoLista(){};
    
    void insertarElementoLista(NodoLista **lista, Persona * cliente){
        //Se crea un nuevo nodo
        system("CLS");
        NodoLista * nuevoNodo = new NodoLista();
        nuevoNodo->cliente = cliente;
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
        cout << "Su datos han sido registrada de manera satisfactoria!" << endl;
        }

    void printClientes(NodoLista* lista){
        //Mientras no se llegue al final de lista, mostrar los datos de los clientes almacenados
        system("CLS");
        while (lista != NULL)
        {
            cout << "Nombre: " << lista->cliente->getNombre() << endl;
            cout << "Apellido: " << lista->cliente->getApellido() << endl;
            cout << "Edad: " << lista->cliente->getEdad() << endl;
            lista = lista->next;
        }
    }
};




