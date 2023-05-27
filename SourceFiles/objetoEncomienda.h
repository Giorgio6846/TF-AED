#include "Libraries.h"
#pragma once
class objetoEncomienda
{
private:
    string categoria;
    int peso;
    bool esFragil;
public:
    objetoEncomienda(string categoria, int peso, bool esFragil){
        this->peso=peso;
        this->esFragil = esFragil;
    };
    ~objetoEncomienda(){};

    void setCategoria(string categoria){this->categoria = categoria;}
    void setPeso(int peso){this->peso = peso;}
    void setEsFragilI(bool esFragil){this->esFragil = esFragil;}
};
