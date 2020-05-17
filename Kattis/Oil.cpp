//  International Collegiate Programming Contest (ACM-ICPC) World Finals 2016
/*
A large part of the world economy depends on oil,
which is why research into new methods for finding
and extracting oil is still active. Profits of oil
companies depend in part on how efficiently they can
drill for oil. The International Crude Petroleum
Consortium (ICPC) hopes that extensive computer
simulations will make it easier to determine how to
drill oil wells in the best possible way.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define pi acos(-1.0)
#define EPS 1e-9

// See Oil2 for working solution

int gcd(int a, int b){
	if (b==0) return a;
	return gcd(b, a%b);
}

struct _pt{
	int x;
	int y;
};
typedef struct _pt pt;
typedef long double ld;

struct _frac{
	int t;
	int b;
	bool neg = 0;
};
typedef struct _frac frac;

bool operator<(frac &a, frac &b){
	if (a.neg && !b.neg) return true;
	if (b.neg && !a.neg) return false;
	if (a.neg){
		return (a.t*b.b < a.b*b.t);
	}else{
		return (a.t*b.b >= a.b*b.t);
	}
}

bool operator==(frac &a, frac &b){
	if (a.t*b.b == a.b*b.t && a.neg == b.neg) return true;
	return false;
}

frac get_frac(pt a, pt b){
	// Get fraction of line from a to b
	int x = b.x-a.x;
	int y = b.y-a.y;
	frac f;
	if (x<0 && y!=0) f.neg = !f.neg;
	if (y<0 && x!=0) f.neg = !f.neg;
	x = abs(x);
	y = abs(y);
	int g = gcd(x,y);
	if ( g != 0 ){
		x /= g;
		y /= g;
	}
	f.t = y;
	f.b = x;

	return f;
}

int main(){
	int n;
	cin >> n;
	vector <pt> pts(2*n);
	// vector <pt> en(n);
	vector <int> val(n);
	int a,b,c;
	int topsoil = 0;
	for(int i=0; i<n; ++i){
		cin >> a >> b >> c;
		pts[2*i].x = a;
		pts[2*i+1].x = b;
		pts[2*i].y = pts[2*i+1].y = c;
		val[i] = max(a-b,b-a);
		if (c==0){
			topsoil += val[i];
		}
	}
	vector <frac> ang(2*n);
	vector <int> order(2*n);
	for(int i=0 ;i < 2*n; ++i){
		order[i] = i;
	}
	int maxval = max( val[0], topsoil );
	vector <bool> I(n,false);
	for(int i=0; i<2*n; ++i){
		for(int k=0; k<2*n; ++k){
			ang[k] = get_frac(pts[i],pts[k]);
		}
		sort( order.begin(), order.end(), [&ang](int a, int b){return ang[a]<ang[b];} );
		cout << pts[i].x << ", " << pts[i].y << endl;
		cout << "sorted:" << endl;
		for(int k=0; k<order.size(); ++k){
			cout << pts[order[k]].x << ", " << pts[order[k]].y << endl;
		}
		int curval = val[i/2];
		I.clear();
		I.resize(n,false);
		I[i/2] = true;

		for(int j=0; j<2*n; ++j){
			if (pts[order[j]].y == pts[i].y) continue;
			b = j+1;
			while( ang[order[b]] == ang[order[j]] && b<2*n ) b++;

			for(a=j;a<b;++a){
				c = order[a];
				if (!I[c/2]){
					curval += val[c/2];
				}
			}
			
			maxval = max(maxval, curval);

			for(a=j;a<b;++a){
				c = order[a];
				if (I[c/2]){
					curval -= val[c/2];
					I[c/2] = false;
				}else{
					I[c/2] = true;
				}
			}
			// if (curval == maxval){
			// 	cout << curval << endl;
			// 	cout << pts[i].x << ", " << pts[i].y << endl;
			// 	cout << pts[order[j]].x << ", " << pts[order[j]].y << endl << endl;
			// }
			j = b-1;
		}
	}
	cout << maxval << endl;
}













