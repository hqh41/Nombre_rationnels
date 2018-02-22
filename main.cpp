#include "Rational.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
	//cout<< "please enter 2 numbers" << endl;
	//int v1, v2;
	//cin >> v1;
	//cin >> v2;
	//constructeur et pgcd
	//Rat r1 = Rat(v1, v2);
	//cout << r.get_num() << r.get_den() << endl;

	//operator+-*/=
	//Rat r2 = Rat(2, 4);
	//r1 /= r2;
	//cout << r1.get_num() << r1.get_den() << endl;

	//operator +-*/
	Rat r3 = Rat(3, 7);
	Rat r4 = Rat(9, 14);
	//Rat r5 = r3 / r4;
	//cout << r5.get_num() << " " << r5.get_den() << " " << endl;

	//== !=
	//cout << (r3 == r4) << endl;
	//cout << (r3 != r4) << endl;

	//< <= > <=
	cout << (r3 < r4) << endl;
	cout << (r3 > r4) << endl;
}
