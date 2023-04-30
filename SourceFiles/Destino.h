#include "Libraries.h"


class Destino
{
private:
    vector<string> destino{"Lima", "Chimbote", "Trujillo", "Pacasmayo", "Cajamarca", "Chepen", "Chiclayo", "Piura", "Jaen", "Cajabamba", "Moyobamba", "Tarapoto"};
    int destinoSelecionado;
    
public:
    Destino(){};
    ~Destino(){};

    int getSizeDestino(){return destino.size();}
    string getDestino(int N) {return destino.at(N);}
};