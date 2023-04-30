#include "Libraries.h"
#include "Asiento.h"

//Los buses ya tienen un tamaño definido

class Bus
{
private:
    vector <Asiento*>*MapaAsientos;
    
    int columnaAsientos;
    int filaAsientos;

public:
    Bus();
    ~Bus();

    void mostrarAsientos();
    void generarAsientos();
};

Bus::Bus()
{
    MapaAsientos = new vector <Asiento*> ();

    this -> columnaAsientos = 6;
    this -> filaAsientos = 18;
}

Bus::~Bus()
{
}

void Bus::mostrarAsientos()
{
    for (int i = 1; i <= filaAsientos; i++)
    {
        for (int j = 1; j <= columnaAsientos; j++)
        {
            cout << "\x1b[32m" << char(124);
            if (columnaAsientos / 2 == j) cout << " ";
            
        }
        cout << "\n";
    }
    
    //cout << MapaAsientos->size();
}

void Bus::generarAsientos()
{
    string ubicacion;
    char clase;

    columnaAsientos = ((columnaAsientos % 2) == 1) * 1 + columnaAsientos;

    if (columnaAsientos >= 8) columnaAsientos = 6;
    else columnaAsientos = columnaAsientos;

    if (filaAsientos >= 25) filaAsientos = 18;
    else filaAsientos = filaAsientos;

    for (int i = 1; i <= filaAsientos; i++)
    {
        for (int j = 1; j <= columnaAsientos; j++)
        {
            ubicacion = to_string(char(64+j)) + to_string(i);
            clase = char((i <= 5) * 1 + (i >= 6 && i <= 8) * 2 + (i > 9) * 3 + 64);

            MapaAsientos->push_back(new Asiento(ubicacion, clase));
        }
    }
    
}