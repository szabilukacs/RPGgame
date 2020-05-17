#ifndef JATEKOS_H
#define JATEKOS_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>

class jatekos
{
private:
	int o, v1, v2, d1, d2;
	int elet, ero, olesek, h1, h2;
	char s, c, h;
	clock_t begin, end;  // ido szamitasahoz
	double time_spent;
	int eero1, eero2, eero3, eero4,eero5;  // elensegek ereje, a kiiratasnal szukseges
	char nev[30];                          // jatekos neve
	void pozicio(int, int);                
	int ellenoriz(int, int);
	void eltuntet(int, int);

public:
	jatekos(int, int, int, int, int, int ,int, int);  
	void kiir(int, int);
	void lepes(char, int &);
	void mezo();
	void gameover();
	void vegsokiir();
	void elsokiir();
	void setcursor(bool , DWORD );
	friend class ellenseg;                // baratosztaly mert meg tudjak valtoztatni egymas allapotait
};


#endif // !JATEKOS_H


