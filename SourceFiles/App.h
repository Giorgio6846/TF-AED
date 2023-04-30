#include "Libraries.h"

class App
{
public:
    vector <string>destinosViajes;
    vector <string>destinosEncomiendas;

public:
    App(){
        destinosViajes = {"Gaa", "GAASDPOJAF"};
        destinosEncomiendas = {"LA MAMA", "DE FABIO XD"};
    };
    ~App(){};

    string getDestinosViajes(int pos){return destinosViajes[pos];}
    string getDestinosEncomiendas(int pos){return destinosEncomiendas[pos];}
    int getEncomiendasN(){return destinosEncomiendas.size();}

    void printDestinosViajes(){
        for (int i = 0; i < destinosViajes.size(); i++){cout << "\n" << destinosViajes[i];}
    }

    void printDestinosEncomiendas(){
        for (int i = 0; i < destinosEncomiendas.size(); i++){cout << "\n" << destinosEncomiendas[i];}
    }

    virtual int generarDuracion(){};
    virtual int generarCosto(){};

};

