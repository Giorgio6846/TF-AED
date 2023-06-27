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
#include <ctype.h>

// Librerias Windows
#ifdef _WIN32
#include <conio.h>
#include<windows.h>
#endif

// Librerias macOS
#ifdef __APPLE__
#include <curses.h>
#endif 

// Librerias Linux

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

//Funciones Windows
    //Limpieza de pantalla y Variables

    #ifdef _WIN32
    #define VER 1
    #define RAD 1
    #define useDataSet 0
    #define clearScreen system("CLS");
    #endif

    //Getch

    #ifdef _WIN32
    void cont()
    {
        _getch();
    }
    #endif

    #ifdef __linux__
    #define VER 1
    #define RAD 1
    #endif

//Funciones macOS
    //Limpieza de pantalla

    #ifdef __APPLE__
    #define clearScreen system("clear");
    #endif

    //Getch

    #ifdef __APPLE__
    void cont()
    {
        // getch();
        char c;
        cin >> c;
        return;
    }
    #endif

    // Funciones Linux
    // Limpieza de pantalla

    #ifdef __linux__
    #define clearScreen system("clear");
    #endif

    // Getch

    #ifdef __linux__
    void cont()
    {
        // getch();
        char c;
        cin >> c;
        return;
    }
    #endif


    //Funciones globales
    void
    ClearKeyboard()
    {
        cin.clear();
        cin.ignore(20000, '\n');
    }

    int randDigit(int exception)
    {
        return (rand() % (10 - exception) + exception);
    }