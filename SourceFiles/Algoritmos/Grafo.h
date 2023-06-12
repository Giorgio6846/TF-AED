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
        T datos;

        AGrafo()
        {
        }

        void agregarDato(T datos) { this -> datos = datos; }
        T getDato(){ return datos; }
    };

    class VGrafo
    {
    public:
        R info;
        NodoLista<AGrafo> *ndArcos = NULL;
        VGrafo()
        {
            infoVertice = vacio;
        }
        void agregarArco(R llegadaVertice, int pesoLlegada, T dato)
        {
            bool cond = 0;

            AGrafo *rGraf = new AGrafo();
            rGraf->llegadaVertice = llegadaVertice;
            rGraf->pesoLlegada = pesoLlegada;
            rGraf->dato = dato;

            while (arcosVertice != NULL || !cond)
            {
                if (arcosVertice->getElemento(arcosVertice)->llegadaVertice == llegadaVertice)
                {   
                    cond = 1;
                }
                arcosVertice->nextElemento(arcosVertice);
            }
            if (cond)
            {
                arcosVertice->push(&arcosVertice, rGraf);
            }
            else
            {
                cout << "El arco al vertice de llegada ya existe";
            }
        }

        int sizeVertice(){ return ndArcos -> contadorLista(ndArcos); }
        int pesoArco(R llegada)
        {
            cond = 0;
            NodoLista<AGrafo> *tmp = ndArcos;
            while (ndArcos != NULL && !cond)
            {
                if (tmp->getElemento(tmp)->verticeLlegada == llegada)
                {
                    return tmp->getElemento(tmp)->pesoLLegada;
                    cond = 1;
                }
                tmp->nextElemento(tmp);
            }
            if (cond == 0)
            {
                coud << "No existe el vertice de llegada";
            }   
        }
        AGrafo * accederGrafo(R llegada)
        {
            cond = 0;
            NodoLista<AGrafo> *tmp = ndArcos;
            while (ndArcos != NULL && !cond)
            {
                if (tmp->getElemento(tmp)->verticeLlegada == llegada)
                {
                    return tmp->getElemento(tmp);
                    cond = 1;
                }
                tmp->nextElemento(tmp);
            }
            if (cond == 0)
            {
                coud << "No existe el vertice de llegada";
            }
        }

    };

    NodoLista<VGrafo> *ndVertices = NULL;
    
public:
    Grafo(/* args */)
    {

    }
    ~Grafo()
    {

    }

    void agregarVertice(R inf)
    {
        bool cond = 0;

        VGrafo *vGraf = new VGrafo();
        vGraf -> infoVertice = inf;
        
        while (vertices != NULL || !cond)
        {
            if (vertices->getElemento(vertices)->infoVertice == inf)
            {
                cond = 1;
            }
            vertices->nextElemento(vertices);
        }
        if (cond)
        {
            cout << "El arco al vertice de llegada ya existe";
        }
        else
        {
            vertices->push(&vertices, vGraf);
        }
    }

    void agregarArco(R vertice, R llegadaVertice, int pesoLlegada, T dato)
    {
        bool cond = 0;
        while (vertices != NULL || !cond)
        {
            if (vertices->getElemento(vertices)->infoVertice == vertice)
            {
                vertices->getElemento(vertices)->agregarArco(llegadaVertice,pesoLlegada, dato);
                vertices->nextElemento(vertices);
            }   
        }
    }

    void imprimirVerticesTest()
    {
        while (vertices != NULL)
        {
            cout << vertices->getElemento(vertices)->infoVertice;
            vertices->nextElemento(vertices);
        }
    }

    int cantidadVertices()
    {
        return vertices->contadorLista(vertices);
    }
};

