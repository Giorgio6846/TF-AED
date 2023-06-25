#pragma once

#include "../Libraries.h"
#include "../Persona.h"
#include "objetoEncomienda.h"
#include "../VehiculoTransporte.h"
#include "../Algoritmos/Grafo.h"
#include "../Algoritmos/NodoLista.h"

class Encomienda
{
public:
    Persona * cliente;
    objetoEncomienda * objeto;
    TotalRuta<Camion> * ruta;
    string codigo;

    Encomienda(Persona * cliente, objetoEncomienda * objeto, TotalRuta<Camion> * rutaTMP){
        this->cliente = cliente;
        this->objeto = objeto;
        this ->codigo = "";
        ruta = rutaTMP;
    };
    ~Encomienda(){};
    
    string generarCodigo(){
        while (codigo.size() != 10){
            if(rand()%2 == 1){
            this->codigo = codigo + to_string(rand()%10);
            }
            else{
            this->codigo = codigo + to_string(rand()%10);
            };
        }
        return this->codigo;
    }

    string getCodigo(){return this->codigo;}
    float getPeso(){return objeto->getPeso();}

};
