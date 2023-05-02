#include "Libraries.h"
#include "App.h"
#include "Bus.h"

int main()
{

    Bus *chama = new Bus();

    chama ->generarAsientos();

    chama ->mostrarAsientos();
}
