#pragma once
#include "../Libraries.h"

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
        this->categoria = categoria;
    };
    ~objetoEncomienda(){};

    void setCategoria(string categoria){this->categoria = categoria;}
    void setPeso(float peso){this->peso = peso;}
    void setEsFragilI(char esFragil){this->esFragil = esFragil;}

    bool getEsFragil(){return (this->esFragil == 'S') ? true : false;}
    string getCategoria(){return this->categoria;}
    int getPeso(){return this->peso;}
};
