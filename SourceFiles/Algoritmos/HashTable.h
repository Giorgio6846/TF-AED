#include "../Libraries.h"
#include "../Persona.h"
#include "../Encomienda/Encomienda.h"
template <class T>
class HashTable
{
private:
    vector<list<Encomienda*>>  tableLists; //Cada indice del Hash será una lista
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

	bool insert(string key, Encomienda* n)
	{
		tableLists[crearHashString(key)].push_back(n); // Del vector, obtenemos la lista de elementos según el hash(indice) obtenido
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