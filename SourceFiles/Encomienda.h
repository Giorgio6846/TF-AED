#include "Libraries.h"
#include "Rutas.h"

class Encomienda : public Rutas
{
private:

public:
    Encomienda(/* args */){};
    ~Encomienda(){};

    // Opcion seleccion
    int menuEncomienda();
    void reservaEncomienda();
    void reservaBusquedaEncomienda();
};

int Encomienda ::menuEncomienda()
{
    int opcionSelecionada;
    do
    {
        cout << "Selecione la opcion. \n";
        cout << "1. Agendar una encomienda \n";
        cout << "2. Eliminar una encomienda \n";
        cout << "3. Regresar al menu principal \n";

        cin >> opcionSelecionada;

        if (!(opcionSelecionada >= 1 && opcionSelecionada <= 4))
            cout << "La opcion seleccionada es incorrecta.\n";
        else
            return opcionSelecionada;
    } while (opcionSelecionada != 3);
    return opcionSelecionada;
}

void Encomienda ::reservaEncomienda()
{
    int Origen, Destino, cantidadUsuarios;

    Origen = Rutas :: selecionarOrigen();
    Destino = Rutas :: selecionarDestino(Origen);

    cout << "\n Ha selecionado el origen " << Rutas :: getOrigen(Origen);
    cout << "\n Ha selecionado el destino " << Rutas :: getDestino(Destino);
}

void Encomienda ::reservaBusquedaEncomienda()
{
}