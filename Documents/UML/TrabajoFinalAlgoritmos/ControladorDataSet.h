#pragma once
#include "Libraries.h"
#include "HashTable.h"
#include "Encomienda.h"
#include "objetoEncomienda.h"
#include "Persona.h"
#include "NodoArbol.h"
#include "VehiculoTransporte.h"
#include "Grafo.h"
#include "Viaje.h"
#include "Rutas.h"

class ControladorDataSet : public Rutas
{
protected:
#if (VER == 1 || VER == 2)
    // Grafo para realizar rutaViaje
    Grafo<NodoLista<Bus>, int, Bus>* grafoRutasV = new Grafo<NodoLista<Bus>, int, Bus>;
    //HashTable Viaje
    HashTable<Viaje> hashTableViajes;
#endif

#if (VER == 1 || VER == 3)
    // Grafo para realizar rutaEncomienda
    Grafo<NodoLista<Camion>, int, Camion>* grafoRutasE = new Grafo<NodoLista<Camion>, int, Camion>;
    // HashTable Encomienda
    HashTable<Encomienda> hashTableEncomiendas;
#endif

    NodoArbol<int>* arbol;
    ifstream archivo;
    char delimitador;
public:
    ControladorDataSet()
    {
#if (VER == 1 || VER == 2)
        generacionGrafoV();
        hashTableViajes.setSize(7000);
#endif

#if (VER == 1 || VER == 3)
        generacionGrafoE();
        hashTableEncomiendas.setSize(7000);
#endif

        this->delimitador = ',';
        arbol = NULL;

#if (useDataSet == 1)
        lecturaIndexacion();
#endif

    };
    ~ControladorDataSet() {};

    void lecturaIndexacion()
    {
        archivo.open("DataSet.csv", ios::in); //Apertura
        if (!archivo.is_open())
        {
            cout << "Error: No se pudo abrir el archivo!" << endl;
            exit(1);
        }
        //Variables del dataSet
        string nombre, apellido1, apellido2, edad, documento, linea;
        string funcion;
        //Saltea la primera linea
        getline(archivo, linea);
        while (getline(archivo, linea))
        {
            stringstream stream(linea); // Convertir la cadena a un stream
            // Extraer todos los valores de esa fila [considerando 3 columans]
            getline(stream, nombre, delimitador);
            getline(stream, apellido1, delimitador);
            getline(stream, apellido2, delimitador);
            getline(stream, edad, delimitador);
            getline(stream, documento, delimitador);
            getline(stream, funcion, delimitador);
            //Indexamos la informacion, según la función, en encomiendas o viajes

#if (VER == 1 || VER == 2)
            if (funcion == "V")
            {
                FuncionViaje(creacionPersona(nombre, apellido1, apellido2, edad, documento));
            }
#endif
#if (VER == 1 || VER == 3)
            if (funcion == "E")
            {
                FuncionEncomienda(creacionPersona(nombre, apellido1, apellido2, edad, documento));
            }
#endif
        }
        archivo.close();
    }

    Persona* creacionPersona(string nombre, string apellido1, string apellido2, string edad, string documento)
    {
        //Objeto cliente del dataset
        Persona* cliente = new Persona(nombre, apellido1, stoi(edad), 'D');
        cliente->setDocumento(documento);
        return cliente;
    }

#if (VER == 1 || VER == 2)
    void FuncionViaje(Persona* pTMP)
    {
        int Origen = randOrigen();
        int Destino = randDestino(Origen);
        TotalRuta<Bus>* busTMP = grafoRutasV->rutaFinal(Origen, Destino, 1);
        Viaje* viajeTMP = new Viaje(pTMP, busTMP);
        asientoRandom(busTMP->rutaAlDestino, viajeTMP->pasajero);
        hashTableViajes.insert(pTMP->getDocumento(), viajeTMP);
    }
#endif

#if (VER == 1 || VER == 3)
    void FuncionEncomienda(Persona* pTMP)
    {
        int Origen, Destino;
        Origen = randOrigen();
        Destino = randDestino(Origen);

        objetoEncomienda* objeto = new objetoEncomienda();
        TotalRuta<Camion>* camionTMP = grafoRutasE->rutaFinal(Origen, Destino, objeto->getPeso());
        Encomienda* encomienda = new Encomienda(pTMP, objeto, camionTMP);
        arbol->insertarValor(arbol, pTMP->getDocumento(), camionTMP->pesoEntero * 10);
        hashTableEncomiendas.insert(pTMP->getDocumento(), encomienda);
    }
#endif

    void asientoRandom(NodoLista<Bus>* trbusTMP, Persona* pTMP)
    {
        NodoLista<Bus>* nlTMP = trbusTMP;
        Bus* bTMP;
        for (; nlTMP != NULL; nlTMP = nlTMP->nextElemento(nlTMP))
        {
            bTMP = nlTMP->getElemento(nlTMP);
            bTMP->AsientoRandom(pTMP);
        }
    }

    /*
    #if (VER == 1 || VER == 2)
        void generacionGrafoViaje()
        {
            for (int i = 0; i < getSizeLugares(); i++)
            {
                grafoRutasV->agregarVertice(i);
            }

            for (int i = 0; i < getSizeLugares(); i++)
            {
                for (int j = 0; j < getSizeLugares(); j++)
                {
                    if (accesoRutaDisponible(i, j) != 0)
                    {
                        NodoLista<Bus> *listaBus = NULL;
                        for (int k = 0; k <= 3; k++)
                        {
                            Bus *tmp = new Bus(i, j, accesoTiempoRuta(i, j));
                            listaBus->push(&listaBus, tmp);
                        }
                        grafoRutasV->agregarArcoVertice(i, j, accesoTiempoRuta(i, j), listaBus);
                    }
                }
            }
        }
    #endif
    */

    void generacionGrafoV()
    {
        for (int i = 0; i < getSizeLugares(); i++)
        {
            grafoRutasV->agregarVertice(i);
        }

        for (int i = 0; i < getSizeLugares(); i++)
        {
            for (int j = 0; j < getSizeLugares(); j++)
            {
                if (accesoRutaDisponible(i, j) != 0)
                {
                    NodoLista<Bus>* listaVehiculo = NULL;
                    for (int k = 0; k <= 3; k++)
                    {
                        Bus* tmp = new Bus(i, j, accesoTiempoRuta(i, j));
                        listaVehiculo->push(&listaVehiculo, tmp);
                    }
                    grafoRutasV->agregarArcoVertice(i, j, accesoTiempoRuta(i, j), listaVehiculo);
                }
            }
        }
    }

    void generacionGrafoE()
    {
        for (int i = 0; i < getSizeLugares(); i++)
        {
            grafoRutasE->agregarVertice(i);
        }

        for (int i = 0; i < getSizeLugares(); i++)
        {
            for (int j = 0; j < getSizeLugares(); j++)
            {
                if (accesoRutaDisponible(i, j) != 0)
                {
                    NodoLista<Camion>* listaVehiculo = NULL;
                    for (int k = 0; k <= 3; k++)
                    {
                        Camion* tmp = new Camion(i, j, accesoTiempoRuta(i, j));
                        listaVehiculo->push(&listaVehiculo, tmp);
                    }
                    grafoRutasE->agregarArcoVertice(i, j, accesoTiempoRuta(i, j), listaVehiculo);
                }
            }
        }
    }

    int randOrigen()
    {
        return rand() % getSizeLugares();
    }

    int randDestino(int Origen)
    {
        int dest;
        do
        {
            dest = rand() % getSizeLugares();
        } while (dest == Origen);
        return dest;
    }
};
