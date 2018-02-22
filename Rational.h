#ifndef RAT_H
#define RAT_H

class Rat{
private:
	int num_;//numerateur
	int den_;//denumerateur
public:
	Rat(int x, int y);

	int get_num() const;
	int get_den() const;

	void set_num(int x);
	void set_den(int x);

	void set(int x, int y);
	Rat& operator+= (const Rat &x);
	Rat& operator-= (const Rat &x);
	Rat& operator*= (const Rat &x);
	Rat& operator/= (const Rat &x);
};
	Rat operator+ (const Rat &x, const Rat &y);
	Rat operator- (const Rat &x, const Rat &y);
	Rat operator* (const Rat &x, const Rat &y);
	Rat operator/ (const Rat &x, const Rat &y);

	bool operator== (const Rat &x,const Rat &y);
	bool operator!= (const Rat &x,const Rat &y);

	bool operator < (const Rat &x, const Rat &y);
	bool operator <= (const Rat &x, const Rat &y);
	bool operator > (const Rat &x, const Rat &y);
	bool operator >= (const Rat &x, const Rat &y);
	//le plus grand commun diviseur
	int pgcd(int x, int y);

#endif
