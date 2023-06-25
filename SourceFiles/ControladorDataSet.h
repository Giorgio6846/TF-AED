#pragma once
#include "Libraries.h"
#include "Algoritmos/HashTable.h"
#include "Encomienda/Encomienda.h"
#include "Encomienda/objetoEncomienda.h"
#include "Persona.h"
#include "Algoritmos/NodoArbol.h"
#include "VehiculoTransporte.h"
#include "Algoritmos/Grafo.h"
#include "Viaje/Viaje.h"
#include "Rutas.h"

class ControladorDataSet : public Rutas
{
protected:
    #if (VER == 1 || VER == 2)
        // Grafo para realizar rutaViaje
        Grafo<NodoLista<Bus>, int, Bus> *grafoRutasV = new Grafo<NodoLista<Bus>, int, Bus>;
        //HashTable Viaje
        HashTable<Viaje> hashTableViajes;
    #endif

    #if (VER == 1 || VER == 3)
        // Grafo para realizar rutaEncomienda
        Grafo<NodoLista<Camion>, int, Camion> *grafoRutasE = new Grafo<NodoLista<Camion>, int, Camion>;
        // HashTable Encomienda
        HashTable<Encomienda> hashTableEncomiendas;
    #endif

    NodoArbol<int> * arbol;
    ifstream archivo;
	char delimitador;
public:
    ControladorDataSet()
    {
    #if (VER == 1 || VER == 2)
        generacionGrafoViaje();
        hashTableViajes.setSize(10000);
    #endif

    #if (VER == 1 || VER == 3)
        generacionGrafoEncomienda();
        hashTableEncomiendas.setSize(10000);
    #endif

    this->delimitador = ',';
    arbol = NULL;

    lecturaIndexacion();
    };
    ~ControladorDataSet(){};

    void lecturaIndexacion()
    {
        archivo.open("DataSet.csv", ios::in); //Apertura
		if (!archivo.is_open())
		{
			cout << "Error: No se pudo abrir el archivo!" << endl;
			exit(1);
		}
        //Variables del dataSet
        string nombre, apellido1, apellido2, edad, documento,linea;
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
                FuncionViaje(nombre, apellido1, apellido2, edad, documento);
            }
            #endif
            #if (VER == 1 || VER == 3)
            if (funcion == "E")
            {
                FuncionEncomienda(nombre, apellido1, apellido2, edad, documento);
            }
            #endif
        }
		archivo.close();
    }

    Persona *creacionPersona(string nombre, string apellido1, string apellido2, string edad, string documento)
    {
        //Objeto cliente del dataset
        Persona *cliente = new Persona(nombre, apellido1, stoi(edad), 'D');
        cliente->setDocumento(documento);
        return cliente;
    }

    #if (VER == 1 || VER == 2)
    void FuncionViaje(string nombre, string apellido1, string apellido2, string edad, string documento)
    {
        int Origen, Destino;
        Origen = randOrigen();
        Destino = randDestino(Origen);
        TotalRuta<Bus> *busTMP = grafoRutasV->rutaFinal(Origen, Destino, 5);
        
        PersonaInf * piTMP = new PersonaInf();
        piTMP -> personaViaje = creacionPersona(nombre, apellido1, apellido2, edad, documento);
        asientoRandom(busTMP->rutaAlDestino,piTMP->personaViaje);
        Viaje *viajeTMP = new Viaje(Origen, Destino, piTMP, busTMP);
        hashTableViajes.insert(piTMP->personaViaje->getKey(), viajeTMP);
    }
    #endif

    #if (VER == 1 || VER == 3)
    void FuncionEncomienda(string nombre, string apellido1, string apellido2, string edad, string documento)
    {
        int Origen, Destino;
        Origen = randOrigen();
        Destino = randDestino(Origen);

        objetoEncomienda *objeto = new objetoEncomienda();
        TotalRuta<Camion> *camionTMP = grafoRutasE->rutaFinal(Origen, Destino, objeto->getPeso());
        Encomienda *encomienda = new Encomienda(creacionPersona(nombre, apellido1, apellido2, edad, documento), objeto, camionTMP);

        hashTableEncomiendas.insert(encomienda->cliente->getKey(), encomienda);
    }
    #endif

    void asientoRandom(NodoLista<Bus> * trbusTMP, Persona * pTMP)
    {
        NodoLista<Bus> * nlTMP = trbusTMP;
        Bus * bTMP;
        for (; nlTMP != NULL; nlTMP = nlTMP->nextElemento(nlTMP))
        {
            bTMP = nlTMP->getElemento(nlTMP);
            bTMP -> AsientoRandom(pTMP);
        }
    }

    void generacionGrafoEncomienda()
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
                    NodoLista<Camion> *listaCamion = NULL;
                    for (int k = 0; k <= 3; k++)
                    {
                        Camion *tmp = new Camion(i, j, accesoTiempoRuta(i, j));
                        listaCamion->push(&listaCamion, tmp);
                    }
                    grafoRutasE->agregarArcoVertice(i, j, accesoTiempoRuta(i, j), listaCamion);
                }
            }
        }
    }

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
                    for (int k = 0; k <= 4; k++)
                    {
                        Bus *tmp = new Bus(i, j, accesoTiempoRuta(i, j));
                        listaBus->push(&listaBus, tmp);
                    }
                    grafoRutasV->agregarArcoVertice(i, j, accesoTiempoRuta(i, j), listaBus);
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
