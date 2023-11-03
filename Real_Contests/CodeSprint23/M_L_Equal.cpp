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

bool q1(ll a, ll b){
	int yn = 0, nn = 0;
	while(max(yn, nn) < 3 || (yn == 2 && nn == 0) || (nn==2 && yn==0)){
		cout << 1 << " " << a << " " << b << endl;
		string s;
		cin >> s;
		if (s[0] == 'Y') {
			yn++;
		} else {
			nn++;
		}
	}
	return (yn > nn ? 1 : 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll hi = 1e18;
	// ll hi = 20;
	ll lo = 0;
	while(hi - lo > 1){
		ll md = (hi + lo) / 2;
		if (q1(md, hi-1)) {
			hi = md;
		} else {
			lo = md;
		}
	}
	cout << "2 " << lo << endl;
	string a;
	cin >> a;
	cout << "! " << a << endl;



}