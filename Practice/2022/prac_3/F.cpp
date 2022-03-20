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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<ll> w(n);
	vector<pair<int, int>> fm(m);
	rep(i,0,n) cin >> w[i];
	rep(i,0,m) cin >> fm[i].second >> fm[i].first;
	sort(all(w));
	sort(all(fm));
	int i = sz(w)-1;
	int j = sz(fm)-1;
	ll tot = 0;
	while(i>=0 && j>=0){
		while(i>=0 && fm[j].second>0){
			tot += fm[j].first * w[i];
			fm[j].second--;
			i--;
		}
		j--;
	}
	cout << tot << endl;

}