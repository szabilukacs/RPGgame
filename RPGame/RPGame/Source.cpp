#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "Jatekos.h"
#include "Ellenseg.h"

using namespace std;

void fokozat(int &a)
{

	cout << endl << endl << endl;
	cout << "               Choose a difficulty level:" << endl;
	cout << "               1-EASY" << endl;
	cout << "               2-NORMAL" << endl;
	cout << "               3-HARD" << endl;
	cin >> a;
	
}

int main()
{
	int nr = 1;
	int level;
	char m = 'h';
	srand(time(NULL));
	fokozat(level);
	int e1, e2, e3, e4, e5;
	switch (level)
	{
	case 1:   //easy
		e1 = 50;
		e2 = 75;
		e3 = 100;
		e4 = 155;
		e5 = 205;
		break;
	case 2:   //normal
		e1 = 50;
		e2 = 115;
		e3 = 130;
		e4 = 175;
		e5 = 275;
		break;
	case 3:   //hard
		e1 = 75;
		e2 = 130;
		e3 = 175;
		e4 = 255;
		e5 = 375;
		break;
	default:   //easy
		e1 = 50;
		e2 = 115;
		e3 = 130;
		e4 = 175;
		e5 = 275;
		break;
	}
	
	
		jatekos A(100, 100, 0, e1, e2, e3, e4, e5);  
		ellenseg E1('d', e2, 4);
		ellenseg E2('B', e3, 3);
		ellenseg E3('M', e4, 3);
		ellenseg E4('A', e1, 2);
		ellenseg E5('A', e1, 2);
		ellenseg E6('A', e1, 2);
		ellenseg E7('A', e1, 2);
		ellenseg E8('d', e2, 4);
		ellenseg E9('d', e2, 4);
		ellenseg E10('d', e2, 4);
		ellenseg E11('d', e2, 4);
		ellenseg E12('B', e3, 3);
		ellenseg E13('B', e3, 3);
		ellenseg E14('M', e4, 3);
		ellenseg E15('M', e4, 3);
		ellenseg E16('D', e5, 2);

		// optimalizalni, kommentelni
		A.setcursor(0, 0);
		A.elsokiir();
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
