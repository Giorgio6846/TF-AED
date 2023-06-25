#pragma once 

#include "Libraries.h"
#include "Persona.h"
#include "HashTable.h"

/*

El bus va a tiene 60 asientos
Estos son categorizados por clase: A, B y C
Dependiendo de la clase el costo del precio es mayor
1  2  3  4  5  6  7  8  9  10
A  A  B  B  B  B  C  C  C  C
A  A  B  B  B  B  C  C  C  C
A  A  B  B  B  B  C  C  C  C
A  A  B  B  B  B  C  C  C  C
A  A  B  B  B  B  C  C  C  C
A  A  B  B  B  B  C  C  C  C
*/

class VehiculoTransporte
{
private:
    int Origen;
    int Destino;

    int tiempoEstimado;

    int cantidadDisponible;

public:
    VehiculoTransporte(int Origen = 0, int Destino = 0, int tiempoEstimado = 0)
    {
        this->Origen = Origen;
        this->Destino = Destino;
        this->tiempoEstimado = tiempoEstimado;
    }
    ~VehiculoTransporte() {}

    int getOrigen() { return this->Origen; }
    void setOrigen(int Origen) { this->Origen = Origen; }

    int getDestino() { return this->Destino; }
    void setDestino(int Destino) { this->Destino = Destino; }

    int gettiempoEstimado() { return this->tiempoEstimado; }
    void settiempoEstimado(int tiempoEstimado) { this->tiempoEstimado = tiempoEstimado; }

    int getCantidadDisponible() { return this->cantidadDisponible; }
    void setCantidadDisponible(int cantidadDisponible) { this->cantidadDisponible = cantidadDisponible; }
};

/*

Cambiar a HashTable
Este puede ser organizado a base del asiento
Por ejemplo: A10 este es organizado por A y despues en la posicion A es organizado de menor a mayor

*/

struct Asiento
{
    string letraAsiento;
    string numeroAsiento;

    char claseAsiento;
    Persona* usuarioPersona;
};

class Bus : public VehiculoTransporte
{
private:
    int columnaAsiento = 10;
    int filaAsiento = 6;

    //Bus asientos
    HashTable<Asiento> busAsientos;

public:
    Bus(int Origen, int Destino, int tiempoEstimado) : VehiculoTransporte(Origen, Destino, tiempoEstimado)
    {
        setOrigen(Origen);
        setDestino(Destino);
        settiempoEstimado(tiempoEstimado);
        setCantidadDisponible(columnaAsiento * filaAsiento);

        busAsientos.setSize(filaAsiento);
        generarAsientos();
    }
    ~Bus() {}

    void mostrarAsientos();
    void generarAsientos();
    bool AsientoDisponible(string letra, string numero);
    void posicionarAsiento(Persona* pTMP, string letra, string numero);
    Asiento* accesoAsiento(string letra, string numero);
    void AsientoRandom(Persona* pTMP);
    string LugarDisponible(string numeroAsiento);

    void agregarPasajero()
    {
        setCantidadDisponible(getCantidadDisponible() - 1);
    }
};

void Bus::AsientoRandom(Persona* pTMP)
{
    string numeroAsiento = "";
    string letraAsiento = "";
    bool cond = 1;
    if (getCantidadDisponible() <= 5)
    {
        for (int i = 1; i <= busAsientos.getSize() && cond; i++)
        {
            numeroAsiento = to_string(i);
            letraAsiento = LugarDisponible(numeroAsiento);
            if (letraAsiento != "")
            {
                cond = 0;
            }
        }
    }
    else
    {
        do
        {
            numeroAsiento = to_string(rand() % columnaAsiento);
            letraAsiento = LugarDisponible(numeroAsiento);
        } while (!AsientoDisponible(letraAsiento, numeroAsiento));
    }
    if (cond == 1)
    {
        posicionarAsiento(pTMP, letraAsiento, numeroAsiento);
    }
}

string Bus::LugarDisponible(string numeroAsiento)
{
    list tmp = busAsientos.buscarListaBus(numeroAsiento);
    for (auto* it : tmp)
    {
        if (it->usuarioPersona == NULL)
        {
            return it->letraAsiento;
        }
    }
    return "";
}

void Bus::mostrarAsientos()
{
    for (int i = 0; i < busAsientos.getSize(); i++)
    {
        string numeroAsiento = to_string(i + 1);
        list tmp = busAsientos.buscarListaBus(numeroAsiento);
        for (auto* it : tmp)
        {
            if (it->usuarioPersona == NULL)
            {
                cout << "\033[92m";
            }
            else
            {
                cout << "\033[91m";
            }

            cout << it->letraAsiento << it->numeroAsiento << " ";
        }
        cout << "\n";
    }
    cout << "\033[39m	\033[49m" << "\n";
}

void Bus::posicionarAsiento(Persona* pTMP, string letra, string numero)
{
    agregarPasajero();
    Asiento* tmp = accesoAsiento(letra, numero);
    tmp->usuarioPersona = pTMP;
}

Asiento* Bus::accesoAsiento(string letra, string numero)
{
    list tmp = busAsientos.buscarListaBus(numero);
    for (auto* it : tmp)
    {
        if (it->letraAsiento == letra)
        {
            return it;
        }
    }
    return NULL;
}

bool Bus::AsientoDisponible(string letra, string numero)
{
    Asiento* aTMP = accesoAsiento(letra, numero);
    if (aTMP == NULL)
    {
        return 0;
    }
    if (aTMP->usuarioPersona == NULL)
    {
        return 1;
    }
    return 0;
}

void Bus::generarAsientos()
{
    for (int i = 0; i < filaAsiento; i++)
    {
        for (int j = 0; j < columnaAsiento; j++)
        {
            Asiento* asientoTMP = new Asiento;
            asientoTMP->letraAsiento = char(65 + j);
            asientoTMP->numeroAsiento = to_string(i + 1);
            asientoTMP->claseAsiento = char((i <= 2) * 0 + (i >= 3 && i <= 6) * 1 + (i >= 7) * 2 + 65);

            busAsientos.insertBus(asientoTMP->numeroAsiento, asientoTMP);
        }
    }
}

class Camion : public VehiculoTransporte
{
private:
    /* data */
public:
    Camion(int Origen, int Destino, int tiempoEstimado) : VehiculoTransporte(Origen, Destino, tiempoEstimado)
    {
        setOrigen(Origen);
        setDestino(Destino);
        settiempoEstimado(tiempoEstimado);
        setCantidadDisponible(200);
    }
    ~Camion() {}
};


