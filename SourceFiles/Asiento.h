#include "Libraries.h"
#include "Persona.h"

class Asiento
{
private:
    string ubicacion;
    char clase;
public:
    Asiento(string ubicacion, char clase);
    ~Asiento();
};

Asiento::Asiento(string ubicacion, char clase)
{
    this -> ubicacion = ubicacion;
    this -> clase = clase;
}

Asiento::~Asiento()
{
}
