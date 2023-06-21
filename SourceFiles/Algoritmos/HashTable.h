#pragma once

#include "../Libraries.h"
#include "../Persona.h"
//#include "../Encomienda/Encomienda.h"

template <class T>
class HashTable
{
private:
    vector<list<T*>>  tableLists; //Cada indice del Hash será una lista
    int currentSize; //Size del hashTable
public:
    explicit HashTable() : currentSize{ 0 }
	{	
		//Resize al vector, para que tenga 200 elementos: 200 listas de Nodos Hash(key, value)
	}

	void setSize(int size)
	{
		tableLists.resize(size);
	}

	void makeEmpty()
	{
		for (auto& thisList : tableLists)
			thisList.clear();
	}

	bool insert(string key, T* n)
	{
		tableLists[crearHashString(key)].push_back(n); // Del vector, obtenemos la lista de elementos según el hash(indice) obtenido
        return true;
	}

	bool isEmpty() const {
		for (int i = 0; i < tableLists.size(); i++) {
			if (!tableLists[i].empty()) {
				return false;
			}
		}
	return true;
	}


	void buscarEncomienda(string key) {
		
		int pos = 0;
		pos = crearHashString(key);	//Obtenemos el indice de la Tabla (pos) a partir de la Funcion HASH
		for (auto * it : tableLists[pos]) {	// Recorremos la Lista de cada indice del vector	
			if (it->cliente->getDocumento() == key )
				it->cliente->informacionPersona();
				it->objeto->infoEncomienda();
				cout << "Tiempo estimado: " << it->ruta->pesoEntero << endl;
				cont();
		}
		cout << endl;
		
	}


	void mostrarTodasEncomiendas() {
		int pos = 0;
		int cont = 1;
		for (auto & thisList  : tableLists) {		// Recorremos el vector<>
			for (auto * it : tableLists[pos]) {	// Recorremos la Lista de cada indice del vector	
				if (it->cliente->getDocumento() != "" ){
					cout << "Encomienda : " << cont << endl;
					it->cliente->informacionPersona();
					it->objeto->infoEncomienda();
					cout << "Tiempo estimado: " << it->ruta->pesoEntero << endl;
					cont++;
				}
			}
			pos++;
		}
	}

	//Función hash; Se utiliza string, ya que el DNI será pasado como llave
    size_t crearHashString(const string key) const {
		size_t hashVal = 0;
		//For each 
		//for (char ch : key) hashVal += size_t(ch);

		auto hashFunc = [](char c) {
        return static_cast<size_t>(c) * 36;};

    	for (size_t i = 0; i < key.length(); i++) {
        hashVal = hashVal + hashFunc(key[i]);
    	}
		hashVal = hashVal % tableLists.size();

		/*for (size_t i = 0; i < key.length(); i++) {
        char c = key[i];
        hashVal = hashVal * 36 + static_cast<size_t>(c);
		}				
		}*/			
		
		return(hashVal);	
	}

	int getSize() const {
		return currentSize;
	}
};