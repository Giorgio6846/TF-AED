#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <limits>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <list>
#include <algorithm>

#ifdef _WIN32
#include <conio.h>
#include<windows.h>
#else
#include <curses.h>
#endif


#include <ctype.h>

using namespace std;

//Funciones de uso comun para toda la applicacion

/*
clearScreen
- Limpieza de pantalla

cont()
Uso del getch en los sistemas operativos Windows y Unix

ClearKeyboard()
Limpieza del cin
*/

//Limpieza de pantalla
#ifdef _WIN32
#define VER 1
#define RAD 1
#define clearScreen system("CLS");
#else
#define clearScreen system("clear");
#endif

//Uso del getch en los sistemas operativos Windows y Unix
#ifdef _WIN32
void cont()
{
    getch();
}
#else
void cont()
{
    getch();
    // char c;
    // cin >> c;
    // return c;
}
#endif

// Limpieza del cin
void ClearKeyboard()
{
    cin.clear();
    cin.ignore(20000, '\n');
}

int randDigit(int exception)
{
    return (rand() % (10 - exception) + exception);
}