#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
// const ld EPS = 1e-9;

int n;
ld m;

int a[1001], sa[1001], b[1001], sb[1001];

bool canwork(ld fuel){
	for(int i=0; i<n; ++i){
		fuel = fuel - ((m+fuel) / a[i]);
		fuel = fuel - ((m+fuel) / b[i+1]);
		if (fuel < 0) return false;
	}
	return true;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		cin >> a[i];
		if (a[i] < 2){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i=0; i<n; ++i){
		cin >> b[i];
		if (b[i] < 2){
			cout << -1 << endl;
			return 0;
		}
	}
	b[n] = b[0];

	ld fuel = 0;
	for(int i=n-1; i>=0; --i){
		fuel = ( fuel + ((ld)m/b[i+1]) ) / ((ld)1.0 - ((ld)1.0/b[i+1]));
		fuel = ( fuel + ((ld)m/a[i]) ) / ((ld)1.0 - ((ld)1.0/a[i]));
		if (fuel > 2e9){
			cout << -1 << endl;
			return 0;
		}
	}

	ld min = fuel - 10;
	ld max = fuel;
	ld mid;
	while(max-min > 1e-7){
		mid = max/2.0 + min/2.0;
		if (canwork(mid)){
			max = mid;
		}else{
			min = mid;
		}
	}
	cout << std::setprecision(18) << max << endl;
}


















