#include "Libraries.h"
#include "App.h"
#include "Busv2.h"

int main()
{

    Bus *chama = new Bus();

    chama ->generarAsientos();

    chama ->mostrarAsientos();
}
