#include "Ellenseg.h"

using namespace std;


ellenseg::ellenseg(char _s, int _ero, int _elspeed)  // inicializalja az ellenseget a megadottak szerint
{
	p1 = rand() % 24 + 2;
	p2 = rand() % 78 + 1;
	if (ellenorize(p1, p2) == 0)                    // ha a kisebb akadalyokra generalta akkor ujakat general
	{
		p1 = rand() % 24 + 2;
		p2 = rand() % 78 + 1;
	}
	s = _s;
	elete = 100;
	eroe = _ero;
	elspeed = _elspeed;
}

void ellenseg::pozicio(int sor, int oszlop)
{
	COORD c;
	c.Y = sor;
	c.X = oszlop;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void ellenseg::kiir(int p1, int p2)   // kiirja az adott poziciora
{
	pozicio(p1, p2);
	cout << s;
}

void ellenseg::nagyellenoriz(jatekos &A)   // ellenorzi a jatekos es az ellenseg allapotat
{
	if ((A.d1 == p1) && (A.d2 == p2))
	{
		if (A.ero >= eroe)               // ha a jatekos az erosebb
		{
			A.olesek++;
			s = ' ';                    // eltunik a karakter 
			A.ero = A.ero + eroe / 10;  // no a jatekos ereje
			A.o = A.o + eroe / 10;      // no a pontszam is
			if (A.olesek == 16)        // ha megolt mindenkit akkor a vegere ert
				A.vegsokiir();
		}
		else                            // ha a szorny erosebb
		{
			if (eroe - A.ero > A.elet)  // ha az erok kulonbsege nagyobb a jatekos eletenel meghal
			{
				A.elet = 0;
				A.gameover();
			}
			else                       // kulonben csak gyengul 
			{
				A.elet = A.elet - eroe / 10;
				A.ero = A.ero - eroe / 10;
			}
		}
	}
}

void ellenseg::randlepes(int &nr, jatekos &A)  // general egy szamot 1-tol 4-ig az l-be, aszerint fog lepni
{
	int l;
	if (s != ' ')
	{
		nagyellenoriz(A);
		l = rand() % 4 + 1;
		if (nr%elspeed == 0)               // a nr mutatja a "sebesseget" az X-hez kepest mindig a nr-dik re fog lepni
		{
			switch (l)
			{
			case 1: eltuntet(p1, p2);
				p1 = p1 - 1;
				if (ellenorize(p1, p2) == 0)  // leellenorzi hogy jo helyt van-e, ha falnak ment, akkor kettot visszalepteti
					p1 = p1 + 2;
				break;
			case 2: eltuntet(p1, p2);
				p2 = p2 - 1;
				if (ellenorize(p1, p2) == 0)
					p2 = p2 + 2;
				break;
			case 3: eltuntet(p1, p2);
				p1 = p1 + 1;
				if (ellenorize(p1, p2) == 0)
					p1 = p1 - 2;
				break;
			case 4: eltuntet(p1, p2);
				p2 = p2 + 1;
				if (ellenorize(p1, p2) == 0)
					p2 = p2 - 2;
				break;
			}
			nagyellenoriz(A);
		}
		A.kiir(A.d1, A.d2);
		kiir(p1, p2);
	}

}

int ellenseg::ellenorize(int d1, int d2)
{
	if ((d1 == 1) || (d1 == 26) || (d2 == 0) || (d2 == 79))  // a palya szelei
		return 0;
	if ((d1 == 13) && (d2 >= 20) && (d2 <= 26))             // kisebb akadalyok
		return 0;
	if ((d1 == 6) && (d2 >= 61) && (d2 <= 72))
		return 0;
	if ((d2 == 55) && (d1 >= 11) && (d1 <= 17))
		return 0;
	else
		return 1;
}