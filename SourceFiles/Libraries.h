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
#endif

#include <ctype.h>

using namespace std;


#ifdef _WIN32
#define clearScreen system("CLS");
#else
#define clearScreen system("clear");
#endif

#ifdef _WIN32
char getChar()
{
    return getch();
}
#else
char getChar()
{
    char c;
    cin >> c;
    return c;
}
#endif
