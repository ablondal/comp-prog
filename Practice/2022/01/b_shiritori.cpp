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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<string> S;
	string a, b;
	int n;
	cin >> n;
	bool w = true;
	rep(i,0,n){
		cin >> a;
		if (!b.empty() && b.back() != a[0]) w = false;
		if (S.count(a)) w = false;
		S.insert(a);
		b = a;
	}
	cout << (w ? "Yes" : "No") << endl;
}