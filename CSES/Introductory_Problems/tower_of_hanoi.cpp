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

vector<pii> mvs;

void mv(int from, int to, int h){
	if (h == 1) {
		mvs.push_back({from, to});
	} else {
		int other = (from^to);
		mv(from, other, h-1);
		mvs.push_back({from, to});
		mv(other, to, h-1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	mv(1, 3, n);
	cout << sz(mvs) << endl;
	for(auto [a, b] : mvs){
		cout << a << " " << b << endl;
	}
}