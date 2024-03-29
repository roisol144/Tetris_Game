#ifndef __GENERAL_H
#define __GENERAL_H

#include <windows.h> // for gotoxy
#include <process.h> // for system
#include <conio.h>
#include <iostream>
#include <random>
#include <cstdlib> // for std::rand and std::srand
#include <ctime> 
#include <cmath>
using namespace std;

void gotoxy(int x, int y);
void clrscr();
void ShowConsoleCursor(bool showFlag);

#endif // __GENERAL_H