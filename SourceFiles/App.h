#include "Libraries.h"

class App
{
public:


public:
    App(){
    };
    ~App(){};

    //string getDestinosViajes(int pos){return destinosViajes[pos];}

    
    void printDestinosViajes(){
        //for (int i = 0; i < destinosViajes.size(); i++){cout << "\n" << i+1 << " " << destinosViajes[i];}
    }

    void printDestinosEncomiendas(){
        //for (int i = 0; i < destinosEncomiendas.size(); i++){cout << "\n" << destinosEncomiendas[i];}
    }

    virtual int generarDuracion(){};
    virtual int generarCosto(){};

};

