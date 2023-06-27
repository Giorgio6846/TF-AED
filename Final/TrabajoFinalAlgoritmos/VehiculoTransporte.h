#pragma once 

#include "Libraries.h"
#include "Persona.h"
#include "Algoritmos/HashTable.h"

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
    int* Origen = new int;
    int* Destino = new int;

    int* tiempoEstimado = new int;

    int* cantidadDisponible = new int;

public:
    VehiculoTransporte(int Origen = 0, int Destino = 0, int tiempoEstimado = 0)
    {
        *this->Origen = Origen;
        *this->Destino = Destino;
        *this->tiempoEstimado = tiempoEstimado;
    }
    ~VehiculoTransporte()
    {
        Origen = NULL;
        Destino = NULL;
        tiempoEstimado = NULL;
        cantidadDisponible = NULL;

        delete cantidadDisponible;
        delete Origen;
        delete Destino;
        delete tiempoEstimado;
    }

    int getOrigen() { return *(this->Origen); }
    void setOrigen(int Origen) { *(this->Origen) = Origen; }

    int getDestino() { return *(this->Destino); }
    void setDestino(int Destino) { *(this->Destino) = Destino; }

    int gettiempoEstimado() { return *(this->tiempoEstimado); }
    void settiempoEstimado(int tiempoEstimado) { *(this->tiempoEstimado) = tiempoEstimado; }

    int getCantidadDisponible() { return *(this->cantidadDisponible); }
    void setCantidadDisponible(int cantidadDisponible) { *(this->cantidadDisponible) = cantidadDisponible; }
};

/*

Cambiar a HashTable
Este puede ser organizado a base del asiento
Por ejemplo: A10 este es organizado por A y despues en la posicion A es organizado de menor a mayor

*/

struct Asiento
{
    string* letraAsiento = new string;
    string* numeroAsiento = new string;

    char* claseAsiento = new char;
    Persona* usuarioPersona;
};

class Bus : public VehiculoTransporte
{
private:
    int * columnaAsiento = new int;
    int * filaAsiento = new int;

    //Bus asientos
    HashTable<Asiento> busAsientos;

public:
    Bus(int Origen, int Destino, int tiempoEstimado) : VehiculoTransporte(Origen, Destino, tiempoEstimado)
    {
        *columnaAsiento = 10;
        *filaAsiento = 6;

        setCantidadDisponible(*columnaAsiento * *filaAsiento);

        busAsientos.setSize(*filaAsiento);
        generarAsientos();
    }
    ~Bus()
    {
        columnaAsiento = NULL;
        filaAsiento = NULL;

        delete columnaAsiento;
        delete filaAsiento;
    }

    char getClaseAsiento(string letra, string numero)
    {
        return (*accesoAsiento(letra, numero)->claseAsiento);
    }

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
    string * numeroAsiento = new string("");
    string * letraAsiento = new string("");
    bool * cond = new bool(1);
    if (getCantidadDisponible() <= 5)
    {
        for (int i = 1; i <= busAsientos.getSize() && cond; i++)
        {
            *numeroAsiento = to_string(i);
            *letraAsiento = LugarDisponible(*numeroAsiento);
            if (*letraAsiento != "")
            {
                *cond = 0;
            }
        }
    }
    else
    {
        do
        {
            *numeroAsiento = to_string(rand() % *columnaAsiento);
            *letraAsiento = LugarDisponible(*numeroAsiento);
        } while (!AsientoDisponible(*letraAsiento, *numeroAsiento));
    }
    if (*cond == 1)
    {
        posicionarAsiento(pTMP, *letraAsiento, *numeroAsiento);
    }

    delete numeroAsiento, letraAsiento, cond;
}

string Bus::LugarDisponible(string numeroAsiento)
{
    list<Asiento*> tmp = busAsientos.buscarListaBus(numeroAsiento);
    for (auto* it : tmp)
    {
        if (it->usuarioPersona == NULL)
        {
            string* sTMP = new string(*(it->letraAsiento));
            tmp.clear();
            return *sTMP;
        }
    }
    return "";
}

void Bus::mostrarAsientos()
{
    for (int i = 0; i < busAsientos.getSize(); i++)
    {
        string * numeroAsiento = new string(to_string(i + 1));
        list<Asiento*> tmp = busAsientos.buscarListaBus(*numeroAsiento);
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

            cout << *it->letraAsiento << *it->numeroAsiento << " ";
        }
        numeroAsiento = NULL;
        delete numeroAsiento;

        tmp.clear();

        cout << "\n";
    }
    cout << "\033[39m	\033[49m" << "\n";
}

void Bus::posicionarAsiento(Persona* pTMP, string letra, string numero)
{
    agregarPasajero();
    Asiento* tmp = accesoAsiento(letra, numero);
    tmp->usuarioPersona = pTMP;
    tmp = NULL;
    delete tmp;
}

Asiento* Bus::accesoAsiento(string letra, string numero)
{
    list<Asiento*> tmp = busAsientos.buscarListaBus(numero); 
    for (auto* it : tmp)
    {
        if (*(it->letraAsiento) == letra)
        {
            Asiento * aTMP = it;
            tmp.clear();
            return aTMP;
        }
    }
    return NULL;
}

bool Bus::AsientoDisponible(string letra, string numero)
{
    Asiento* aTMP = accesoAsiento(letra, numero);
    if (aTMP == NULL)
    {
        aTMP = NULL;
        delete aTMP;
        return 0;
    }
    if (aTMP->usuarioPersona == NULL)
    {
        aTMP = NULL;
        delete aTMP;
        return 1;
    }
    aTMP = NULL;
    delete aTMP;
    return 0;
}

void Bus::generarAsientos()
{
    for (int i = 0; i < *filaAsiento; i++)
    {
        for (int j = 0; j < *columnaAsiento; j++)
        {
            Asiento* asientoTMP = new Asiento;
            *(asientoTMP->letraAsiento) = char(65 + j);
            *(asientoTMP->numeroAsiento) = to_string(i + 1);
            *(asientoTMP->claseAsiento) = char((i <= 2) * 0 + (i >= 3 && i <= 6) * 1 + (i >= 7) * 2 + 65);
            asientoTMP->usuarioPersona = nullptr;

            busAsientos.insertBus(*(asientoTMP->numeroAsiento), asientoTMP);
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
        setCantidadDisponible(200);
    }
    ~Camion() {}
};


