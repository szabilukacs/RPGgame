#include "Ellenseg.h"

using namespace std;


ellenseg::ellenseg(char _s, int _ero, int _elspeed)
{
	p1 = rand() % 24 + 2;
	p2 = rand() % 78 + 1;
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

void ellenseg::kiir(int p1, int p2)
{
	pozicio(p1, p2);
	cout << s;
}

void ellenseg::nagyellenoriz(jatekos &A)
{
	if ((A.d1 == p1) && (A.d2 == p2))
	{
		if (A.ero >= eroe)
		{
			A.olesek++;
			s = ' ';
			A.ero = A.ero + eroe / 10;
			A.o = A.o + eroe / 10;
			if (A.olesek == 16)
				A.vegsokiir();
		}
		else
		{
			if (eroe - A.ero > A.elet)
			{
				A.elet = 0;
				A.gameover();
			}
			else
			{
				A.elet = A.elet - eroe / 10;
				A.ero = A.ero - eroe / 10;
			}
		}
	}
}

void ellenseg::randlepes(int &nr, jatekos &A)
{
	int l;
	if (s != ' ')
	{
		nagyellenoriz(A);
		l = rand() % 4 + 1;
		if (nr%elspeed == 0)
		{
			switch (l)
			{
			case 1: eltuntet(p1, p2);
				p1 = p1 - 1;
				if (ellenorize(p1, p2) == 0)
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
	if ((d1 == 1) || (d1 == 26) || (d2 == 0) || (d2 == 79))
		return 0;
	if ((d1 == 13) && (d2 >= 20) && (d2 <= 26))
		return 0;
	if ((d1 == 6) && (d2 >= 61) && (d2 <= 72))
		return 0;
	if ((d2 == 55) && (d1 >= 11) && (d1 <= 17))
		return 0;
	else
		return 1;
}