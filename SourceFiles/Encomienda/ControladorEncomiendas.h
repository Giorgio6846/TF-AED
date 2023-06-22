#pragma once

#include "../Libraries.h"
#include "../Rutas.h"
#include "../Persona.h"

//Algoritmos
#include "../Algoritmos/NodoLista.h"
#include "../Algoritmos/NodoArbol.h"
#include "../Algoritmos/HashTable.h"
#include "../Algoritmos/Grafo.h"
#include "../VehiculoTransporte.h"
#include "objetoEncomienda.h"
#include "Encomienda.h"


class ControladorEncomiendas: public Rutas
{
    private:
        HashTable<Encomienda> hashTable;
        Grafo<NodoLista<Camion>, int, Camion> *grafoRutas = new Grafo<NodoLista<Camion>, int, Camion>;
        NodoArbol<int> * arbol;

    public:
        ControladorEncomiendas(){
            arbol = NULL;
        };
        ~ControladorEncomiendas(){};

    void printInfoEncomiendas(){
        clearScreen;
        if (hashTable.isEmpty())
        {
            cout << "No hay encomiendas registradas!" << endl;
        }
        else
        {
            hashTable.mostrarTodasEncomiendas();
            cont();
        }
    }

    int menuEncomienda(){
        int opcionSelecionada;
        do{
            clearScreen;
            cout << "Selecione la opcion: \n";
            cout << "1. Agendar una encomienda \n";
            cout << "2. Mostrar todas las encomiendas \n";
            cout << "3. Mostrar encomiendas en orden \n";
            cout << "4. Buscar encomienda por DNI \n";
            cout << "5. Regresar al menu principal \n";
            
            cin >> opcionSelecionada;

            if (!(opcionSelecionada >= 1 && opcionSelecionada <= 5)){
                ClearKeyboard();
                cout << "La opcion seleccionada es incorrecta.";
                cont();
            }
            else
                return opcionSelecionada;
        } while (opcionSelecionada != 3);
        return opcionSelecionada;
    }

    void generacionGrafo()
    {
        for (int i = 0; i < getSizeLugares(); i++)
        {
            grafoRutas->agregarVertice(i);
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
                    grafoRutas->agregarArcoVertice(i, j, accesoTiempoRuta(i, j), listaCamion);
                }
            }
        }
    }

    void buscarEncomienda(){
        if (hashTable.isEmpty())
        {
            cout << "No hay encomiendas registradas!" << endl;
            cont();
        }
        else
        {
            clearScreen;
            string codigo;
            cout << "Ingrese su DNI" << endl;
            cin >> codigo;
            clearScreen;
            hashTable.buscarEncomienda(codigo); 
        }
    }

    Persona * almacenarInfoCliente(){
        clearScreen;
        string nombreP, apellidoP;
        int edadP;
        bool validar;

        Persona * cliente = new Persona();

        #if RAD == 1
                    cliente->typePersona();
        #elif RAD == 1
                    cliente->randomPersona();
        #endif

        return cliente;
    }

    objetoEncomienda * almacenarInfoObjeto(){
        string categoria;
        int opcion;
        float peso;
        int esFragil;

        do
        {
            clearScreen;

            cout << "De que categoria es su objeto a encomendar?: " << endl;
            cout << "1- Tecnologia"<< endl;
            cout << "2- Salud"<< endl;
            cout << "3- Vestimenta"<< endl;

            cin >> opcion;

            if (!(opcion >= 1 && opcion <= 3)) {
            ClearKeyboard();
            cout << "La opcion seleccionada es incorrecta.";
            cont();
            
        }
        } while (!(opcion >= 1 && opcion <= 3));
        
        switch (opcion)
        {
        case 1: categoria = "Tecnologia";break;
        case 2: categoria = "Salud";break;
        case 3: categoria = "Vestimenta";break;
        }

        do
        {
            clearScreen;

            cout << "Cual es el peso aproximado(Kg) de su objeto?"<< endl;
            cin >> peso;

            if (!(peso >= 0.01 && peso <= 30)) {
            ClearKeyboard();
            cout << "El valor ingresado es invalido.\n";
            cont();

            }   
        } while (!(peso >= 0.01 && peso <= 30));

        do
        {
            clearScreen;

            cout << "Es su objeto considero fragil?: 1 = Si / 2 = No "<< endl;
            cin >> esFragil;

            if (!(esFragil >= 1 && esFragil <= 2)) {
            ClearKeyboard();
            cout << "El valor ingresado es invalido.\n";
            cont();

            }   
        } while (!(esFragil >= 1 && esFragil <= 2));
        clearScreen;
        objetoEncomienda * objeto = new objetoEncomienda(categoria, peso, esFragil);
        return objeto;
    }

    TotalRuta<Camion> * almacenarRuta(){
        int Origen = Rutas :: selecionarOrigen();

        if(Origen != -1)
        {
            int Destino = selecionarDestino(Origen);
            if (Destino != -1)
            {
                int peso ;
                TotalRuta<Camion> * TRtmp = grafoRutas->rutaFinal(Origen, Destino, peso);
                return TRtmp;
            }
        }
        return nullptr;
    }

    void mostrarOrdenEncomiendas(){
        clearScreen;
        arbol->imprimirEnOrden(arbol);
    }

    void agendarEncomiendaFinal(){
        //Se crea e iguala el objeto a los devueltos por funciones
        Persona *cliente = almacenarInfoCliente();
        objetoEncomienda *encomiendaItem = almacenarInfoObjeto();
        TotalRuta<Camion> * ruta = almacenarRuta();
        //Se crea la encomienda completa a base de 3 objetos
        Encomienda *encomiendaFinal = new Encomienda(cliente, encomiendaItem, ruta);
        //Se asigna un tamaño al hash
        hashTable.setSize(200);
        //Si se insertó de manera satisfactoria, se printea un mensaje
        if (hashTable.insert(encomiendaFinal->cliente->getDocumento(), encomiendaFinal))
        {   
            clearScreen;
            cout << "Su encomienda ha sido registrada de manera satisfactoria!" << endl;
        }
        //Se agrega el valor de tiempo a un arbol de búsqueda
        arbol->insertarValor(arbol, cliente->getKey() , ruta->pesoEntero);
        cont();
    }
};