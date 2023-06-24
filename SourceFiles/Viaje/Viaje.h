#pragma once
#include "../Libraries.h"

#include "../Persona.h"
#include "../Algoritmos/NodoLista.h"
#include "../VehiculoTransporte.h"
#include "../Algoritmos/Grafo.h"
#include "../Rutas.h"

struct PersonaInf
{
    int Precio = 0;
    Persona *personaViaje = new Persona;
};

class Viaje : public Rutas
{
public:
    int cantidadPasajeros;
//    NodoLista<PersonaInf> *listaPasajeros = NULL;
    PersonaInf *pasajero = new PersonaInf();
    TotalRuta<Bus> *TRtmp;

    int codigoO,codigoD;

public:
    Viaje(int codigoO, int codigoD, int cantidadPasajeros, TotalRuta<Bus> *busTmp);
    Viaje(int codigoO, int codigoD, PersonaInf *piTMP, TotalRuta<Bus> *busTmp);
    ~Viaje();

    void agregarPasajero();
    void setRutaBus(TotalRuta<Bus> *busTmp) { TRtmp = busTmp; }
    void mostrarAsientos();
    void seleccionarAsientos();
    void mostrarBuses();
    void AsientoPersona(PersonaInf *pTMP, Bus *busTMP);
};

Viaje::Viaje(int codigoO, int codigoD, int cantidadPasajeros, TotalRuta<Bus> *busTmp)
{
    this->codigoO = codigoO;
    this->codigoD = codigoD;
    this->cantidadPasajeros = cantidadPasajeros;

    TRtmp = busTmp;    
}

Viaje::Viaje(int codigoO, int codigoD, PersonaInf * piTMP, TotalRuta<Bus> *busTmp)
{
    this->codigoO = codigoO;
    this->codigoD = codigoD;
    this->cantidadPasajeros = cantidadPasajeros;

    TRtmp = busTmp;
}

Viaje::~Viaje()
{
}

void Viaje ::mostrarAsientos()
{
  
}

void Viaje :: agregarPasajero()
{
    for (int i = 0; i <= cantidadPasajeros - 1; i++)
    {
        //PersonaInf * personaGrupo = new PersonaInf();

        #if RAD == 0
        //personaGrupo->personaViaje->typePersona();
        pasajero->personaViaje->typePersona();
        #elif RAD == 1
        pasajero->personaViaje->randomPersona();
        //personaGrupo->personaViaje->randomPersona();
        #endif

        //listaPasajeros->push(&listaPasajeros, personaGrupo);
    }
}

void Viaje :: mostrarBuses()
{
    cout << "\n";
    cout << "Los buses para su destino son: " << "\n";
    NodoLista<Bus> * nlbusTMP = TRtmp->rutaAlDestino;
    Bus * busTMP = NULL;
    for (int i = 1; nlbusTMP != NULL; nlbusTMP = nlbusTMP->nextElemento(nlbusTMP))
    {
        busTMP = nlbusTMP -> getElemento(nlbusTMP);
        cout << "Bus " << i << ": " << getLugar(busTMP->getOrigen()) << " con destino a " << getLugar(busTMP->getDestino()) << "\n";
        i++;
    }
    cont();
}

void Viaje ::seleccionarAsientos()
{
    NodoLista<PersonaInf> * nlpiTMP;
    NodoLista<Bus> *nlbusTMP = TRtmp->rutaAlDestino;
    Bus *busTMP = NULL;
    for (int i = 1; nlbusTMP != NULL; nlbusTMP = nlbusTMP->nextElemento(nlbusTMP))
    {
        clearScreen;
        busTMP = nlbusTMP->getElemento(nlbusTMP);
        cout << "Selecione los asientos para el bus " << i << " "<< getLugar(busTMP->getOrigen()) << " con destino a " << getLugar(busTMP->getDestino()) << "\n";
        cout << "Letra A al C: Clase A; D al G: Clase B; y H al J: Clase C\n" << "El precio afecta dependiendo de la clase selecionada\n\n";
        busTMP->mostrarAsientos();
        AsientoPersona(pasajero, busTMP);
        /*
        nlpiTMP = listaPasajeros;
        for (; nlpiTMP != NULL; nlpiTMP = nlpiTMP->nextElemento(nlpiTMP))
        {
            AsientoPersona(nlpiTMP->getElemento(nlpiTMP), busTMP);
        }
        */
        i++;
    }

    cout << "El costo final por pasajero es: ";
    /*
    nlpiTMP = listaPasajeros;
    for (; nlpiTMP != NULL; nlpiTMP = nlpiTMP->nextElemento(nlpiTMP))
    {
        cout << nlpiTMP->getElemento(nlpiTMP)->personaViaje->getNombre() + nlpiTMP->getElemento(nlpiTMP)->personaViaje->getApellido();
        cout << " S/." << nlpiTMP->getElemento(nlpiTMP)->Precio << "\n";
    }
    */
    cout << pasajero->personaViaje->getNombre() + pasajero->personaViaje->getApellido();
    cout << " S/." << pasajero->Precio << "\n";
}

void Viaje :: AsientoPersona(PersonaInf * pTMP, Bus * busTMP)
{
    cout << "Selecione el asiento para el pasajero: \n";
    cout << pTMP->personaViaje->getNombre() << " " << pTMP->personaViaje->getApellido();
    
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

    busTMP->posicionarAsiento(pTMP->personaViaje,asientoletra, asientonumero);
    
    switch (int(busTMP->accesoAsiento(asientoletra,asientonumero)->claseAsiento))
    {
        case 65:
            pTMP->Precio = pTMP->Precio + busTMP->gettiempoEstimado() * 1.3;
            break;
        case 66:
            pTMP->Precio = pTMP->Precio + busTMP->gettiempoEstimado() * 1;
            break;
        case 67:
            pTMP->Precio = pTMP->Precio + busTMP->gettiempoEstimado() * 0.7;
            break;
        default:
        break;
    }

}