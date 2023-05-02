#include "Libraries.h"

#include "Origen.h"
#include "Destino.h"

/*
Lima, Chimbote, Trujillo, Pacasmayo, Cajamarca, Chepen, Chiclayo, Piura, Jaen, Cajabamba, Moyobamba, Tarapoto
*/

class Viajes : public Origen, public Destino
{
private:
    bool rutas[12][12] = {
        /*Lima*/      {0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0},
        /*Chimbote*/  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*Trujillo*/  {1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        /*Pacasmayo*/ {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        /*Cajamarca*/ {0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1},
        /*Chepen*/    {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        /*Chiclayo*/  {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
        /*Piura*/     {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        /*Jaen*/      {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        /*Cajabamba*/ {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
        /*Moyobamba*/ {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        /*Tarapoto*/  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    };

public:
    Viajes(){};
    ~Viajes(){};

    void selecionarDestino();
    void selecionarOrigen();
    void leerArchivo();
    void escribirArchivo();
};

void Viajes :: selecionarDestino()
{
    cout << "\nElija, de la lista, el destino del viaje (1 - " << getSizeDestino() << ")";

    for (int i = 0; i < getSizeDestino(); i++)
    {
        cout << "\n" << i + 1 << " " << getDestino(i);
    }
}

void Viajes :: selecionarOrigen()
{
    cout << "\nElija, de la lista, el origen del viaje (1 - " << getSizeOrigen() << ")";

    for (size_t i = 0; i < getSizeOrigen(); i++)
    {
        cout << "\n" << i + 1 << " " << getOrigen(i);
    }
}