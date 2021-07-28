#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 2e5+7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;

	vi perm(n);
	vi invp(n);
	vi last(n, -1);

	vi seq(m);
	vi start(m);
	vi next(m, -1);

	rep(i,0,n){
		int pi;
		cin >> pi;
		pi--;
		perm[i] = pi;
		invp[pi] = i;
	}
	
	rep(i,0,m){
		cin >> seq[i];
		seq[i]--;
		seq[i] = invp[seq[i]];

		last[seq[i]] = i;

		prevn = (seq[i] + n-1)%n;
		if (last[prevn] != -1){
			int b4 = last[prevn];
			if (next(b4))
		}

	}

	rep(i,0,q){
		int l, r;
		cin >> l >> r;
		if (lower_bound(all(poss), l-1) != upper_bound(all(poss), r-1)){
			cout << "1";
		}else{
			cout << "0";
		}
	}
	cout << endl;
}