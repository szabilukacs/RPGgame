#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "Functions.h"

using namespace std;

class jatek
{
private:
	int o, v1, v2, d1, d2, elet, ero, olesek, h1, h2;
	char s, c, h;
	void pozicio(int, int);
	int ellenoriz(int, int);
	void eltuntet(int, int);

public:
	jatek();
	void kiir(int, int);
	void lepes(char, int &);
	void mezo();
	void gameover();
	void vegsokiir();
	friend class ellenseg;
};

class ellenseg
{
private:
	int p1, p2, elete, eroe, elspeed;
	char s;
	void pozicio(int, int);
	void eltuntet(int p1, int p2) { pozicio(p1, p2); cout << " "; }
	void kiir(int, int);
	void nagyellenoriz(jatek &);
public:
	ellenseg(char, int, int);
	void randlepes(int &, jatek &);
	int ellenorize(int, int);
	friend class jatek;

};


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

void ellenseg::nagyellenoriz(jatek &A)
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
				A.gameover();
			else
			{
				A.elet = A.elet - eroe / 10;
				A.ero = A.ero - eroe / 10;
			}
		}
	}
}

void ellenseg::randlepes(int &nr, jatek &A)
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

jatek::jatek()
{
	o = 0;
	s = 'X';
	c = 'P';
	h = 'H';
	v1 = rand() % 24 + 2;
	v2 = rand() % 78 + 1;
	d1 = rand() % 24 + 2;
	d2 = rand() % 78 + 1;
	h1 = rand() % 24 + 2;
	h2 = rand() % 78 + 1;
	elet = 100;
	ero = 100;
	olesek = 0;
}

int jatek::ellenoriz(int d1, int d2)
{
	if ((d1 == 1) || (d1 == 26) || (d2 == 0) || (d2 == 79))
		return 0;
	if ((d1 == 13) && (d2 >= 20) && (d2 <= 26))
		return 0;
	if ((d1 == 6) && (d2 >= 61) && (d2 <= 72))
		return 0;
	if ((d2 == 55) && (d1 >= 11) && (d1 <= 17))
		return 0;
	return 1;
}

void jatek::mezo()
{
	pozicio(1, 0);
	for (int i = 1; i <= 8; i++)
		cout << "----------";
	for (int j = 1; j <= 24; j++)
	{
		pozicio(1 + j, 0);
		cout << "|";
	}
	pozicio(26, 0);
	for (int i = 1; i <= 8; i++)
		cout << "----------";
	for (int j = 1; j <= 24; j++)
	{
		pozicio(1 + j, 79);
		cout << "|";
	}

	pozicio(13, 20);
	cout << "-------";
	pozicio(6, 61);
	cout << "------------";
	for (int i = 11; i <= 17; i++)
	{
		pozicio(i, 55);
		cout << "|";
	}

	pozicio(0, 35);
	cout << "  A-Power:" << 50;
	cout << "  B-Power:" << 115;
	cout << "  C-Power:" << 130;
	cout << "  D-Power:" << 175;
	cout << "  W-Power:" << 275;
	cout << "  P-Power+";
	cout << "  H-Heal+" << "  ";
}

void jatek::eltuntet(int d1, int d2)
{
	pozicio(d1, d2);
	cout << " ";
}

void jatek::kiir(int d1, int d2)
{

	pozicio(d1, d2);
	cout << s;
	pozicio(v1, v2);
	cout << c;
	pozicio(h1, h2);
	cout << h;
	pozicio(0, 0);
	cout << "Points: " << o;
	cout << "  Life: " << elet;
	cout << "  Power: " << ero << "  ";

}
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void setcursor(bool visible, DWORD size)
{

	size = 20;

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void jatek::pozicio(int sor, int oszlop)
{
	COORD c;
	c.Y = sor;
	c.X = oszlop;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void jatek::lepes(char m, int &nr)
{
	switch (m)
	{
	case 'w':
		eltuntet(d1, d2);
		d1 = d1 - 1;
		break;
	case 'a':
		eltuntet(d1, d2);
		d2 = d2 - 1;
		break;
	case 's':
		eltuntet(d1, d2);
		d1 = d1 + 1;
		break;
	case 'd':
		eltuntet(d1, d2);
		d2 = d2 + 1;
		break;
	}
	nr++;
	if ((d1 == v1) && (d2 == v2))
	{
		ero = ero + 3;
		eltuntet(v1, v2);
		v1 = rand() % 24 + 2;
		v2 = rand() % 78 + 1;
	}
	if ((d1 == h1) && (d2 == h2))
	{
		elet = elet + 5;
		eltuntet(h1, h2);
		h1 = rand() % 24 + 2;
		h2 = rand() % 78 + 1;
	}
	if (ellenoriz(d1, d2) == 0)
		gameover();
	else
		kiir(d1, d2);

}

void jatek::gameover()
{
	char a[18][60];
	ifstream be("valami.txt");
	for (int i = 0; i <= 14; i++)
		for (int j = 0; j <= 59; j++)
			be >> a[i][j];
	for (int i = 0; i <= 14; i++)
		for (int j = 0; j <= 59; j++)
			if (a[i][j] == '0')
				a[i][j] = ' ';
	for (int i = 1; i <= 3; i++)
	{
		system("cls");
		Sleep(700);
		for (int i = 0; i <= 14; i++)
		{
			for (int j = 0; j <= 59; j++)
				cout << a[i][j];
			cout << endl;
		}
		Sleep(1000);
	}
	vegsokiir();
}

void jatek::vegsokiir()
{
	system("cls");
	pozicio(5, 10);
	cout << "Points: " << o;
	pozicio(7, 10);
	cout << "Kills: " << olesek;
	pozicio(9, 10);
	cout << "Life: " << elet;
	cout << endl;
	cout << endl;
	Sleep(5000);
	exit(0);
}


int main()
{
	int nr = 1;
	char m = 'h';
	srand(time(NULL));
	jatek A;
	ellenseg E1('B', 115, 4);
	ellenseg E2('C', 130, 3);
	ellenseg E3('D', 175, 3);
	ellenseg E4('A', 50, 2);
	ellenseg E5('A', 50, 2);
	ellenseg E6('A', 50, 2);
	ellenseg E7('A', 50, 2);
	ellenseg E8('B', 115, 4);
	ellenseg E9('B', 115, 4);
	ellenseg E10('B', 115, 4);
	ellenseg E11('B', 115, 4);
	ellenseg E12('C', 130, 3);
	ellenseg E13('C', 130, 3);
	ellenseg E14('D', 175, 3);
	ellenseg E15('D', 175, 3);
	ellenseg E16('W', 275, 2);

	// nev beiras + kezdo kep
	setcursor(0, 0);
	cout << "Move with the X and win the game!";
	A.mezo();
	while (m != 'q')
	{
		m = _getch();
		A.lepes(m, nr);
		E1.randlepes(nr, A);
		E2.randlepes(nr, A);
		E3.randlepes(nr, A);
		E4.randlepes(nr, A);
		E5.randlepes(nr, A);
		E6.randlepes(nr, A);
		E7.randlepes(nr, A);
		E8.randlepes(nr, A);
		E9.randlepes(nr, A);
		E10.randlepes(nr, A);
		E11.randlepes(nr, A);
		E12.randlepes(nr, A);
		E13.randlepes(nr, A);
		E14.randlepes(nr, A);
		E15.randlepes(nr, A);
		E16.randlepes(nr, A);
	}
	A.vegsokiir();

	return 0;
}
