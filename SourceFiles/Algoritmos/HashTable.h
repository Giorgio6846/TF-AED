#include "../Libraries.h"
#include "NodoLista.h"
#include "../Persona.h"

template <class T>
class HashTable
{
private:
    vector<list<T>> tableLists; //Cada indice del Hash será una lista
    int currentSize; //Size del hashTable
public:
    explicit HashTable(int size = 200) : currentSize{ 0 }
	{
		tableLists.resize(size);	//Resize al vector, para que tenga 200 elementos: 200 listas de Nodos Hash(key, value)
	}

    void makeEmpty()
	{
		for (auto& thisList : tableLists)
			thisList.clear();
	}

    bool insertPersona(T&& x)
	{
		auto& whichList = tableLists[crearHashString(x.getDocumento())]; //Del vector, obtenemos la lista de elementos según el hash(indice) obtenido
		whichList.push_back(x); //Agregamos el nuevo elemento(key, value) a la lista del hash(indice)
		return true;
	}
	
	bool insert(T &&x)
	{
		auto &whichList = tableLists[crearHashString(x.getDocumento())]; // Del vector, obtenemos la lista de elementos según el hash(indice) obtenido
		whichList.push_back(x);											 // Agregamos el nuevo elemento(key, value) a la lista del hash(indice)
		return true;
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

	void buscar(string key)
	{
		int pos = 0;
		pos = crearHashString(key); // Obtenemos el indice de la Tabla (pos) a partir de la Funcion HASH
		cout << "Key: " + to_string(pos) << " | ";
		for (auto &it : tableLists[pos])
		{								  // Recorremos la Lista de cada indice del vector
		}
		cout << endl;
	}

	void buscarPersona(string key) {
		int pos = 0;
		pos = crearHashString(key);	//Obtenemos el indice de la Tabla (pos) a partir de la Funcion HASH
		cout << "Key: " + to_string(pos) << " | ";
		for (auto& it : tableLists[pos]) {	// Recorremos la Lista de cada indice del vector	
			if (it.getDocumento() == key ) //Como es una lista, se recorre hasta que el documento coincida
				cout << "Nombre: " << it.getNombre() << endl;
                cout << "DNI: " << it.getDocumento() << endl;
		}
		cout << endl;
	}
};
