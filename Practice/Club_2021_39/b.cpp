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
	int n;
	cin >> n;
	vector<int> t(43207, 0);
	rep(i,0,n){
		int di, ti;
		cin >> di >> ti;
		t[ti]++;
		t[ti-di]++;
		t[ti-di-di]++;
	}
	int M = 0;
	rep(i,0,43207){
		M = max(M, t[i]);
	}
	cout << (M+1) /2 << endl;
}