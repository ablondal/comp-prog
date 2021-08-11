#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	unordered_set<string> pol;
	cin >> n >> m;
	rep(i,0,n){
		string s;
		cin >> s;
		pol.insert(s);
	}
	int p = 0;
	rep(i,0,m){
		string t;
		cin >> t;
		if (pol.count(t)){
			p++;
		}
	}
	n += (p%2);
	if (n>m) cout << "YES";
	else cout << "NO";
	cout << endl;
}