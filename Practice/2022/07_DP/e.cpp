#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;
const int NX = 1e5+7;
const long double PI = acos((long double)-1.0);

long double ang[2*NX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a;
	rep(i,0,n){
		a.push_back(i);
		long double x, y;
		cin >> x >> y;
		ang[i] = atan2(y,x);
	}
	// a.push_back(n);
	sort(all(a), [](int a, int b){return ang[a]<ang[b];});
	// rep(i,0,n){
	// 	cout << a[i] << " " << setprecision(20) << ang[a[i]] << endl;
	// }
	long double m = 100;
	int b,c;
	rep(i,0,n){
		if (i) {if ( ang[a[i]] - ang[a[i-1]] < m ){
			m = ang[a[i]] - ang[a[i-1]];
			b = a[i], c = a[i-1];
		}} else {
			m = ang[a[i]] - ang[a[n-1]] + 2*PI;
			// cout << m << endl;
			b = a[0], c = a[n-1];
		}
	}
	cout << (b % n)+1 << " " << (c % n)+1 << endl;
}