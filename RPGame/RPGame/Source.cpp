#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "Jatekos.h"
#include "Ellenseg.h"

using namespace std;


int main()
{
	int nr = 1;
	char m = 'h';
	srand(time(NULL));
	jatekos A(100,100,0);
	// fokazat
	ellenseg E1('d', 115, 4);
	ellenseg E2('B', 130, 3);
	ellenseg E3('M', 175, 3);
	ellenseg E4('A', 50, 2);
	ellenseg E5('A', 50, 2);
	ellenseg E6('A', 50, 2);
	ellenseg E7('A', 50, 2);
	ellenseg E8('d', 115, 4);
	ellenseg E9('d', 115, 4);
	ellenseg E10('d', 115, 4);
	ellenseg E11('d', 115, 4);
	ellenseg E12('B', 130, 3);
	ellenseg E13('B', 130, 3);
	ellenseg E14('M', 175, 3);
	ellenseg E15('M', 175, 3);
	ellenseg E16('D', 275, 2);

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
