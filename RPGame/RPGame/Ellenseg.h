#ifndef ELLENSEG_H
#define ELLENSEG_H

#include"Jatekos.h"
#include <iostream>

using namespace std;

class ellenseg
{
private:
	int p1, p2, elete, eroe, elspeed;
	char s;
	void pozicio(int, int);
	void eltuntet(int p1, int p2) { pozicio(p1, p2); cout << " "; }
	void kiir(int, int);
	void nagyellenoriz(jatekos &);
public:
	ellenseg(char, int, int);
	void randlepes(int &, jatekos &);
	int ellenorize(int, int);
	friend class jatek;

};

#endif // !ELLENSEG_H

