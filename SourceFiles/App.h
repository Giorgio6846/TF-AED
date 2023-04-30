#include "Libraries.h"

class App
{
public:
    vector <string>destinosViajes;
    vector <string>destinosEncomiendas;

public:
    App(){
        destinosViajes = {"Gaa", "GAASDPOJAF"};
    };
    ~App();

    string getDestinosViajes(int pos){return destinosViajes[pos];}
    string getDestinosEncomiendas(int pos){return destinosEncomiendas[pos];}

    void printDestinosViajes(){
        for (int i = 0; i < destinosViajes.size(); i++)
        {
            cout << "\n" << destinosViajes[i];
        }
        
    }


};

