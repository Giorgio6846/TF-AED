#pragma once

#include "Libraries.h"

//Algoritmos
#include "NodoLista.h"
#include "NodoArbol.h"
#include "HashTable.h"
#include "ControladorDataSet.h"

class ControladorEncomiendas : public ControladorDataSet
{
private:
public:
    ControladorEncomiendas()
    {
    }
    ~ControladorEncomiendas() {}

    void printInfoEncomiendas() {
        clearScreen;
        if (hashTableEncomiendas.isEmpty())
        {
            cout << "No hay encomiendas registradas!" << endl;
        }
        else
        {
            hashTableEncomiendas.mostrarTodasEncomiendas();
            cont();
        }
    }

    int menuEncomienda() {
        int opcionSelecionada;
        do {
            clearScreen;
            cout << "Selecione la opcion: \n";
            cout << "1. Agendar una encomienda \n";
            cout << "2. Mostrar todas las encomiendas \n";
            cout << "3. Mostrar encomiendas en orden \n";
            cout << "4. Buscar encomienda por DNI \n";
            cout << "5. Regresar al menu principal \n";

            cin >> opcionSelecionada;

            if (!(opcionSelecionada >= 1 && opcionSelecionada <= 5)) {
                ClearKeyboard();
                cout << "La opcion seleccionada es incorrecta.";
                cont();
            }
            else
                return opcionSelecionada;
        } while (opcionSelecionada != 3);
        return opcionSelecionada;
    }



    void buscarEncomienda() {
        if (hashTableEncomiendas.isEmpty())
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
            hashTableEncomiendas.buscarEncomienda(codigo);
        }
    }

    Persona* almacenarInfoCliente() {
        clearScreen;
        string nombreP, apellidoP;
        int edadP;
        bool validar;

        Persona* cliente = new Persona();

#if RAD == 0
        cliente->typePersona();
#elif RAD == 1
        cliente->randomPersona();
#endif
        return cliente;
    }

    objetoEncomienda* almacenarInfoObjeto() {
        string categoria;
        int opcion;
        float peso;
        bool esFragil;

        do
        {
            clearScreen;

            cout << "De que categoria es su objeto a encomendar?: " << endl;
            cout << "1- Tecnologia" << endl;
            cout << "2- Salud" << endl;
            cout << "3- Vestimenta" << endl;

            cin >> opcion;

            if (!(opcion >= 1 && opcion <= 3)) {
                ClearKeyboard();
                cout << "La opcion seleccionada es incorrecta.";
                cont();

            }
        } while (!(opcion >= 1 && opcion <= 3));

        switch (opcion)
        {
        case 1: categoria = "Tecnologia"; break;
        case 2: categoria = "Salud"; break;
        case 3: categoria = "Vestimenta"; break;
        }

        do
        {
            clearScreen;

            cout << "Cual es el peso aproximado(Kg) de su objeto?" << endl;
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

            cout << "Es su objeto considero fragil?: 1 = Si / 2 = No " << endl;
            cin >> esFragil;

            if (!(esFragil >= 1 && esFragil <= 2)) {
                ClearKeyboard();
                cout << "El valor ingresado es invalido.\n";
                cont();

            }
        } while (!(esFragil >= 1 && esFragil <= 2));
        esFragil = (esFragil == 1);
        clearScreen;
        objetoEncomienda* objeto = new objetoEncomienda(categoria, peso, esFragil);
        return objeto;
    }

    TotalRuta<Camion>* almacenarRuta(int peso) {
        int Origen = Rutas::selecionarOrigen();

        if (Origen != -1)
        {
            int Destino = selecionarDestino(Origen);
            if (Destino != -1)
            {
                TotalRuta<Camion>* TRtmp = grafoRutasE->rutaFinal(Origen, Destino, peso);
                return TRtmp;
            }
        }
        return nullptr;
    }

    void mostrarOrdenEncomiendas() {
        clearScreen;
        arbol->imprimirEnOrden(arbol);
    }

    void agendarEncomiendaFinal()
    {
        //Se crea e iguala el objeto a los devueltos por funciones
        Persona* cliente = almacenarInfoCliente();
        objetoEncomienda* encomiendaItem = almacenarInfoObjeto();
        TotalRuta<Camion>* ruta = almacenarRuta(encomiendaItem->getPeso());
        //Se crea la encomienda completa a base de 3 objetos
        Encomienda* encomiendaFinal = new Encomienda(cliente, encomiendaItem, ruta);
        //Se asigna un tamaño al hash
        //Si se insertó de manera satisfactoria, se printea un mensaje
        if (hashTableEncomiendas.insert(encomiendaFinal->cliente->getDocumento(), encomiendaFinal))
        {
            clearScreen;
            cout << "Su encomienda ha sido registrada de manera satisfactoria!" << endl;
        }
        //Se agrega el valor de tiempo a un arbol de búsqueda
        cont();
    }
};