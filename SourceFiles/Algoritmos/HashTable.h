#include "Libraries.h"
#include "NodoLista.h"
#include "../Persona.h"
class HashTable
{
private:
    vector<list<Persona>> tableLists; //Cada indice del Hash será una lista
    int currentSize; //Size del hashTable
public:
    explicit HashTable(int size = 200) : currentSize{ 0 }
	{
		tableLists.resize(200);	//Resize al vector, para que tenga 200 elementos: 200 listas de Nodos Hash(key, value)
	}

    void makeEmpty()
	{
		for (auto& thisList : tableLists)
			thisList.clear();
	}

    bool insert(Persona&& x)
	{
		auto& whichList = tableLists[crearHashString(x.getDocumento())]; //Del vector, obtenemos la lista de elementos según el hash(indice) obtenido
		whichList.push_back(x); //Agregamos el nuevo elemento(key, value) a la lista del hash(indice)
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
};
