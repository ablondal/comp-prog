#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5+7;

struct node{
	struct node* D[2] = {nullptr, nullptr};
	// struct node* L = (nullptr);
	// struct node* R = (nullptr);
	char val = 0;
	bool inv[2] = {0, 0};
	// bool Linv = 0, Rinv = 0;
};

node nds[MX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, r;
	cin >> n >> l >> r;
	rep(i,0,n){
		cin >> nds[i].val;
		if (i) nds[i].D[0] = &nds[i-1];
		if (i!=n-1) nds[i].D[1] = &nds[i+1];
	}
	int m;
	cin >> m;
	node* lptr = &nds[l-1];
	node* rptr = &nds[r-1];
	bool linv = 0;
	bool rinv = 0;
	string ans;
	rep(mm, 0, m){
		char q;
		cin >> q;
		if (q == 'S') {
			char X, Y;
			cin >> X >> Y;
			if (X == 'L') {
				bool dir = ((Y=='L') ^ linv) ? 0 : 1;
				linv ^= lptr->inv[dir];
				lptr = lptr->D[dir];
			} else {
				bool dir = ((Y=='L') ^ rinv) ? 0 : 1;
				rinv ^= rptr->inv[dir];
				rptr = rptr->D[dir];
			}
		} else if (q == 'R') {
			bool rdir = (rinv == 0) ? 1 : 0;
			bool ldir = (linv == 0) ? 0 : 1;

			rptr->inv[rdir] ^= 1;
			lptr->inv[ldir] ^= 1;
			rptr->D[rdir]->inv[rdir^rptr->inv[rdir]] ^= 1;
			lptr->D[ldir]->inv[ldir^lptr->inv[ldir]] ^= 1;

			auto tmp = rptr->D[rdir];
			rptr->D[rdir] = lptr->D[ldir];
			lptr->D[ldir] = rptr->D[rdir];

			rptr->D[rdir]->D[rdir^rptr->inv[rdir]] = rptr;
			lptr->D[ldir]->D[ldir^lptr->inv[ldir]] = lptr;

			rinv ^= 1;
			linv ^= 1;

			auto tmp1 = linv;
			linv = rinv;
			rinv = tmp1;

			auto tmp2 = rptr;
			rptr = lptr;
			lptr = tmp2;

		} else if (q == 'Q') {
			char X;
			cin >> X;
			if (X == 'L'){
				ans.push_back(lptr->val);
			} else {
				ans.push_back(rptr->val);
			}
			cout << ans.back() << endl;
		}
	}
	cout << ans << endl;
}