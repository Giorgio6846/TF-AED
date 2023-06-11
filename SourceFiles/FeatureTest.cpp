#include "Libraries.h"
//#include "Bus.h"
//#include "Algoritmos/NodoLista.h"
#include "Algoritmos/NodoArbolComplex.h"
#include "Algoritmos/NodoArbol.h"
#include "Algoritmos/NodoArbolComplexv2.h"
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

int main()
{
    srand(time(NULL));

    //NodoArbolComplex<string> *test = new NodoArbolComplex<string>();
    NodoArbolComplexv2<string> * test = new NodoArbolComplexv2<string>();

    //NodoArbol *testArbol = new NodoArbol();

    //testArbol->insertarValor(testArbol,1);
    //testArbol->insertarValor(testArbol, 2);
    //testArbol->insertarValor(testArbol, 3);
    //testArbol->insertarValor(testArbol, 4);
    //testArbol->insertarValor(testArbol, 5);

    //testArbol->recorrerArbol(testArbol);

    //cout << test->getN();

    test->insertar(1, "hola");
    //cout << test->getN();
    
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

    //NodoLista<int> *test = NULL;

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