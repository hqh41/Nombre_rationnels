#include "Rational.h"
#include <assert.h>
#include <iostream>
using namespace std;

Rat::Rat(int x, int y):num_(x/pgcd(x, y)), den_(y/pgcd(x, y)){
	if(x == 0){num_ = 0; den_ = 1;}
	assert(y > 0);
}

int Rat::get_num() const {return num_;}
int Rat::get_den() const {return den_;}

void Rat::set_num(int x){num_ = x/pgcd(x, this->den_);}
void Rat::set_den(int x){den_ = x/pgcd(this->num_, x);}

void Rat::set(int x, int y){num_ = x/pgcd(x, y); den_ = y/pgcd(x, y);}

Rat& Rat::operator+= (const Rat &x){
	int num = get_num() * x.get_den() + get_den() * x.get_num();
	int den = get_den() * x.get_num();
	int p = pgcd(num, den);
	num = num/p;
	den = den/p;
	set(num, den);
	return *this;
}

Rat& Rat::operator-= (const Rat &x){
	int num = get_num() * x.get_den() - get_den() * x.get_num();
	int den = get_den() * x.get_num();
	int p = pgcd(num, den);
	num = num/p;
	den = den/p;
	set(num, den);
	return *this;
}

Rat& Rat::operator*= (const Rat &x){
	int num = get_num() * x.get_num();
	int den = get_den() * x.get_den();
	int p = pgcd(num, den);
	num = num/p;
	den = den/p;
	set(num, den);
	return *this;
}

Rat& Rat::operator/= (const Rat &x){
	cout << get_num() << " " << x.get_den() << " " << get_num() * x.get_den() << endl;
	cout << get_den() << " " << x.get_num() << " " << get_den() * x.get_num() << endl;
	int num = get_num() * x.get_den();
	int den = get_den() * x.get_num();
	int p = pgcd(num, den);
	num = num/p;
	den = den/p;
	set(num, den);
	return *this;
}

Rat operator+ (const Rat &x, const Rat &y){
	int num = y.get_den() * x.get_num() + x.get_den() * y.get_num();
	int den = x.get_den() * y.get_den();
	int p = pgcd(num, den);
	num = num/p;
	den = den/p;
	return Rat(num, den);
}

Rat operator- (const Rat &x, const Rat &y){
	int num = y.get_den() * x.get_num() - x.get_den() * y.get_num();
	int den = x.get_den() * y.get_den();
	int p = pgcd(num, den);
	num = num/p;
	den = den/p;
	return Rat(num, den);
}

Rat operator* (const Rat &x, const Rat &y){
	int num = y.get_num() * x.get_num();
	int den = x.get_den() * y.get_den();
	int p = pgcd(num, den);
	num = num/p;
	den = den/p;
	return Rat(num, den);
}

Rat operator/ (const Rat &x, const Rat &y){
	int num = x.get_num() * y.get_den();
	int den = x.get_den() * y.get_num();
	int p = pgcd(num, den);
	num = num/p;
	den = den/p;
	return Rat(num, den);
}

bool operator== (const Rat &x,const Rat &y){
	int num1 = x.get_num() / pgcd(x.get_num(), x.get_den());
	int den1 = x.get_den() / pgcd(x.get_num(), x.get_den());
	int num2 = y.get_num() / pgcd(y.get_num(), y.get_den());
	int den2 = y.get_den() / pgcd(y.get_num(), y.get_den());
	if(num1 == num2 && den1 == den2)
		return true;
	else
		return false;
}

bool operator!= (const Rat &x,const Rat &y){
	int num1 = x.get_num() / pgcd(x.get_num(), x.get_den());
	int den1 = x.get_den() / pgcd(x.get_num(), x.get_den());
	int num2 = y.get_num() / pgcd(y.get_num(), y.get_den());
	int den2 = y.get_den() / pgcd(y.get_num(), y.get_den());
	if(num1 == num2 && den1 == den2)
		return false;
	else
		return true;
}

bool operator < (const Rat &x, const Rat &y){
	if(x.get_num() * y.get_den() < x.get_den() * y.get_num())
		return true;
	else
		return false;
}

bool operator <= (const Rat &x, const Rat &y){
	if(x.get_num() * y.get_den() <= x.get_den() * y.get_num())
		return true;
	else
		return false;
}

bool operator > (const Rat &x, const Rat &y){
	if(x.get_num() * y.get_den() > x.get_den() * y.get_num())
		return true;
	else
		return false;
}

bool operator >= (const Rat &x, const Rat &y){
	if(x.get_num() * y.get_den() >= x.get_den() * y.get_num())
		return true;
	else
		return false;
}

int pgcd(int x, int y){
		while(x != y){
			if(x > y)
				x = x - y;
			else
				y = y - x;
		}
		return x;
	}
