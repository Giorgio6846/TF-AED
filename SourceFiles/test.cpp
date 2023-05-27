#include "Libraries.h"
#include "Persona.h"

int main()
{
    srand(time(NULL));

    Persona * person = new Persona();

    for (int i = 0; i < 10; i++)
    {
        person->randomPersona();
    }
}