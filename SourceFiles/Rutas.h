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

<<<<<<< HEAD
    bool getRuta(int pos, int N){return rutas[pos][N]; }

    int seleccionarOrigen(){
    int opcionElegida;
    do
    {
        cout << "\nElija, de la lista, el origen del viaje (1 - " << getSizeOrigen() << " o 0 para regresar al menu de viajes) \n";
        for (size_t i = 0; i < getSizeOrigen(); i++)
        {
            cout << i + 1 << " " << getOrigen(i) << "\n";
        }
        cin >> opcionElegida;
    } while (!(opcionElegida >= 0 && opcionElegida <= 13));

    return opcionElegida-1;
    }

    void selecionarDestino(int *Origen){

    //Convierte de la matriz a un vector con los destinos disponibles para esa ruta especifica
    vector<string> DestinosDisponibles;
    for (int i = 0; i < getSizeDestino(); i++)
    {
        if (getRuta(*Origen,i))
        {
            DestinosDisponibles.push_back(getDestino(i));
        }
    }


=======
    bool getRuta(int fil, int col) { return rutas[fil][col]; }
>>>>>>> aa9b36fc99cdce3ee9db5deefe9491da7014701e
};

