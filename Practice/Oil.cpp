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

struct _pt{
	int x;
	int y;
};
typedef struct _pt pt;

double get_ang(pt a, pt b){
	// Get angle of line from a to b, compared to the line (1,0)
	int x = b.x-a.x;
	int y = b.y-a.y;
	if (y==0) return 0;
	if (x==0) return pi/2;
	double r = atan( (double)y/(double)x );
	if (r<0) r += pi;
	return r;
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
	vector <double> ang(2*n);
	vector <double> order(2*n);
	for(int i=0 ;i < 2*n; ++i){
		order[i] = i;
	}
	int maxval = max( val[0], topsoil );
	vector <bool> I(n,false);
	for(int i=0; i<2*n; ++i){
		for(int k=0; k<2*n; ++k){
			ang[k] = get_ang(pts[i],pts[k]);
		}
		sort( order.begin(), order.end(), [&ang](int a, int b){
			int d1, d2, n1, n2;
			return pts[a].x;
		} );
		// cout << pts[i].x << ", " << pts[i].y << endl;
		// cout << "sorted:" << endl;
		// for(int k=0; k<order.size(); ++k){
		// 	cout << pts[order[k]].x << ", " << pts[order[k]].y << endl;
		// }
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













