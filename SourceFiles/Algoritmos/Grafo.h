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
            info = vacio;
        }
        void agregarArco(R llegadaVertice, int pesoLlegada, T dato)
        {
            bool cond = 0;

            AGrafo *rGraf = new AGrafo();
            rGraf->verticeLlegada = llegadaVertice;
            rGraf->pesoLlegada = pesoLlegada;
            rGraf->datos = dato;

            if (_accesoArco(llegadaVertice) != NULL)
            {
                cout << "El arco al vertice de llegada ya existe";
            }
            else
            {
                ndArcos->push(&ndArcos, rGraf);
            }            
        }
        int sizeVertice(){ return ndArcos -> contadorLista(ndArcos); }
        int pesoArco(R llegada)
        {
            AGrafo * tmp = _accesoArco(llegada);
            if (tmp != NULL)
            {
                return tmp->pesoLlegada;
            }
            else
            {
                return 0;
            }        
        }
        AGrafo * _accesoArco(R llegada)
        {
            bool cond = 0;
            NodoLista<AGrafo> *tmp = ndArcos;
            while (tmp != NULL && !cond)
            {
                if (tmp->getElemento(tmp)->verticeLlegada == llegada)
                {
                    return tmp->getElemento(tmp);
                    cond = 1;
                }
                tmp = tmp->nextElemento(tmp);
            }
            if (cond == 0)
            {
                cout << "No existe el vertice de llegada";
            }
            return NULL;
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

    void agregarArcoVertice(R vertice, R llegadaVertice, int pesoLlegada, T dato)
    {
        bool cond = 0;
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

    void imprimirVerticesTest()
    {
        int a;
        cout << sizeGrafo() << endl << endl;
        for (int i = 0; i < sizeGrafo(); i++)
        {
            a = _accesoVertice(i) -> info;
            cout << a << endl;
        }
    }

    void eliminarVertice()
    {
        /*
        
        */
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
            AGrafo *aTmp = vTmp->_accesoArco(llegadaVertice);
        }
        else
        {
            cout << "El vertice no existe";
        }
    }

    VGrafo * _accesoVertice(R vertice)
    {
        bool cond = 0;
        NodoLista<VGrafo> *tmp = ndVertices;
        while (tmp != NULL && !cond)
        {
            if (tmp->getElemento(tmp)->info == vertice)
            {
                return tmp->getElemento(tmp);
                cond = 1;
            }
            tmp = tmp->nextElemento(tmp);
        }
        return NULL;
    }

    int sizeGrafo()
    {
        return ndVertices->contadorLista(ndVertices);
    }
};

