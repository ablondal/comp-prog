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
	set<string> s;
	int t;
	cin >> t;
	while(t--){
		s.clear();
		int n;
		cin >> n;
		rep(i,0,n){
			string t;
			cin >> t;
			s.insert(t);
		}
		cout << sz(s) << endl;
	}
}