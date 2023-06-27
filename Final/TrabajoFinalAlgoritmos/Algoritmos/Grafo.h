#pragma once
#include "../Libraries.h"

#include "NodoLista.h"
#include "HashTable.h"

template<class Z>
struct TotalRuta
{
    int Origen;
    int Destino;
    NodoLista<Z> *rutaAlDestino = nullptr;
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
        NodoLista<AGrafo> * ndArcos = nullptr;
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
            if (tmp == nullptr)
            {
                ndArcos->push(&ndArcos, rGraf);
                delete tmp;
            }
            
        }
        
        int sizeVertice(){ return ndArcos -> contadorLista(ndArcos); }

        AGrafo * _accesoArco(R llegada)
        {
            NodoLista<AGrafo> *tmp = ndArcos;
            for (bool cond = 0; tmp != nullptr && !cond; tmp = tmp->nextElemento(tmp))
            {
                if (tmp->getElemento(tmp)->verticeLlegada == llegada)
                {
                    return tmp->getElemento(tmp);
                }
            }
            tmp = nullptr;
            delete tmp;
            return nullptr;
        }

        AGrafo *_accesoArcoPosicion(R posicion)
        {
            NodoLista<AGrafo> *tmp = ndArcos;
            for (int contador = 0; tmp != nullptr && contador <= posicion; tmp = tmp->nextElemento(tmp))
            {
                if (contador == posicion)
                {
                    return tmp->getElemento(tmp);
                }
                contador++;
            }
            tmp = nullptr;
            delete tmp;
            return nullptr;
        }

    };

    HashTable<TotalRuta<W>> htRutaViaje;
    NodoLista<VGrafo> *ndVertices = nullptr;

    public:
        Grafo()
        {
        htRutaViaje.setSize(12);
        }
        ~Grafo(){}

        string genKey(int Origen, int Destino)
        {
            return to_string(Origen)+to_string(Destino);
        }

        void agregarVertice(R vertice)
        {
            bool cond = 0;
            VGrafo *VerV = _accesoVertice(vertice);
            VGrafo *tmpV = new VGrafo();
            tmpV-> info = vertice;

            if ( VerV == nullptr)
            {
                ndVertices->push(&ndVertices, tmpV);
            }

            VerV = nullptr;
            delete VerV;
        }

        void agregarArcoVertice(R vertice, R llegadaVertice, int pesoLlegada, T * dato)
        {
            VGrafo * tmp = _accesoVertice(vertice);

            if (tmp != nullptr)
            {
                tmp->agregarArco(llegadaVertice, pesoLlegada, dato);
            }
            tmp = nullptr;
            delete tmp;
        }

        void imprimirVerticesGrafo()
        {
            NodoLista<VGrafo> * tmp = ndVertices;
            for (; tmp != nullptr; tmp = tmp->nextElemento(tmp))
            {
                cout << tmp->getElemento(tmp)->info << " ";
            }
            tmp = nullptr;
            delete tmp;
        }

        void imprmirArcosVertices(int vertice)
        {
            NodoLista<VGrafo> *Vtmp = ndVertices;
            for (; Vtmp != nullptr; Vtmp = Vtmp->nextElemento(Vtmp))
            {
                cout << Vtmp->getElemento(Vtmp)->info << " ";
                NodoLista<AGrafo> *Atmp = Vtmp->getElemento(Vtmp)->ndArcos;
                for (; Atmp != nullptr; Atmp = Atmp->nextElemento(Atmp))
                {
                    cout << Atmp->getElemento(Atmp)->verticeLlegada;
                }
                Atmp = nullptr;
                delete Atmp;
            }
            Vtmp = nullptr;
            delete Vtmp;
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
            if (tmp->pesoArco(llegadaVertice) != nullptr)
            {
                return tmp->pesoArco(llegadaVertice);
            }
            tmp = nullptr;
            delete tmp;
            return 0;
        }

        bool disponiblesArco(R vertice, R llegada, int cantidadPasajeros)
        {
            NodoLista<T> * tmp = _accesoVertice(vertice) -> _accesoArco(llegada);
            for (; tmp != nullptr; tmp = tmp -> nextElemento(tmp))
            {
                if (tmp->getElemento(tmp) -> cantidadDisponible >= cantidadPasajeros)
                {
                    tmp = nullptr;
                    delete tmp;
                    return 1;
                }           
            }
            return 0;
        }

        AGrafo * arcoInfo(R vertice, R llegadaVertice)
        {
            bool cond = 0;
            VGrafo *vTmp = _accesoVertice(vertice);
            if (vTmp != nullptr)
            {
                AGrafo* aTmp = nullptr;
                aTmp = vTmp->_accesoArco(llegadaVertice);

                vTmp = nullptr;
                delete vTmp;

                if (aTmp != nullptr)
                {
                    return aTmp;
                }
                aTmp = nullptr;
                delete aTmp;
            }
            return nullptr;
        }

        VGrafo *_accesoVerticePosicion(R posicion)
        {
            NodoLista<VGrafo> *tmp = ndVertices;
            for (int contador = 0; tmp != nullptr && contador <= posicion; tmp = tmp->nextElemento(tmp))
            {
                if (contador == posicion)
                {
                    return tmp->getElemento(tmp);
                }
                contador++;
            }
            tmp = nullptr;
            delete tmp;
            return nullptr;
        }

        VGrafo * _accesoVertice(R vertice)
        {
            NodoLista<VGrafo> *tmp = ndVertices;

            for (bool cond = 0; tmp != nullptr && !cond; tmp = tmp->nextElemento(tmp))
            {
                if (tmp->getElemento(tmp)->info == vertice)
                {
                    cond = 1;
                    return tmp->getElemento(tmp);
                }
            }
            tmp = nullptr;
            delete tmp;
            return nullptr;
        }

        int sizeGrafo()
        {
            return ndVertices->contadorLista(ndVertices);
        }

        void sumaPesos(NodoLista<TotalRuta<W>> *TotRut)
        {
            NodoLista<TotalRuta<W>> *TRtmp = nullptr;
            TRtmp = TotRut;

            for (; TRtmp != nullptr; TRtmp = TRtmp->nextElemento(TRtmp))
            {
                TotalRuta<W> *TRStmp = new TotalRuta<W>();
                TRStmp = TRtmp->getElemento(TRtmp);
                NodoLista<W> *wTmp = nullptr;
                wTmp = TRStmp->rutaAlDestino;
                for (; wTmp != nullptr; wTmp = wTmp->nextElemento(wTmp))
                {
                    TRStmp->pesoEntero = TRStmp->pesoEntero + wTmp->getElemento(wTmp)->gettiempoEstimado();
                }

                TRStmp = nullptr;
                delete TRStmp;

                wTmp = nullptr;
                delete wTmp;
            }

            TRtmp = nullptr;
            delete TRtmp;
        }

        bool verticeVisitado(R Origen, NodoLista<R> * verticesIdos)
        {
            NodoLista<R> *tmpVI = verticesIdos;
            if (tmpVI == nullptr)
            {
                tmpVI = nullptr;
                delete tmpVI;
                return 0;
            }

            for (; tmpVI != nullptr; tmpVI = tmpVI->nextElemento(tmpVI))
            {
                    if (*(tmpVI->getElemento(tmpVI)) == Origen)
                    {
                        tmpVI = nullptr;
                        delete tmpVI;
                        return 1;
                    }
            }
            
            tmpVI = nullptr;
            delete tmpVI;
            return 0;
        }

        TotalRuta<W> * generadorRuta(R Origen, R Destino, int espacioRequerido)
        {
            list<TotalRuta<W> *> listRV = htRutaViaje.buscarListaRutas(genKey(Origen, Destino));
            bool cond = 1;
            for (auto *it : listRV)
            {
                if(it->Origen == Origen && it -> Destino == Destino)
                {
                    if (verificacionVehiculoRuta(it->rutaAlDestino,espacioRequerido))
                    {
                        return it;
                    }
                    else
                    {
                        it = nullptr;
                    }
                }
            }
            listRV.clear();

            TotalRuta<W>* trWTMP;
            if(cond)
            {
                trWTMP = rutaFinalNueva(Origen, Destino, espacioRequerido);
                htRutaViaje.insert(genKey(trWTMP->Origen, trWTMP->Destino), trWTMP);
                return trWTMP;
            }
            
            trWTMP = nullptr;
            delete trWTMP;

            return nullptr;
        }

        TotalRuta<W> *rutaFinalNueva(R Origen, R Destino, int espacioRequerido)
        {
            NodoLista<TotalRuta<W>> *rutaFinalNL = nullptr;

            NodoLista<R> * NLItmp = nullptr;
            NodoLista<W> * NLVTtmp = nullptr;

            rutaVertice(Origen, Destino, espacioRequerido, NLItmp, NLVTtmp, rutaFinalNL);

            NLItmp = nullptr;
            NLVTtmp = nullptr;
            delete NLItmp;
            delete NLVTtmp;

            sumaPesos(rutaFinalNL);

            TotalRuta<W> *TRtmp = new TotalRuta<W>;
            TRtmp->pesoEntero = 999999;

            NodoLista<TotalRuta<W>> *rutaFinalNLtmp = rutaFinalNL;
            for (; rutaFinalNLtmp != nullptr; rutaFinalNLtmp = rutaFinalNLtmp->nextElemento(rutaFinalNLtmp))
            {
                if (rutaFinalNLtmp->getElemento(rutaFinalNLtmp)->pesoEntero < TRtmp->pesoEntero)
                {
                    TRtmp = rutaFinalNLtmp->getElemento(rutaFinalNLtmp);
                    TRtmp->Origen=Origen;
                    TRtmp->Destino = Destino;
                }        
            }

            rutaFinalNLtmp = nullptr;
            delete rutaFinalNLtmp;

            return TRtmp;
        }

        void rutaVertice(R Origen, R Destino, int espacioDisponible, NodoLista<R> *&verticesIdos, NodoLista<W> *&listaVehiculo, NodoLista<TotalRuta<W>> *&rutasTotales)
        {
            NodoLista<R> * tmpVI;
            tmpVI->duplicadoLista(&verticesIdos, &tmpVI);
            //NodoLista<R>* tmpVI = new NodoLista<R>;
            //tmpVI = verticesIdos;

            if (!verticeVisitado(Origen, tmpVI))
            {
                R *rTmp = new R;
                *rTmp = Origen;
                verticesIdos->push(&verticesIdos, rTmp);
            }
            
            tmpVI = verticesIdos;
            NodoLista<AGrafo> * tmpNdAgrafo = _accesoVertice(Origen)->ndArcos;

            for(; tmpNdAgrafo != nullptr; tmpNdAgrafo = tmpNdAgrafo ->nextElemento(tmpNdAgrafo))
            {
                // Si existe un bus disponible accede al arco
                if (verificacionVehiculo(tmpNdAgrafo->getElemento(tmpNdAgrafo), espacioDisponible) != nullptr)
                {
                    NodoLista<W> *busTMP;
                    busTMP->duplicadoLista(&listaVehiculo, &busTMP);
                    //NodoLista<W>* busTMP = new NodoLista<W>;
                    //busTMP = listaVehiculo;
                    busTMP->append(&busTMP, verificacionVehiculo(tmpNdAgrafo->getElemento(tmpNdAgrafo), espacioDisponible));
                    rutaArco(tmpNdAgrafo->getElemento(tmpNdAgrafo), Destino, espacioDisponible, tmpVI, busTMP, rutasTotales);

                    busTMP = nullptr;
                    delete busTMP;
                }
                // Si no existe un bus disponible va al siguente arco
            }

            tmpNdAgrafo = nullptr;
            delete tmpNdAgrafo;

            tmpVI = nullptr;
            delete tmpVI;
        }

        void rutaArco(AGrafo * ArcoTMP, int DestinoFinal, int espacioDisponible, NodoLista<R> *& verticesIdos, NodoLista<W> *& listaVehiculo, NodoLista<TotalRuta<W>> *& rutasTotales)
        {
            AGrafo * tmpArco = ArcoTMP;

            NodoLista<W> *listaVehiculotmp;
            listaVehiculotmp->duplicadoLista(&listaVehiculo, &listaVehiculotmp);

            //NodoLista<W>* listaVehiculotmp = new NodoLista<W>;
            //listaVehiculotmp = listaVehiculo;

            if (tmpArco->verticeLlegada == DestinoFinal)
            {
                TotalRuta<W> *tmpTR = new TotalRuta<W>;
                tmpTR->rutaAlDestino = listaVehiculotmp;
                rutasTotales->push(&rutasTotales, tmpTR);

                tmpArco = nullptr;
                listaVehiculotmp = nullptr;
                delete listaVehiculotmp;
                delete tmpArco;
                return;
            }

            if (!verticeVisitado(ArcoTMP->verticeLlegada, verticesIdos))
            {
                rutaVertice(tmpArco->verticeLlegada, DestinoFinal, espacioDisponible, verticesIdos, listaVehiculotmp, rutasTotales);
            }

            tmpArco = nullptr;
            listaVehiculotmp = nullptr;
            delete listaVehiculotmp;
            delete tmpArco;
        }

        W *verificacionVehiculo(AGrafo *tmpArco, int espacioDisponible)
        {
            T *tmpDato = tmpArco->datos;
            for (; tmpDato != nullptr; tmpDato = tmpDato->nextElemento(tmpDato))
            {
                    if (tmpDato->getElemento(tmpDato)->getCantidadDisponible() >= espacioDisponible)
                    {
                        return tmpDato->getElemento(tmpDato);
                    }
            }
            tmpDato = nullptr;
            delete tmpDato;
            return nullptr;
        }

        bool verificacionVehiculoRuta(NodoLista<W> * nlZ, int espacioDisponible)
        {
            NodoLista<W> * nlZTMP = nlZ;
            for (; nlZTMP != nullptr; nlZTMP = nlZTMP->nextElemento(nlZTMP))
            {
                if (!(nlZTMP->getElemento(nlZTMP)->getCantidadDisponible() >= espacioDisponible))
                {
                    nlZTMP = nullptr;
                    delete nlZTMP;
                    return 0;
                }
            }
            nlZTMP = nullptr;
            delete nlZTMP;
            return 1;
        }

        /*
        int RutaOrigen(TotalRuta<W> * trW)
        {
            NodoLista<W> * nlW = trW ->rutaAlDestino;
            W * wTMP;
            for (; nlW != nullptr; nlW = nlW -> nextElemento(nlW))
            {
                wTMP = nlW->getElemento(nlW);
                return wTMP->getOrigen();
            }            
        }

        int RutaDestino(TotalRuta<W> *trW)
        {
            NodoLista<W> *nlW = trW->rutaAlDestino;
            W * wTMP;
            for (; nlW != nullptr; nlW = nlW->nextElemento(nlW))
            {
                if (nlW->nextElemento(nlW) == nullptr)
                {
                    wTMP = nlW->getElemento(nlW);
                    return wTMP->getDestino();
                }
            }
        }
        */
};