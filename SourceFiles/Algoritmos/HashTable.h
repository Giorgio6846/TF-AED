#pragma once

#include "../Libraries.h"
#include "../Persona.h"
#include "../Encomienda/Encomienda.h"

template <class T>
class HashTable
{
private:
    vector<list<T*>>  tableLists; //Cada indice del Hash será una lista
    int currentSize; //Size del hashTable
public:
    explicit HashTable(int size) : currentSize{ 0 }
	{
		tableLists.resize(size);	//Resize al vector, para que tenga 200 elementos: 200 listas de Nodos Hash(key, value)
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
		cout << "Informacion de su encomienda: "<< endl;
		for (auto * it : tableLists[pos]) {	// Recorremos la Lista de cada indice del vector	
			if (it->cliente->getDocumento() == key )
				it->cliente->informacionPersona();
				cont();
		}
		cout << endl;
	}

	

	void mostrarTodasEncomiendas() {
		int pos = 0;
		int cont = 0;
		for (auto & thisList  : tableLists) {		// Recorremos el vector<>
			for (auto * it : tableLists[pos]) {	// Recorremos la Lista de cada indice del vector	
				if (it->cliente->getDocumento() != "" ){
					cout << "Encomienda : " << cont << endl;
					it->cliente->informacionPersona();
					cont++;
				}
			}
			pos++;
		}
	}

	//Función hash; Se utiliza string, ya que el DNI será pasado como llave
    size_t crearHashString(const string key) const {
		char c;	
		size_t hashVal = 0;
		//For each 
		for (char ch : key) hashVal += ch;					
		hashVal = hashVal % tableLists.size();
		return(hashVal);	
	}
};