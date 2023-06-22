#pragma once
#include "../Libraries.h"

#include "NodoLista.h"

template<class Z>
struct TotalRuta
{
    NodoLista<Z> *rutaAlDestino = NULL;
    int pesoEntero = 0;
};

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
        }
        
        int sizeVertice(){ return ndArcos -> contadorLista(ndArcos); }

        AGrafo * _accesoArco(R llegada)
        {
            NodoLista<AGrafo> *tmp = ndArcos;
            for (bool cond = 0; tmp != NULL && !cond; tmp = tmp->nextElemento(tmp))
            {
                if (tmp->getElemento(tmp)->verticeLlegada == llegada)
                {
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
            VGrafo *tmp = _accesoVertice(vertice);
            if (tmp->pesoArco(llegadaVertice) != NULL)
            {
                return tmp->pesoArco(llegadaVertice);
            }
            return 0;
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
                if (aTmp != NULL)
                {
                    return aTmp;
                }
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

        void sumaPesos(NodoLista<TotalRuta<W>> *TotRut)
        {
            NodoLista<TotalRuta<W>> *TRtmp = NULL;
            TRtmp = TotRut;

            for (; TRtmp != NULL; TRtmp = TRtmp->nextElemento(TRtmp))
            {
                TotalRuta<W> *TRStmp = new TotalRuta<W>();
                TRStmp = TRtmp->getElemento(TRtmp);
                NodoLista<W> *wTmp = NULL;
                wTmp = TRStmp->rutaAlDestino;
                for (; wTmp != NULL; wTmp = wTmp->nextElemento(wTmp))
                {
                    TRStmp->pesoEntero = TRStmp->pesoEntero + wTmp->getElemento(wTmp)->gettiempoEstimado();
                }
            }
        }

        bool verticeVisitado(R Origen, NodoLista<R> * verticesIdos)
        {
            NodoLista<R> *tmpVI = verticesIdos;
            if (tmpVI == NULL)
            {
                return 0;
            }

            for (; tmpVI != NULL; tmpVI = tmpVI->nextElemento(tmpVI))
            {
                    if (*(tmpVI->getElemento(tmpVI)) == Origen)
                    {
                        return 1;
                    }
            }
            
            return 0;
        }

        TotalRuta<W> *rutaFinal(R Origen, R Destino, int espacioRequerido)
        {
            //cout << "TEST";
            NodoLista<TotalRuta<W>> *rutaFinalNL = NULL;

            NodoLista<R> * NLItmp = NULL;
            NodoLista<W> * NLVTtmp = NULL;

            rutaVertice(Origen, Destino, espacioRequerido, NLItmp, NLVTtmp, rutaFinalNL);
            sumaPesos(rutaFinalNL);

            TotalRuta<W> *TRtmp = new TotalRuta<W>;
            TRtmp->pesoEntero = 999999;

            NodoLista<TotalRuta<W>> *rutaFinalNLtmp = NULL;
            rutaFinalNLtmp = rutaFinalNL;
            for (; rutaFinalNLtmp != NULL; rutaFinalNLtmp = rutaFinalNLtmp->nextElemento(rutaFinalNLtmp))
            {
                if (rutaFinalNLtmp->getElemento(rutaFinalNLtmp)->pesoEntero < TRtmp->pesoEntero)
                {
                    TRtmp->pesoEntero = rutaFinalNLtmp->getElemento(rutaFinalNLtmp)->pesoEntero;
                    TRtmp->rutaAlDestino = rutaFinalNLtmp->getElemento(rutaFinalNLtmp)->rutaAlDestino;
                }        
            }
            
            return TRtmp;
        }

        void rutaVertice(R Origen, R Destino, int espacioDisponible, NodoLista<R> *& verticesIdos, NodoLista<W> *& listaVehiculo, NodoLista<TotalRuta<W>> *& rutasTotales)
        {
            NodoLista<R> * tmpVI;
            tmpVI->duplicadoLista(&verticesIdos, &tmpVI);

            if (!verticeVisitado(Origen, tmpVI))
            {
                R *rTmp = new R;
                *rTmp = Origen;
                verticesIdos->push(&verticesIdos, rTmp);
            }
            
            tmpVI = verticesIdos;
            NodoLista<AGrafo> * tmpNdAgrafo = _accesoVertice(Origen)->ndArcos;

            for(; tmpNdAgrafo != NULL; tmpNdAgrafo = tmpNdAgrafo ->nextElemento(tmpNdAgrafo))
            {
                W * wTmp = verificacionVehiculo(tmpNdAgrafo->getElemento(tmpNdAgrafo), espacioDisponible);
                // Si existe un bus disponible accede al arco
                if (wTmp != NULL)
                {
                    NodoLista<W> *busTMP;
                    busTMP->duplicadoLista(&listaVehiculo, &busTMP);
                    busTMP->append(&busTMP, wTmp);
                    rutaArco(tmpNdAgrafo->getElemento(tmpNdAgrafo), Destino, espacioDisponible, tmpVI, busTMP, rutasTotales);
                }
                // Si no existe un bus disponible va al siguente arco
            }
        }

    // Actualmente solo funciona con buses

        void rutaArco(AGrafo * ArcoTMP, int DestinoFinal, int espacioDisponible, NodoLista<R> *& verticesIdos, NodoLista<W> *& listaVehiculo, NodoLista<TotalRuta<W>> *& rutasTotales)
        {
            AGrafo * tmpArco = ArcoTMP;

            NodoLista<W> *listaVehiculotmp;
            listaVehiculotmp->duplicadoLista(&listaVehiculo, &listaVehiculotmp);

            //Si el arco llega al vertice de llegada crea un objeto TotalRuta para ingresar el dato
            if (tmpArco->verticeLlegada == DestinoFinal)
            {
                W* tmpW = verificacionVehiculo(tmpArco, espacioDisponible);
                TotalRuta<W> *tmpTR = new TotalRuta<W>;
                tmpTR->rutaAlDestino = listaVehiculotmp;
                rutasTotales->push(&rutasTotales, tmpTR);
                return;
            }

            // Si no existe no bus disponible va al vertice de llegada
            if (!verticeVisitado(ArcoTMP->verticeLlegada, verticesIdos))
            {
                rutaVertice(tmpArco->verticeLlegada, DestinoFinal, espacioDisponible, verticesIdos, listaVehiculotmp, rutasTotales);
            }
        }

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
};