#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;


ll choose(int r, int k){
	ll res = 1;
	k = min(k,r-k);
	for(int i=1; i<=k; ++i){
		res *= r - (i-1);
		res /= i;
	}
	return res;
}

void solve(int t){
	int n;
	cin >> n;

	int m = n-30;
	if (m<0) m = 0;

	bool side = 0;
	int r = 1;

	cout << "Case #" << t << ":"<< endl;

	while(n>0){
		if (m%2){
			if (side){
				for(int k=r; k>=1; k--){
					cout << r << " " << k << endl;
				}
			}else{
				for(int k=1; k<=r; k++){
					cout << r << " " << k << endl;
				}
			}
			side = !side;
			n -= (1 << (r-1));
		}else{
			if (side){
				cout << r << " " << r << endl;
			}else{
				cout << r << " " << 1 << endl;
			}
			n -= 1;
		}

		m = m >> 1;
		r++;
	}
	
}


int main(){
	int T;
	cin >> T;
	for(int t=1;t<=T;++t){
		//cout << "Case #" << t << ": ";
		solve(t);
	}
	return 0;
}



















