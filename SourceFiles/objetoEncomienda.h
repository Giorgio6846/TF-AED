#include "Libraries.h"
#pragma once
class objetoEncomienda
{
private:
    string categoria;
    float peso;
    char esFragil;
public:
    objetoEncomienda(string categoria, float peso, char esFragil){
        this->peso=peso;
        this->esFragil = esFragil;
    };
    ~objetoEncomienda(){};

    void setCategoria(string categoria){this->categoria = categoria;}
    void setPeso(float peso){this->peso = peso;}
    void setEsFragilI(char esFragil){this->esFragil = esFragil;}
};
