#include "../Libraries.h"
#include "../Persona.h"
#include "objetoEncomienda.h"
class Encomienda
{
public:
    Persona * cliente;
    objetoEncomienda * objeto;
    string codigo;

    Encomienda(Persona * cliente, objetoEncomienda * objeto){
        this->cliente = cliente;
        this->objeto = objeto;
        this ->codigo = "";
    };
    ~Encomienda(){};
    
    string generarCodigo(){
        while (codigo.size() != 10){
            if(rand()%2 == 1){
            codigo = codigo + to_string(rand()%10);
            }
            else{
            codigo = codigo + to_string(rand()%10);
            };
        }
        return codigo;
    }

    string getCodigo(){return this->codigo;}
    int getPeso(){return objeto->getPeso();}

};
