#include "Libraries.h"

struct Asiento
{
    string ubicacion;
    char clase;
};

class Bus
{
private:
    vector<vector<Asiento>> distribucionAsientos;

    int columnaAsiento = 6;
    int filaAsiento = 10;

public:
    Bus(){}
    ~Bus(){}

    void mostrarAsientos();
    void generarAsientos();
};

void Bus::mostrarAsientos()
{
    for(int i = 0; i < distribucionAsientos.size(); i++)
    {
        for(int j = 0; j < distribucionAsientos[i].size();j++)
        {
            cout << distribucionAsientos[i][j].ubicacion << " " << distribucionAsientos[i][j].clase << " ";
        }
        cout << "\n";
    }
}

void Bus::generarAsientos()
{
    string ubicacion;
    char clase;

    for (int i = 0; i < filaAsiento; i++)
    {
        vector<Asiento> Fil;
        for (int j = 0; j < columnaAsiento; j++)
        {
            ubicacion = char(65 + j) + to_string(i+1);
            clase = char((i <= 2) * 0 + (i >= 3 && i <= 6) * 1 + (i >= 7) * 2 + 65);

            Fil.push_back(Asiento());
            Fil[j].clase = clase;
            Fil[j].ubicacion = ubicacion;
        }
        distribucionAsientos.push_back(Fil);
    }
}