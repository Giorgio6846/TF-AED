#pragma once
#include "../Libraries.h"

#include "../Persona.h"
#include "../Algoritmos/NodoLista.h"
#include "../VehiculoTransporte.h"
#include "../Algoritmos/Grafo.h"
#include "../Rutas.h"

class Viaje : public Rutas
{
private:
    TotalRuta<Bus> *TRtmp;
    int * precio = new int(0);
    Persona *pasajero = new Persona;

public:
    Viaje(TotalRuta<Bus> *busTmp);
    Viaje(Persona *pTMP, TotalRuta<Bus> *busTmp);
    ~Viaje();

    TotalRuta<Bus>* getRutaBus() { return TRtmp; }
    int getOrigenViaje() {return TRtmp->Origen;}
    int getDestinoViaje(){ return TRtmp -> Destino; }
    int getTiempoDuracion() { return TRtmp->pesoEntero;}

    int getPrecio() { return *precio; }
    void setPrecio(int Precio) { *precio = Precio; }

    Persona* getPasajero() { return this->pasajero; }
    void agregarPasajero();
    void setRutaBus(TotalRuta<Bus>* busTmp) { TRtmp = busTmp; }
    void seleccionarAsientos();
    void mostrarBuses();
    void AsientoPersona(Persona* pTMP, Bus* busTMP);
    void AsignacionPrecio(Bus* busTMP, char claseAsiento);

    void informacionViaje();
};

Viaje::Viaje(TotalRuta<Bus> *busTmp)
{
    TRtmp = busTmp;    
}

Viaje::Viaje(Persona * pTMP, TotalRuta<Bus> *busTmp)
{
    TRtmp = busTmp;
    pasajero = pTMP;
}

Viaje::~Viaje()
{
}

void Viaje :: agregarPasajero()
{
    #if RAD == 0
    pasajero->typePersona();
    #elif RAD == 1
    pasajero->randomPersona();
    #endif
}

void Viaje :: informacionViaje()
{
    cout << "Origen: " << getLugar(getOrigenViaje()) << "\n";
    cout << "Destino: " << getLugar(getDestinoViaje()) << "\n";
}

void Viaje :: mostrarBuses()
{
    cout << "\n";
    cout << "Los buses para su destino son: " << "\n";
    NodoLista<Bus> * nlbusTMP = TRtmp->rutaAlDestino;
    Bus * busTMP = NULL;
    for (int i = 1; nlbusTMP != NULL; nlbusTMP = nlbusTMP->nextElemento(nlbusTMP))
    {
        busTMP = nlbusTMP -> getElemento();
        cout << "Bus " << i << ": " << getLugar(busTMP->getOrigen()) << " con destino a " << getLugar(busTMP->getDestino()) << "\n";
        i++;
    }
    cont();
}

void Viaje ::seleccionarAsientos()
{
    NodoLista<Bus> *nlbusTMP = TRtmp->rutaAlDestino;
    Bus *busTMP = NULL;
    for (int i = 1; nlbusTMP != NULL; nlbusTMP = nlbusTMP->nextElemento(nlbusTMP))
    {
        clearScreen;
        busTMP = nlbusTMP->getElemento();
        cout << "Selecione los asientos para el bus " << i << " "<< getLugar(busTMP->getOrigen()) << " con destino a " << getLugar(busTMP->getDestino()) << "\n";
        cout << "Letra A al C: Clase A; D al G: Clase B; y H al J: Clase C\n" << "El precio afecta dependiendo de la clase selecionada\n\n";
        busTMP->mostrarAsientos();
        AsientoPersona(pasajero, busTMP);
        i++;
    }

    cout << "El costo final del pasajero es: ";
   
    cout << pasajero->getNombre() + " " + pasajero->getApellido() + " ";
    cout << " S/. " << getPrecio() << "\n";
    cont();
}

void Viaje :: AsientoPersona(Persona * pTMP, Bus * busTMP)
{
    cout << "Selecione el asiento para el pasajero: \n";
    cout << pTMP->getNombre() + " " + pTMP->getApellido() + " ";
    
    string asientostr, asientoletra, asientonumero;

    bool cond = 0;
    do
    {
        cin >> asientostr;
        if (asientostr.size() == 2 || asientostr.size() == 3)
        {
            cond = 1;
            asientoletra = asientostr.at(0);
            asientonumero = asientostr.at(1);
            if (asientostr.size() == 3)
            {
                asientonumero = asientonumero + asientostr.at(2);
            }
            asientoletra = toupper(asientoletra.at(0));
            if (!(busTMP->AsientoDisponible(asientoletra, asientonumero)))
            {
                cout << "El asiento esta ocupado";
                asientostr = "";
                asientonumero = "";
                asientoletra = "";
                cond = 0;
            }
        }
        else
        {
            cout << "El asiento escrito es incorrecto";
            cond = 0;
        }
    } while (cond == 0);    

    busTMP->posicionarAsiento(pasajero,asientoletra, asientonumero);
    AsignacionPrecio(busTMP, busTMP->getClaseAsiento(asientoletra,asientonumero));
}

void Viaje :: AsignacionPrecio(Bus * busTMP,char claseAsiento)
{
    switch (int(claseAsiento))
    {
    case 65:
        setPrecio(getPrecio() + busTMP->gettiempoEstimado() * 1.3);
        break;
    case 66:
        setPrecio(getPrecio() + busTMP->gettiempoEstimado() * 1);
        break;
    case 67:
        setPrecio(getPrecio() + busTMP->gettiempoEstimado() * 0.7);
        break;
    default:
        break;
    }
}