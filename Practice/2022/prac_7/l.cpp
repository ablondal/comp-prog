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
const int MAXN = 1e5+7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	double k;
	cin >> n >> m >> k;
	vector<pair<double, double>> TP(m);
	rep(i,0,m){
		cin >> TP[i].first >> TP[i].second;
	}
	double a = 0;
	double b;
	int c;
	rep(i,0,n){
		b = 1e31;
		rep(j,0,m){
			auto& [ti, pi] = TP[j];
			double t = (a+ti + pi*k)/(1-pi);
			// cout << j << " " << t << endl;
			b = min(b, t);

		}
		a = b;
		// cout << b << endl;
	}
	cout << setprecision(20) << a << endl;
}