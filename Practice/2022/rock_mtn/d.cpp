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

double ttw[107];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int dl, dw;
	double g, l;
	cin >> dl >> dw >> g >> l;
	g /= 100;
	l /= 100;
	ttw[100] = 1.0 / (1-l);
	for(int i=99; i>=0; i--){
		ttw[i] = 1
			+ (l * ttw[min(100, i+dl)])
			+ (1-l)*( (1-(i/100.0)) * ttw[min(100, i+dw)]);
	}
	// cout << ttw[0] << endl;
	cout << setprecision(16) << ttw[0] / g << endl;
}