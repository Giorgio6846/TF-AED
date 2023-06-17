#pragma once
#include <iostream>
#include "NodoLista.h"
#include "../VehiculoTransporte.h"

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

template <class T, class R, class W, R vacio = -1>
class Grafo
{
private:
    
    class AGrafo
    {
    public:
        R verticeOrigen;
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
            rGraf->verticeOrigen = info;
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

    // Al agregar un arco realizar el algoritmo de busqueda de nuevo

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

    //Al agregar un arco realizar el algoritmo de busqueda de nuevo

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

    //Modificar mas adelante
    bool disponiblesArco(R vertice, R llegada, int cantidadPasajeros)
    {
        NodoLista<T> * tmp = _accesoVertice(vertice) -> _accesoArco(llegada);
        for (; tmp != NULL; tmp = tmp -> nextElemento(tmp))
        {
            if (tmp->getElemento(tmp) -> cantidadDisponible >= cantidadPasajeros)
            {
                return 1;
            }           
        }
        return 0;
    }

    AGrafo * arcoInfo(R vertice, R llegadaVertice)
    {
        bool cond = 0;
        VGrafo *vTmp = _accesoVertice(vertice);
        if (vTmp != NULL)
        {
            AGrafo* aTmp = NULL;
            aTmp = vTmp->_accesoArco(llegadaVertice);
            if (aTmp == NULL)
            {
                cout << "EL arco no existe";
                return NULL;
            }
            else
            {
                return aTmp;
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

/*

Al realizar el algoritmo de Dijkstra este al ingresar un arco ingresarlo ya organizado


*/

/*

Incluir un nodo lista de un nodo lista
para agregar la ruta del bus a seguir
por ejemplo
Origen: 1
Destino: 4

Ruta 
1 - 3
3 - 6
6 - 4
Guarda de esto un una NodoLista y despues es agregado a otro nodo lista para ordenarlo de menor a mayor
*/

//NO SE PUEDEN ELIMINAR VERTICES
//Esta diseñado para que todos los vertices existan


/*
void rutaViaje(int Origen, int Destino, int cantidadPasajeros)
{
    struct TotalRuta
    {
        NodoLista <AGrafo> = NULL;
        int pesoEntero;
        string lugarRealizado;
    };
    

    //Genera un string con los lugares

    //0: No visitado
    //1: Origen
    //2: Destino

    string lugares = "";
    for (int i = 0; i < sizeGrafo(); i++)
    {
        if (i == Origen)
        {
            lugares = lugares + "1";
        }
        if else(i == Destino)
        {
            lugares = lugares + "2";
        }
        else
        {
            lugares = lugares + "0";
        }
    }

    //Aqui se genera un NodoLista de un NodoLista de los Arcos del grafo
    //Despues de organiza de menor a mayor para imprimir la ruta optima para el usuario
    NodoLista<TotalRuta> = NULL;

}
*/

//Esta diseñado para x Vertices
//Se pueden agregar o eliminar vertices
/*
struct TotalRuta
{
    NodoLista<Bus> * rutaAlDestino= NULL;
    int pesoEntero = 0;
};
*/
struct informacionArco
{
    NodoLista<AGrafo> * listArcs = NULL;
};

/*
Usuario seleciona
Origen, Destino y Cantidad de Pasajeros


Funcion 1:
        Operacion:
        Datos: Origen, Destino y Cantidad de Pasajeros

    Crea un Nodo con Lista Buses y un peso de ellos
    Invoca a Funcion 2:

    Funcion 2:
        Operacion: Accede al vertice
        Datos: Origen, Destino, Cantidad de Pasajeros, vector de Destinos accedidos

        A base de un for ingresa a cada arco del vertice
            Verificacion Invoca a la Funcion 3 == 1
                Si:
                    Agrega el bus a la lista de buses y el tiempo de duracion a la estructura TotalRuta
                    return 1;
                No:
                    Siguente Arco

    bool Funcion 3:
        Operacion: Accede al arco
        Datos: Origen, Destino, Cantidad de Pasajeros, Vector de Destinos Accedidos

        Accede al arco Bus *
        Verificacion destinoLlegada = Destino y Asientos Disponibles
            Si
                Regresa con el puntero del bus
                return 1
            No
                Verificacion: verticeDestinoLlegada esta en destinosAcedidos
                    Si
                        Accede al vertice del destinoLlegada
                        Invoca a la Funcion 2
                    No
                        return 0;

Este le va a retornar una lista de vehiculos para realizar su viaje
*/

/*
METODO DEL CANGREJO PE IZIZIIIZZIZIZIZIZIZIZIZIZIZ
Lo mismo :v
*/

struct TotalRuta
{
    NodoLista<Bus> *rutaAlDestino = NULL;
    int pesoEntero = 0;
};

// Actualmente solo funciona con buses
NodoLista<TotalRuta> *RutaFinal(R Origen, R Destino, int espacioDisponible)
{
    cout << "TEST";
    NodoLista<TotalRuta> * TRtmp = NULL;
    rutaVertice(Origen, Destino, espacioDisponible, NULL, NULL, TRtmp);

    cout << TRtmp -> contadorLista(TRtmp);
    return TRtmp;
}

void rutaVertice(R Origen, R Destino, int espacioDisponible, NodoLista<R> *verticesIdos, NodoLista<Bus> * listaBus, NodoLista<TotalRuta> *rutasTotales)
{
    NodoLista<R> * tmpVI = verticesIdos;
    if (tmpVI != NULL)
    {
        bool cond = 1;
        for (; tmpVI != NULL; tmpVI = tmpVI -> nextElemento(tmpVI))
        {
            if (*(tmpVI->getElemento(tmpVI)) == Origen)
            {
                cond = 0;
            }
        }
        if (cond)
        {
            R * rTmp = new R;
            *rTmp = Origen;
            verticesIdos->push(&verticesIdos, rTmp);
        }
    }
    else
    {
        R * rTmp = new R;
        *rTmp = Origen;
        verticesIdos->push(&verticesIdos, rTmp);
    }

    NodoLista<AGrafo> * tmpNdAgrafo = _accesoVertice(Origen)->ndArcos;

    for(; tmpNdAgrafo != NULL; tmpNdAgrafo = tmpNdAgrafo ->nextElemento(tmpNdAgrafo))
    {
        W * wTmp = verificacionVehiculo(tmpNdAgrafo->getElemento(tmpNdAgrafo), espacioDisponible);
        // Si existe un bus disponible accede al arco
        if (wTmp != NULL)
        {
            listaBus->push(&listaBus, wTmp);
            rutaArco(Origen, Destino, espacioDisponible, tmpVI, listaBus, rutasTotales);
        }
        // Si no existe un bus disponible va al siguente arco
    }
}   

// Actualmente solo funciona con buses

void rutaArco(R Origen, R Destino, int espacioDisponible, NodoLista<R> *verticesIdos, NodoLista<Bus> * listaBus, NodoLista<TotalRuta> *rutasTotales)
{
    AGrafo* tmpArco = NULL;
    tmpArco = arcoInfo(Origen, Destino);
    NodoLista<Bus> * listaBustmp = listaBus;
    
    //Si el arco llega al vertice de llegada crea un objeto TotalRuta para ingresar el dato
    if (tmpArco != NULL)
    {
        if (tmpArco->verticeLlegada == Destino)
        {
            W* tmpW = verificacionVehiculo(tmpArco, espacioDisponible);
            TotalRuta* tmpTR = new TotalRuta;
            tmpTR->rutaAlDestino = listaBus;
            rutasTotales->push(&rutasTotales, tmpTR);
        }
        // Si no existe no bus disponible va al vertice de llegada
        else
        {
            NodoLista<R>* tmpVI = verticesIdos;
            int cond = 1;
            for (; tmpVI != NULL; tmpVI = tmpVI->nextElemento(tmpVI))
            {
                if (*(tmpVI->getElemento(tmpVI)) == Origen)
                {
                    cond = 0;
                }
            }
            if (cond)
            {
                rutaVertice(tmpArco->verticeOrigen, tmpArco->verticeLlegada, espacioDisponible, verticesIdos, listaBustmp, rutasTotales);
            }
        }
    }
}


// Actualmente solo funciona con buses
/*
Dato retorno
Caso 1:
    Retorna la direccion del vehiculo disponible
Caso 2:
    Retorna NULL

*/
W *verificacionVehiculo(AGrafo *tmpArco, int espacioDisponible)
{
T *tmpDato = tmpArco->datos;
// NodoLista<Bus> * tmpDato = tmpArco->datos;
for (; tmpDato != NULL; tmpDato = tmpDato->nextElemento(tmpDato))
{
        if (tmpDato->getElemento(tmpDato)->getCantidadDisponible() >= espacioDisponible)
        {
            return tmpDato->getElemento(tmpDato);
        }
}
return NULL;
}

/*
struct ListaBuses
{
    NodoLista<Bus> * Buses = NULL;
    int duracionTiempo = 0;
};

// Actualmente solo funciona con buses
NodoLista<Bus> * RutaFinal(R Origen, R Destino, int cantidadPasajeros)
{   
    vector<R> verticesVisitados;
    
}

// Actualmente solo funciona con buses
NodoLista<TotalRuta> * rutaTotal(R Origen, R Destino, int cantidadPasajeros)
{
    NodoLista<TotalRuta> * tmp = NULL;
    
    vector<int> * tmp;
    rutaVertice(Origen, Destino, cantidadPasajeros, NULL);

}

// Actualmente solo funciona con buses
bool rutaVertice(R Origen, R Destino, int cantidadPasajeros, vector<R> * verticesIdos)
{
    verticesIdos->insert(Origen);
    VGrafo * tmpVertice = _accesoVertice(Origen);


}

// Actualmente solo funciona con buses

bool rutaArco(R Origen, R Destino, int espacioDisponible, vector<R> *verticesIdos)
{
    AGrafo * tmpArco = arcoInfo(Origen, Destino);
    NodoLista<Bus> *tmpBus = tmpArco->datos;

    if (tmpArco -> verticeLlegada == Destino)
    {
        W * tmpVehiculo = verificacionVehiculo(tmpArco, espacioDisponible);
        if(tmpVehiculo != NULL)
        {
            return 1;
        }
        
    }
    else
    {
        rutaVertice();
    }
   
}
*/




/*
TotalRuta *rutaSelecionada(int Origen, int Destino, int cantidadPasajeros, vector<int> verticesIdos)
{
    TotalRuta * trTmp = new TotalRuta();
    
    for (; tmp != NULL; tmp = tmp->nextElemento(tmp))
    {
            if (disponiblesArco(Origen, tmp->getElemento(tmp)->verticeLlegada, cantPasajeros))
            {
                tmp1->push(&tmp1, tmp->getElemento(tmp));
                return 1;
            }
    }
    return 0;
}
*/

/*
void rutaViaje(int Origen, int Destino, int cantidadPasajeros){
        
        
        0: No visitado
        1: Origen
        2: Destino
        Generacion string lugares
        
        string lugares = "";
        for (int i = 0; i < sizeGrafo(); i++)
        {
            if (i == Origen)
            {
                lugares = lugares + "1";
            }
            if
                else(i == Destino)
                {
                    lugares = lugares + "2";
                }
            else
            {
                lugares = lugares + "0";
            }
        }

        string *tmp = lugares;
        
NodoLista<TotalRuta> *rutasDisponibles = NULL;
TotalRuta *rutas = new TotalRuta();

informacionArco *arcVist = new informacionArco();
}
*/
/*

bool creacionRuta(R Origen, R Destino, NodoLista<TotalRuta> *truct, informacionArco *arcoVist)
{
    //Crea un NodoLista temporal con todos los arcos del vertice Origen
    NodoLista<AGrafo> *tmp = _accesoVertice(Origen) -> ndArcos();

    //Accede a cada arco
    for (int i = 0; i <= tmp->contadorLista() && tmp != NULL; i++)
    {
        if (tmp->getElemento(tmp)-> verticeLlegada == Destino)
        {
            TotalRuta * tmpS = new TotalRuta();
            NodoLista<AGrafo> *tmpA = tmpS->rutaAlDestino;
            tmpS->pesoEntero = tmp->getElemento(tmp)->pesoLlegada + tmpS->pesoEntero;
            tmpA->append(tmpA, tmp);
            tmpS->rutaAlDestino = tmpA;
            return 1;
        }

        if (creacionRuta(tmp->getElemento(tmp)->verticeLlegada, Destino, truct))
        {
            TotalRuta *tmpS = new TotalRuta();
            NodoLista<AGrafo> *tmpA = tmpS->rutaAlDestino;
            tmpS->pesoEntero = tmp->getElemento(tmp)->pesoLlegada + tmpS->pesoEntero;
            tmpA->append(tmpA, tmp);
            tmpS->rutaAlDestino = tmpA;
        }
        tmp->nextElemento(tmp);   
    }
    return 0;
}
*/
/*
bool creacionRutav2(R Origen, R Destino, NodoLista<TotalRuta> *truct, informacionArco *arcoVisit, int cantPasajeros)
{
    NodoLista<AGrafo> *tmp = _accesoVertice(Origen) -> ndArcos();
    
    for (; tmp != NULL; tmp = tmp->nextElemento(tmp))
    {
        if (disponiblesArco(Origen, tmp->getElemento(tmp)->verticeLlegada,cantPasajeros))
        {
            return 0;
        }   
    }
}
*/
/*
bool verArcoVisitado(informacionArco *infArc, AGrafo *tmpnam)
{
    informacionArco * aux = infArc;
    
    if (aux->listArcs->contadorLista(aux->listArcs) == 0)
    {
        return 0;
    }
    else
    {
    }
    return 0;
}
*/
/*
Por ejemplo O:1 D:5
Accede al Vertice 1 y obtiene los arcos del vertice 1
V1 A1 V2:
Accede al Vertice 2 y obtiene los arcos del vertice 2
    V2 A1 V1:
        Ya accedio al vertice 1 asi que no realiza el calculo
    V2 A3 V3:
        Accede al Vertice 3 y obtiene los arcos del vertice 3
    V2 A4 V4:

    V2 A5 V5:

V1 A2 V3:
Accede al Vertice 1 y obtiene los arcos del vertice 1

V1 A3 V4:
Accede al Vertice 1 y obtiene los arcos del vertice 1

V1 A4 V5:
Accede al Vertice 1 y obtiene los arcos del vertice 1

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int rigth(int i) { return 2 * i + 2; }

// MinHeap basado en tiempo estimado
void pushMin()
{

}

//MaxHeap basado en tiempo estimado
void pushMax()
{

}
*/
};
