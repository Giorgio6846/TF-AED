#pragma once
#include "../Libraries.h"

class objetoEncomienda
{
private:
    string categoria;
    float peso;
    int esFragil;
    string fragil;
public:
    //Constructor para input manual
    objetoEncomienda(string categoria, float peso, int esFragil){
        this->peso=peso;
        this->esFragil = esFragil;
        this->categoria = categoria;
    };
    //Constructor para DataSet
    objetoEncomienda(){
        this->peso=rand()%100;
        this->esFragil = rand()%2;
        this->categoria = "Tecnologia";
    };
    ~objetoEncomienda(){};

    void setCategoria(string categoria){this->categoria = categoria;}
    void setPeso(float peso){this->peso = peso;}
    void setEsFragilI(int esFragil){this->esFragil = esFragil;}

    bool getEsFragil(){return (this->esFragil == '1') ? true : false;}
    string getCategoria(){return this->categoria;}
    int getPeso(){return this->peso;}

    void infoEncomienda(){
        cout << "Informacion del objeto: " << endl;
        cout << "Peso: " << peso << "Kg" << endl;
        if (esFragil==true)
        {
           fragil="Si";
        }else
        {
            fragil="No";
        }
        cout << "Es fragil?: " << fragil << endl;
    }
};
