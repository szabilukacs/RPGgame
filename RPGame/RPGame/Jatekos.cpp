#include "Jatekos.h"

using namespace std;

jatekos::jatekos(int _elet, int _ero, int _olesek, int _eero1, int _eero2, int _eero3, int _eero4, int _eero5)
{
	o = 0;                      // pontok 
	s = 'X';                    // a felhasznalo karaktere 
	c = 'P';                    // +ero karaktere
	h = 'H';                    //  +elet karaktere
	v1 = rand() % 24 + 2;		// a fentiek pozicioi random generalva a palyan belul
	v2 = rand() % 78 + 1;
	d1 = rand() % 24 + 2;
	d2 = rand() % 78 + 1;
	h1 = rand() % 24 + 2;
	h2 = rand() % 78 + 1;
	elet = _elet;				// jatekos elete
	ero = _ero;					//jatekos ereje
	olesek = _olesek;			// olesek szama
	eero1 = _eero1;				// ellensegek ereje
	eero2 = _eero2;
	eero3 = _eero3;
	eero4 = _eero4;
	eero5 = _eero5;
}

int jatekos::ellenoriz(int d1, int d2)   // ellenorzi hogy a jatekos a palya szelen vagy az akadalyokon van-e
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

void jatekos::mezo()   // kiirja a palyat
{
	pozicio(1, 0);
	cout << "--------------------------------------------------------------------------------";
	for (int j = 1; j <= 24; j++)
	{
		pozicio(1 + j, 0);
		cout << "|";
	}
	pozicio(26, 0);
	cout << "--------------------------------------------------------------------------------";
	for (int j = 1; j <= 24; j++)
	{
		pozicio(1 + j, 79);
		cout << "|";
	}
	pozicio(13, 20);      // kisebb akadalyok
	cout << "-------";
	pozicio(6, 61);
	cout << "------------";
	for (int i = 11; i <= 17; i++)
	{
		pozicio(i, 55);
		cout << "|";
	}

	pozicio(0, 34);
	cout << "  Power: Andariel-" << eero1;
	cout << "  duriel-" << eero2;
	cout << "  Baal-" << eero3;
	cout << "  Mephisto-" << eero4;
	cout << "  Diablo-" << eero5;

}

void jatekos::eltuntet(int d1, int d2)  // a megadott poziciot felulirja egy space-el
{
	pozicio(d1, d2);
	cout << " ";
}

void jatekos::kiir(int d1, int d2)  // kiirja a karaktert, es a hozza tartozo dolgokat
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

void jatekos::setcursor(bool visible, DWORD size)  // beallitja a kurzort (eltunteti)
{
	size = 20;
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void jatekos::pozicio(int sor, int oszlop)  // a megadott koordinatakra allitja a kurzort
{
	COORD c;
	c.Y = sor;
	c.X = oszlop;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void jatekos::lepes(char m, int &nr)    // az m karakter szerint lepteti a karaktert, nr-lepesek szama
{
	switch (m)
	{
	case 'w':
		eltuntet(d1, d2);            // eltunteti az aktualis poziciot
		d1 = d1 - 1;                 // csokkenti a sort, feljebb lepik
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
	nr++;                              // noveli a nr-t, a lepesek szamat  mutatja, az ellenseg lepkedesenel fontos
	if ((d1 == v1) && (d2 == v2))      // ellenorzi hogy a P-re lepett-e
	{
		ero = ero + 3;
		eltuntet(v1, v2);
		v1 = rand() % 24 + 2;
		v2 = rand() % 78 + 1;
	}
	if ((d1 == h1) && (d2 == h2))     // ellenorzi hogy a H-ra lepett-e
	{
		elet = elet + 5;
		eltuntet(h1, h2);
		h1 = rand() % 24 + 2;
		h2 = rand() % 78 + 1;
	}
	if (ellenoriz(d1, d2) == 0)     // ellenorzi hogy meg a palyan van-e. Ha igen akkor kiirja a karaktert, ha nem game over
		gameover();
	else
		kiir(d1, d2);

}

void jatekos::gameover()              // a gameover txt-bol beolvas egy matrixot, a nullasokat atalakitja space-re, majd pillogtatva kiirja
{									  // majd kiirja a vegso eredmenyeket
	char a[18][60];
	ifstream be("gameover.txt");
	for (int i = 0; i <= 14; i++)
		for (int j = 0; j <= 59; j++)
		{
			be >> a[i][j];
			if (a[i][j] == '0')
				a[i][j] = ' ';
		}
	for (int i = 1; i <= 3; i++)
	{
		system("cls");
		Sleep(600);
		for (int i = 0; i <= 14; i++)
		{
			for (int j = 0; j <= 59; j++)
				cout << a[i][j];
			cout << endl;
		}
		Sleep(900);
	}
	vegsokiir();
}

void jatekos::vegsokiir()         // befejezi az idomerest, kiirja a vegso pontokat, eletet stb...
{
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	system("cls");
	pozicio(5, 10);
	cout << "Points: " << o;
	pozicio(7, 10);
	cout << "Kills: " << olesek;
	pozicio(9, 10);
	cout << "Life: " << elet;
	pozicio(11, 10);
	cout << "Time: " << time_spent << " s";
	pozicio(13, 10);
	cout << "Congratulation " << nev << "!";
	Sleep(2000);
	exit(0);
}

void jatekos::elsokiir()    // kiirja a kezdo szoveget
{
	char folosleg;
	pozicio(0, 0);
	char a[18][64];
	ifstream be("cim.txt");
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 63; j++)
		{
			be >> a[i][j];
			if (a[i][j] == '0')
				a[i][j] = ' ';
			cout << a[i][j];
		}
		cout << endl;
	}

	cout << "\tYou are The Barbarian, a powerful melee fighter from the steppes of Mount Arreat." << endl;
	cout << "\tHe is an expert at frontline combat, able to absorb great punishment," << endl;
	cout << "\tand is the only class capable of dual wielding weapons." << endl;
	cout << "" << endl;
	cout << "\t\tYour enemies: " << endl;
	cout << "\tAndariel - The Maiden of Anguish - Twin sister of Duriel. Sent to guard the Rogue Monastery by Diablo himself." << endl;
	cout << "\tDuriel - The Lord of Pain - Though Duriel had his part in the Dark Exile. " << endl;
	cout << "\tBaal - The Lord of Destruction - The Most Destructive, Insidious and Ruthless of the Three. " << endl;
	cout << "\tMephisto - The Lord of Hatred - The Eldest of the Three, Leader of Prime Evils, Father of Lilith and Lucion." << endl;
	cout << "\tDiablo - The Lord of Terror - The Youngest of the Three, The Strongest Prime Evil and Father of Leah. " << endl;
	cout << endl;
	cout << "\tKill all of the enemies and win the game!" << endl << "\tMove on the 'P' for more power and 'H' for more health. Moove with WASD. Press q for Quit" << endl;

	cout << "Enter your name: ";
	cin.getline(nev, 29);
	cin.getline(nev, 29);  //ketszer kell bekeretni, mert az elsobe bekerul a level(1,2,3)
	
	cout << endl << "Press any key to start the game...";

	folosleg = _getch();     // any key
	system("cls");

	begin = clock();         // elkezdi az idomerest

}

