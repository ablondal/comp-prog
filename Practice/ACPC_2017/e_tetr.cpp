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

int c[1000007] = {0};
int cc[1000007] = {0};
vi dbs;

int choosecard(int& i, vi& omeg){
	while(i < sz(omeg) && cc[omeg[i]]){
		i++;
	}
	cc[omeg[i]] = 1;
	int card = omeg[i] / 2;
	c[card]++;
	if (c[card] == 2) {
		dbs.push_back(card);
	}
	return card;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double N;
	cin >> N;
	double lo = 0, hi = 4;
	while(hi-lo > 1e-8){
		double md = (hi+lo)/2;
		double aN = pow(md,N);
		if (aN > N) {
			hi = md;
		} else {
			lo = md;
		}
	}
	cout << setprecision(12) << lo << endl;

}