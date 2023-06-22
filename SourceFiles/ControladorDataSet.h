#pragma once
#include "Libraries.h"
#include "Algoritmos/HashTable.h"
#include "Encomienda/Encomienda.h"
#include "Persona.h"
//#include "objetoEncomienda.h"
//#include "../VehiculoTransporte.h"

class ControladorDataSet
{
protected:
    //HashTable donde se almacerán aquellas personas con una "E"
    HashTable<Encomienda> hashTableEncomiendas;
    //hashTableEncomiendas donde se almacerán aquellas personas con una "V"
    //HashTable<GAAA> la mama defabio!;

    ifstream archivo;
	char delimitador;


public:
    ControladorDataSet(){
        this->delimitador = ',';
        hashTableEncomiendas.setSize(10000);
    };
    ~ControladorDataSet(){};

    void lecturaIndexacion(){
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
            if (funcion == "E")
            {   
                Persona * cliente = new Persona(nombre, apellido1 , stoi(edad), 'D');
                cliente->setDocumento(documento);
                Encomienda * encomienda = new Encomienda(cliente, NULL, NULL);
                hashTableEncomiendas.insert(encomienda->cliente->getKey(), encomienda);
            }
		}
		archivo.close();
    }
};
