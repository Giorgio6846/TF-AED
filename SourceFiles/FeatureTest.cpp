#include "Libraries.h"

//#include "Bus.h"
//#include "Algoritmos/NodoLista.h"
//#include "Algoritmos/NodoArbolComplex.h"
//#include "Algoritmos/NodoArbol.h"
//#include "Algoritmos/NodoArbolComplexv2.h"

//#include "Algoritmos/Grafo.h"
//#include "Viaje/ControladorViajes.h"
//#include "Algoritmos/NodoLista.h"

#include "Algoritmos/Grafo.h"
#include "VehiculoTransporte.h"
#include "Rutas.h"
#include "ControladorDataSet.h"

/*
void print(NodoLista <int> *test)
{
    int contador = 0;
    NodoLista<int> *tmp = test;
    while (tmp != NULL)
    {
        contador++;
        cout << "a" << contador << "a"; 
        cout << *tmp->elemento << " ";
        tmp = tmp -> next;
    }
}
*/

/*
void minHeapify(NodoLista<int> *&lista, int n, int i)
{
    int l = lista->left(lista);
    int r = lista->right(lista);

    int smallest(0);
    if (l <= (n - 1) && lista->obtenerPosicionElemento(&lista, l) < lista->obtenerPosicionElemento(&lista, i))
    {
        smallest = l;
    }
    else
    {
        smallest = i;
    }

    if (r <= (n - 1) && lista->obtenerPosicionElemento(&lista, r) < lista->obtenerPosicionElemento(&lista, smallest))
    {
        smallest = r;
    }
    if (smallest != i)
    {
        lista->SwapElementosDatos(lista, *(lista->obtenerPosicionElemento(&lista, i)), *(lista->obtenerPosicionElemento(&lista, smallest)));
        minHeapify(lista, n, smallest);
    }
}

void buildMinHeap(NodoLista<int> *&lista)
{
    for (int i = lista->contadorLista(lista) / 2 - 1; i >= 0; --i)
    {
        minHeapify(lista, lista->contadorLista(lista), i);
    }
}

void heapMinSort(NodoLista<int> *&lista, int n)
{
    buildMinHeap(lista);
    for (int i = n - 1; i > 0; --i)
    {
        lista->SwapElementosDatos(lista, *(lista->obtenerPosicionElemento(&lista, 0)), *(lista->obtenerPosicionElemento(&lista, i)));
        minHeapify(lista, --n, 0);
    }
}





void heapMaxSort(NodoLista<int> *lista)
{

}

void buildMaxHeap(NodoLista<int> *lista)
{

}

void maxHeapify(NodoLista<int> *lista)
{

}
*/
/*
struct test
{
    NodoLista<int> *tmp = NULL;
    int a;
};
*/

int main()
{



//cout << "Color	Foreground	Background Default	\033[39m	\033[49m Black	\033[30m	\033[40m Dark red	\033[31m	\033[41m Dark green	\033[32m	\033[42m Dark yellow (Orange-ish)	\033[33m	\033[43m Dark blue	\033[34m	\033[44m Dark magenta	\033[35m	\033[45m Dark cyan	\033[36m	\033[46m Light gray	\033[37m	\033[47m Dark gray	\033[90m	\033[100m Red	\033[91m	\033[101m Green	\033[92m	\033[101m Orange \033[93m	\033[103m Blue	\033[94m	\033[104m Magenta	\033[95m	\033[105m Cyan	\033[96m	\033[106m White	\033[97m	\033[107m";
    /*
    char test = 'A';
    string test1;
    ControladorDataSet * GA = new ControladorDataSet();
    GA ->lecturaIndexacion();
    test1 = test;
*/
 
/*
Grafo<NodoLista<Bus>, int, Bus> *grafoRutas = new Grafo<NodoLista<Bus>, int, Bus>;
Rutas *rTMP = new Rutas;

for (int i = 0; i < rTMP -> getSizeLugares(); i++)
{
    grafoRutas->agregarVertice(i);
}

for (int i = 0; i < rTMP->getSizeLugares(); i++)
{
    for (int j = 0; j < rTMP->getSizeLugares(); j++)
    {
        if (rTMP->accesoRutaDisponible(i, j) != 0)
        {
            NodoLista<Bus> *listaBus = NULL;
            for (int k = 0; k <= 3; k++)
            {
                Bus *tmp = new Bus(i, j, rTMP->accesoTiempoRuta(i, j));
                listaBus->push(&listaBus, tmp);
            }
            grafoRutas->agregarArcoVertice(i, j, rTMP->accesoTiempoRuta(i, j), listaBus);
        }
    }
}

TotalRuta<Bus> * TRtmp = new TotalRuta<Bus>;
NodoLista<Bus> *busTMP = NULL;

Bus * busETMP = NULL;

for (int i = 0; i < rTMP->getSizeLugares(); i++)
{
    for (int j = 0; j < rTMP->getSizeLugares(); j++)
    {
        if (i != j)
        {
            TRtmp = grafoRutas->rutaFinal(i, j, 1);

            busTMP = NULL;
            busTMP = TRtmp->rutaAlDestino;

            cout << "Origen: " << rTMP->getLugar(i) << " ";
            cout << "Destino: " << rTMP->getLugar(j) << " ";
            cout << "Tiempo: " << TRtmp->pesoEntero << "\n\n";
            
            for (; busTMP != NULL; busTMP = busTMP->nextElemento(busTMP))
            {
                busETMP = busTMP->getElemento(busTMP);
                cout << "Origen bus: " << rTMP->getLugar(busETMP->getOrigen()) << " ";
                cout << "Destino bus: " << rTMP->getLugar(busETMP->getDestino()) << "\n";
            }
            cout << "\n\n";
        }
    }
}
*/


/*
string test = "HOLA";

for (char ch : test)
    cout << ch << " ";
*/
// srand(time(NULL));

// ControladorViajes *claseViaje = new ControladorViajes();
// claseViaje->generarGrafo();

/*
//test *tmp1 = new test();
NodoLista<int> *tmp2 = NULL;
for (int i = 0; i < 100; i++)
{
    int *a = new int;
    *a = i;

    tmp2->push(&tmp2, a);
}

NodoLista<int> *tmp = tmp2;


NodoLista<int> *tmp1 = NULL;

tmp1->duplicadoLista(&tmp, &tmp1);


for (; tmp != NULL; tmp=tmp->nextElemento(tmp))
{
    tmp1->append(&tmp1, tmp->getElemento(tmp));
}
*/
/*
int *a = new int;
*a = 200;

tmp1->push(&tmp1, a);
tmp = tmp2;


for (; tmp != NULL; tmp=tmp->nextElemento(tmp))
{

    cout << *(tmp->getElemento(tmp)) << endl;
}


cout << "WOOHOO";

for (; tmp1 != NULL; tmp1 = tmp1->nextElemento(tmp1))
{

    cout << *(tmp1->getElemento(tmp1)) << endl;
}
*/
// NodoLista<int> *tmp2 = tmp1->tmp;
// cout << tmp1->tmp->contadorLista(tmp1->tmp);
/*
for (int i = 0; i < tmp2->contadorLista(tmp2); i++)
{

    cout << *(tmp1->tmp->getElemento(tmp1->tmp)) << endl;
    tmp1->tmp = tmp1->tmp->nextElemento(tmp1->tmp);
}
*/

/*
Grafo<int, int> *test = new Grafo<int,int>();

test->agregarVertice(0);
test->agregarArcoVertice(0,1,21,12);
test->agregarVertice(1);
test->agregarVertice(2);
test->agregarVertice(3);
test->agregarVertice(4);
test->agregarVertice(5);
test->agregarVertice(6);
test->agregarVertice(6);
test->agregarVertice(7);
test->agregarVertice(8);
test->agregarVertice(9);

test->imprimirVerticesTest();
*/
/*
 NodoLista<int> *testNodoLista = NULL;

 NodoLista<int> *tmp;
 NodoLista<int> *tmp1;



 tmp = testNodoLista;
 */
// cout << testNodoLista -> contadorLista(testNodoLista) << endl << endl;
/*
int *c = new int;
clear    *c = 444;

testNodoLista->insertarElementoPosicion(testNodoLista,c,99);
for (; tmp != NULL; tmp = tmp -> nextElemento(tmp))
{
    cout << *(tmp->getElemento(tmp)) << endl;
}
*/
/*
tmp = testNodoLista;

int *b = new int;
*b = 34;

//testNodoLista->append(&testNodoLista, b);

testNodoLista->insertarElementoPosicion(&testNodoLista, b, 99);
testNodoLista->SwapElementosDatos(testNodoLista, 1, 7);

testNodoLista->SwapElementosDireccion(testNodoLista, testNodoLista->obtenerPosicionElemento(&testNodoLista, 10), testNodoLista->obtenerPosicionElemento(&testNodoLista, 20));

tmp = testNodoLista;
tmp1 = testNodoLista;

for (int contador = 0; tmp != NULL;)
{
    cout << contador << " ";
    cout << *(tmp->getElemento(tmp)) << " ";
    cout << *(tmp1->obtenerPosicionElemento(&tmp1, contador)) << " ";
    cout << (tmp->getElemento(tmp)) << endl;

    tmp = tmp->nextElemento(tmp);

    contador++;
}



tmp = testNodoLista;
*/
/*
for (; tmp != NULL; tmp = tmp->nextElemento(tmp))
{
    cout << *(tmp->getElemento(tmp)) << endl;
}
*/
/*
buildMinHeap(tmp);
heapMinSort(tmp, tmp->contadorLista(tmp));

for (; tmp != NULL; tmp = tmp->nextElemento(tmp))
{
    cout << *(tmp->getElemento(tmp)) << endl;
}
*/

/*
 tmp = testNodoLista;
 tmp1 = testNodoLista;
 for (int contador = 0; contador <= tmp1->contadorLista(tmp1);)
 {
     cout << contador << " ";
     //cout << *(tmp->getElemento(tmp)) << " ";
     cout << *(tmp1->obtenerPosicionElemento(&tmp1, contador)) << endl;

     //tmp = tmp->nextElemento(tmp);
     //tmp1 = tmp1->nextElemento(tmp1);

     contador++;
 }
 */
/*
tmp = testNodoLista;
cout << tmp->contadorLista(tmp) << " ";


tmp = testNodoLista;
cout << *(tmp->obtenerPosicionElemento(&tmp, 100)) << endl;
*/
/*
cout << *(tmp->obtenerPosicionElemento(tmp, 99)) << endl;

tmp = testNodoLista;
cout << *(tmp->obtenerPosicionElemento(tmp, 10)) << endl;

cout << tmp->obtenerPosicionElemento(tmp, 10) << endl;
*/
// for (; tmp != NULL; tmp = tmp->nextElemento(tmp))
//{
//     cout << *(tmp->getElemento(tmp)) << endl;
// }

/*
while (tmp != NULL)
{
    cout << *(tmp->getElemento(tmp)) << endl;
    tmp->nextElemento(tmp);
}
*/

/*
int * a = new int;
*a = 2;

cout << a << endl;
cout << *a << endl;
cout << &a << endl;

int * b = new int;

testNodoLista -> push(&testNodoLista, a);

b = testNodoLista->getElemento(testNodoLista);

cout << b << endl;
cout << *b << endl;
cout << &b << endl;

cout << *(testNodoLista->getElemento(testNodoLista));

int *c = new int;
*c = 5;

cout << c << endl;
cout << *c << endl;
cout << &c << endl;

testNodoLista->append(&testNodoLista, c);

tmp = testNodoLista->nextElemento(testNodoLista);

int *d = new int;

d = testNodoLista->getElemento(testNodoLista);

cout << d << endl;
cout << *d << endl;
cout << &d << endl;

cout << *(testNodoLista->getElemento(testNodoLista));
*/

// NodoArbolComplex<string> *test = new NodoArbolComplex<string>();
// NodoArbolComplexv2<string> * test = new NodoArbolComplexv2<string>();

// NodoArbol *testArbol = new NodoArbol();

// testArbol->insertarValor(testArbol,1);
// testArbol->insertarValor(testArbol, 2);
// testArbol->insertarValor(testArbol, 3);
// testArbol->insertarValor(testArbol, 4);
// testArbol->insertarValor(testArbol, 5);

// testArbol->recorrerArbol(testArbol);

// cout << test->getN();

// test->insertar(1, "hola");
// cout << test->getN();
/*
test->insertar(0, "hola");
test->insertar(2, "test");
test->insertar(3, "ab");
test->insertar(4, "gewsf");
test->insertar(5, "owo");
test->insertar(6, "You're my wonderwall");
test->insertar(7, "Nyanpasu");
test->insertar(8, "I said maybe");
test->insertar(9, "You're gonna be the one that saves me");
test->insertar(10, "And afterall");
test->insertar(11, "Estaba escuchando oasis ok");

//cout << test->getData();
//cout << test->getN();

//cout << test->buscarNodoArbol(5);

cout << test->buscar(2)<< endl;
cout << test->buscar(4)<< endl;
cout << test->buscar(3)<< endl;
cout << test->buscar(5)<< endl;
cout << test->buscar(6)<< endl;
cout << test->buscar(7)<< endl;
cout << test->buscar(6)<< endl;
cout << test->buscar(7)<< endl;
cout << test->buscar(8) << endl;

cout << test->buscar(9) << endl;
cout << test->buscar(9) << endl;
cout << test->buscar(9) << endl;
cout << test->buscar(10) << endl;
cout << test->buscar(6) << endl;
cout << test->buscar(6) << endl;
*/
/*
    Persona * person = new Persona();

    for (int i = 0; i < 10; i++)
    {
        person->randomPersona();
    }
*/

//    Bus * bos = new Bus();

//    bos->generarAsientos();
//    bos->mostrarAsientos();

// NodoLista<int> *test = NULL;

/*
do
{
    cout << "Selecionar\n";
    cout << "1Agregar datos\n";

} while (1);
*/

/*
    int *a = new int;
    *a = 1;

    test -> push(&test, a);

    for (int i = 0; i < 10; i++)
    {
        int *a = new int;
        *a = i;

        test->push(&test, a);
    }

    cout << test->contadorLista(test) << " ";

    print(test);

    cout << "\n";

    int *b = new int;
    *b = 200;
    test->append(&test,b);

    cout << test->contadorLista(test) << " ";

    print(test);
*/

    


    /*
        int *b = new int;
        *b = 2;
        test->insertarElementoInicio(b);


    */
}