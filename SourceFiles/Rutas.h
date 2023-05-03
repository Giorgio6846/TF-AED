#include "Libraries.h"

class Rutas
{
private:
    
    vector<string> origen{"Lima", "Chimbote", "Trujillo", "Pacasmayo", "Cajamarca", "Chepen", "Chiclayo", "Piura", "Jaen", "Cajabamba", "Moyobamba", "Tarapoto"};
    vector<string> destino{"Lima", "Chimbote", "Trujillo", "Pacasmayo", "Cajamarca", "Chepen", "Chiclayo", "Piura", "Jaen", "Cajabamba", "Moyobamba", "Tarapoto"};

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
    int destino, origen;
    Rutas(/* args */){};
    ~Rutas(){};

    int getSizeDestino() { return destino.size(); }
    string getDestino(int N) { return destino.at(N); }

    int getSizeOrigen() { return origen.size(); }
    string getOrigen(int N) { return origen.at(N); }

    bool getRuta(int pos, int N){return rutas[pos][N]; }
};

