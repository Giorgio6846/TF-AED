#include "../Libraries.h"
#include "../Persona.h"
#include "objetoEncomienda.h"
class Encomienda
{
public:
    Persona * cliente;
    objetoEncomienda * objeto;
    
    Encomienda(Persona * cliente, objetoEncomienda * objeto){
        this->cliente = cliente;
        this->objeto = objeto;
    };
    ~Encomienda(){};
    
    int getPeso(){return objeto->getPeso();}

};
