#include "Libraries.h"
#include "Algoritmos\HashTable.h"
#include "Encomienda\Encomienda.h"

class ControladorDataSet
{
private:
    //HashTable donde se almacerán aquellas personas con una "E"
    HashTable<Encomienda> hashTable;
    
public:
    ControladorDataSet(){};
    ~ControladorDataSet(){};
};

