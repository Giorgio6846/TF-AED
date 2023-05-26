#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <limits>
#include <sstream>
#include <stdio.h>
#include <list>
#include <stdlib.h>

#ifdef _WIN32
#include <conio.h>
#include<windows.h>
#else
#include <curses.h>
#endif


#include <ctype.h>

using namespace std;


#ifdef _WIN32
#define clearScreen system("CLS");
#else
#define clearScreen system("clear");
#endif

#ifdef _WIN32
void cont()
{
    getch();
}
#else
void cont()
{
    getch();
    //char c;
    //cin >> c;
    //return c;
}
#endif

void ClearKeyboard()
{
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}