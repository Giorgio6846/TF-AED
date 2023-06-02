#include "Libraries.h"
#include "Bus.h"

int main()
{
    srand(time(NULL));

/*
    Persona * person = new Persona();

    for (int i = 0; i < 10; i++)
    {
        person->randomPersona();
    }
*/

    Bus * bos = new Bus();

    bos->generarAsientos();
    bos->mostrarAsientos();
}