#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

#ifdef _WIN32
#define clearScreen system("CLS");
#else
#define clearScreen system("clear");
#endif
