#include "Libraries.h"

class Origen
{
private:
    vector<string> origen{"Lima", "Chimbote", "Trujillo", "Pacasmayo", "Cajamarca", "Chepen", "Chiclayo", "Piura", "Jaen", "Cajabamba", "Moyobamba", "Tarapoto"};
    int origenSelecionado;

public:
    Origen(){};
    ~Origen(){};

    

    int getSizeOrigen() { return origen.size(); }
    string getOrigen(int N) { return origen.at(N); }
};
