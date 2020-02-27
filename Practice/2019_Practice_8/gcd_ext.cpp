#include <iostream>

using namespace std;

long long gcd ( long long a, long long b, long long &xa, long long &xb ){
	long long r, r1, r2, x, x1, x2, y, y1, y2, q;
	r2 = a;
	r1 = b;
	x2 = 1;
	x1 = 0;
	y2 = 0;
	y1 = 1;
	while(r1 != 0){
		q = r2 / r1;
		r = r2 % r1;
		y = y2 - q * y1;
		x = x2 - q * x1;

		r2 = r1; r1 = r;
		x2 = x1; x1 = x;
		y2 = y1; y1 = y;
	}
	xa = x2;
	xb = y2;
	return r2;
}

int main()
{
	long long a, b, xa, xb, GCD;

	GCD = gcd ( 98, 101, xa, xb );
	cout << xa << " * 98 + " << xb << " * 101 = " << GCD << endl; 
}