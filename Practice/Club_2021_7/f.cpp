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
	int n, m, p;
	cin >> n >> m >> p;
	vi d(n);
	rep(i,1,n) cin >> d[i];
	d[0] = 0;
	rep(i,1,n) d[i] += d[i-1];
	vi h(n), t(n);
	rep(i,0,n){
		cin >> h[i] >> t[i];
		t[i] -= d[h[i]];
	}
	sort(all(t[i]));
	int ii = 0;
	vi ncats;
	while(ii < sz(t)){
		int jj = ii;
		while(jj < sz(t) && t[jj] == t[ii]) jj++;
		ncats.push_back(jj);
	}

	

}