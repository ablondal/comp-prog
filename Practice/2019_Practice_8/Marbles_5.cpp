#include <iostream>
#include <vector>

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
	//xa0 = x1;
	//xb0 = y1;
	return r2;
}

long long gcd_simp ( long long a, long long b )
{
	if (b==0) return a;
	return gcd_simp (b, a%b);
}

int main(){
	int N;
	cin >> N;
	long long c1, n1, c2, n2;
	long long x1, x2, xa, xb, x1_, x2_;
	long long tmp1, tmp2, remain;
	long long gcd_ns, cost;
	int swap;
	while(N != 0)
	{
		cin >> c1 >> n1 >> c2 >> n2;
		swap = 0;
		

		if( n1/float(c1) < n2/float(c2) ){
			tmp1 = n1; 	tmp2 = c1;
			n1 = n2;	c1 = c2;
			n2 = tmp1;	c2 = tmp2;
			swap = 1;
		}
		// Now n1, c1, has the best ratio
		// Get gcd, and xa, xb, such that xa*n1 + xb*n2 = gcd(n1, n2)
		
		gcd_ns = gcd ( n1, n2, xa, xb );
		if( N % gcd_ns != 0 )
		{
			cout << "failed" << endl;
			cin >> N;
			continue;
		}

		// xa, xb, give possible values for x's. Now scale them up
		x1 = xa * (N / gcd_ns);
		x2 = xb * (N / gcd_ns);

		// Now replace as many x2s with x1s as possible

		x1_ = n2 / gcd_ns;
		x2_ = n1 / gcd_ns;
		// x1 * n1 = x2 * n2

		tmp1 = abs( x2 / x2_ ); // How many times we can replace x2s with x1s

		if( x1 < 0 )
		{
			//tmp1 = x2 / x2_; // How many times we can replace x2s with x1s
			x1 += tmp1 * x1_;
			x2 -= tmp1 * x2_;
		}
		else // x2 < 0
		{
			//tmp1 = abs( x2 / x2_ );
			x2 += (tmp1 + 1) * x2_; // get x2 positive
			x1 -= (tmp1 + 1) * x1_; // sad
		}

		// Now, x1 and x2 should be done.

		// cost = x1 * c1 + x2 * c2;
		if(swap)
		{
			cout << x2 << " " << x1 << endl;
		}
		else
		{
			cout << x1 << " " << x2 << endl;
		}
		

		cin >> N;
	}
}