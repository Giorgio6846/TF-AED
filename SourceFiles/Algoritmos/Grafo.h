#pragma once
#include <iostream>
#include "NodoLista.h"

/*

Grafo
Datos:
NodoLista de Vertices: Los vertices que tiene el grafo

Metodos:
    agregarVertice()
    agregarArcoVertice()
    eliminarVertice()
    accederArco()
    accederVertice()
    pesoArco()
    tamañoGrafo()

Vertice
    Datos:
    - Dato del vertice
    - NodoListas de Arcos del Vertice: Los arcos que tiene el vertice

Metodos:
    agregarArco()
    eliminarArco()
    accederArco()
    pesoArco()
    tamañoVertice()

Arco
    Datos:
        - Dato de llegada
        - Dato de peso de llegada
        - Dato de Arco - Para viajes este va a ser un NodoLista de Buses

Metodos:
    agregarDato()
    getDato()

*/

template <class T, class R, R vacio = -1>
class Grafo
{
private:
    
    class AGrafo
    {
    public:
        R verticeLlegada;
        int pesoLlegada;
        T * datos;

        AGrafo()
        {
        }
    };

    class VGrafo
    {
    public:
        R info;
        NodoLista<AGrafo> * ndArcos = NULL;
        VGrafo()
        {
            info = vacio;
        }

        void agregarArco(R llegadaVertice, int pesoLlegada, T * dato)
        {
            bool cond = 0;

            AGrafo *rGraf = new AGrafo();
            rGraf->verticeLlegada = llegadaVertice;
            rGraf->pesoLlegada = pesoLlegada;
            rGraf->datos = dato;

            AGrafo *tmp = _accesoArco(llegadaVertice);
            if (tmp == NULL)
            {
                ndArcos->push(&ndArcos, rGraf);
            }
            else
            {
                cout << "El arco al vertice de llegada ya existe";
            }            
        }
        
        int sizeVertice(){ return ndArcos -> contadorLista(ndArcos); }

        AGrafo * _accesoArco(R llegada)
        {
            bool cond = 0;
            NodoLista<AGrafo> *tmp = ndArcos;
            for (bool cond = 0; tmp != NULL && !cond; tmp = tmp->nextElemento(tmp))
            {
                if (tmp->getElemento(tmp)->verticeLlegada == llegada)
                {
                    cond = 1;
                    return tmp->getElemento(tmp);
                }
            }
            return NULL;
        }

        AGrafo *_accesoArcoPosicion(R posicion)
        {
            NodoLista<AGrafo> *tmp = ndArcos;
            for (int contador = 0; tmp != NULL && contador <= posicion; tmp = tmp->nextElemento(tmp))
            {
                if (contador == posicion)
                {
                    return tmp->getElemento(tmp);
                }
                contador++;
            }
            return NULL;
        }

    };

    NodoLista<VGrafo> *ndVertices = NULL;
    
public:
    Grafo(){}
    ~Grafo(){}

    void agregarVertice(R vertice)
    {
        bool cond = 0;
        VGrafo *VerV = _accesoVertice(vertice);
        VGrafo *tmpV = new VGrafo();
        tmpV-> info = vertice;

        if ( VerV == NULL)
        {
            ndVertices->push(&ndVertices, tmpV);
        }
    }

    void agregarArcoVertice(R vertice, R llegadaVertice, int pesoLlegada, T * dato)
    {
        VGrafo * tmp = _accesoVertice(vertice);

        if (tmp != NULL)
        {
            tmp->agregarArco(llegadaVertice, pesoLlegada, dato);
        }
        else
        {
            cout << "El vertice no existe";
        }
    }

    void imprimirVerticesGrafo()
    {
        NodoLista<VGrafo> * tmp = ndVertices;
        for (; tmp != NULL; tmp = tmp->nextElemento(tmp))
        {
            cout << tmp->getElemento(tmp)->info << " ";
        }
    }

    void imprmirArcosVertices(int vertice)
    {
        NodoLista<VGrafo> *Vtmp = ndVertices;
        for (; Vtmp != NULL; Vtmp = Vtmp->nextElemento(Vtmp))
        {
            cout << Vtmp->getElemento(Vtmp)->info << " ";
            NodoLista<AGrafo> *Atmp = Vtmp->getElemento(Vtmp)->ndArcos;
            for (; Atmp != NULL; Atmp = Atmp->nextElemento(Atmp))
            {
                cout << Atmp->getElemento(Atmp)->verticeLlegada;
            }
        }
    }

    void imprimirGrafo()
    {
        for (int i = 0; i < sizeGrafo(); i++)
        {
            cout << "Vertice: " << _accesoVerticePosicion(i)->info << endl << endl;
            for (int j = 0; j < _accesoVerticePosicion(i)->sizeVertice(); j++)
            {
                cout << "Rutas: " << _accesoVerticePosicion(i)->info << " con destino a " << _accesoVerticePosicion(i) -> _accesoArcoPosicion(j) -> verticeLlegada << " con duracion de " << _accesoVerticePosicion(i)->_accesoArcoPosicion(j)->pesoLlegada << endl;
            }
            cout << endl;
        }
    }

    void eliminarVertice()
    {
        
    }

    int pesoArco(R vertice, R llegadaVertice)
    {
        bool cond = 0;
        VGrafo *tmp = _accesoVertice(vertice);
        if (tmp->pesoArco(llegadaVertice) != NULL)
        {
            return tmp->pesoArco(llegadaVertice);
        }
        else
        {
            return 0;
        }
    }

    AGrafo *arcoInfo(R vertice, R llegadaVertice)
    {
        bool cond = 0;
        VGrafo *vTmp = _accesoVertice(vertice);
        if (vTmp != NULL)
        {
            if (vTmp->_accesoArco(llegadaVertice) != NULL)
            {
                cout << "EL arco no existe";
                return NULL;
            }
            else
            {
                return vTmp->_accesoArco(llegadaVertice);
            }
        }
        else
        {
            cout << "El vertice no existe";
        }
        return NULL;
    }

    VGrafo *_accesoVerticePosicion(R posicion)
    {
        NodoLista<VGrafo> *tmp = ndVertices;
        for (int contador = 0; tmp != NULL && contador <= posicion; tmp = tmp->nextElemento(tmp))
        {
            if (contador == posicion)
            {
                return tmp->getElemento(tmp);
            }
            contador++;
        }
        return NULL;
    }

    VGrafo * _accesoVertice(R vertice)
    {
        NodoLista<VGrafo> *tmp = ndVertices;

        for (bool cond = 0; tmp != NULL && !cond; tmp = tmp->nextElemento(tmp))
        {
            if (tmp->getElemento(tmp)->info == vertice)
            {
                cond = 1;
                return tmp->getElemento(tmp);
            }
        }
        return NULL;
    }

    int sizeGrafo()
    {
        return ndVertices->contadorLista(ndVertices);
    }


};