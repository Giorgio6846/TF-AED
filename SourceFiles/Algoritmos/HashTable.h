#include "Libraries.h"
#include "NodoLista.h"
#include "../Encomienda.h"
class HashTable
{
private:
    vector<list<Encomienda>> tableLists; //Cada indice del Hash será una lista
    int currentSize; //Size del hashTable
public:
    HashTable(int currentSize){
        tableLists.resize(currentSize); //Crea "currentSize" listas
    };
    ~HashTable(){};
};