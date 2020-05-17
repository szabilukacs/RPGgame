#ifndef ELLENSEG_H
#define ELLENSEG_H

#include"Jatekos.h"
#include <iostream>

using namespace std;

class ellenseg
{
private:
	int p1, p2, elete, eroe, elspeed;    // ellenseg pozicioi, elete, ereje, sebessege
	char s;								// ellenseg karaktere
	void pozicio(int, int);
	void eltuntet(int p1, int p2) { pozicio(p1, p2); cout << " "; }
	void kiir(int, int);
	void nagyellenoriz(jatekos &);      // ellenorzi a poziciokat 
public:
	ellenseg(char, int, int);
	void randlepes(int &, jatekos &);    // random leptetes
	int ellenorize(int, int);           // ellenseg poziciojanak ellenorzese
	friend class jatek;                 // hozzafer a jatekos allapotahoz, azt meg tudja valtoztatni

};

#endif // !ELLENSEG_H

