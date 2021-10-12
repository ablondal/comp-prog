#include <bits/stdc++.h>
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
	struct node* L = (nullptr);
	struct node* R = (nullptr);
	char val = 0;
	bool Linv = 0, Rinv = 0;
};

node nds[MX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, r;
	cin >> n >> l >> r;
	rep(i,0,n){
		cin >> nds[i].val;
		if (i) nds[i].L = &nds[i-1];
		if (i!=n-1) nds[i].R = &nds[i+1];
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
				bool direction = ((Y=='L') ^ linv) ? 0 : 1;
				if (direction == 0) {
					// left ptr
					linv ^= lptr->Linv;
					lptr = lptr->L;
				} else {
					linv ^= lptr->Rinv;
					lptr = lptr->R;
				}
			} else {
				bool direction = ((Y=='L') ^ rinv) ? 0 : 1;
				if (direction == 0) {
					// left ptr
					rinv ^= rptr->Linv;
					rptr = rptr->L;
				} else {
					rinv ^= rptr->Rinv;
					rptr = rptr->R;
				}
			}
		} else if (q == 'R') {
			if (rinv == 0 && linv == 0) {
				rptr->Rinv ^= 1;
				lptr->Linv ^= 1;
				rptr->R->Linv ^= 1;
				lptr->L->Rinv ^= 1;

				auto tmp = rptr->R;
				rptr->R = lptr->L;
				lptr->L = tmp;

				rptr->R->L = rptr;
				lptr->L->R = lptr;
			} else if (rinv == 1 && linv == 0) {
				rptr->Linv ^= 1;
				lptr->Linv ^= 1;
				rptr->L->Rinv ^= 1;
				lptr->L->Rinv ^= 1;

				auto tmp = rptr->L;
				rptr->L = lptr->L;
				lptr->L = tmp;

				rptr->L->R = rptr;
				lptr->L->R = lptr;
			} else if (rinv == 0 && linv == 1) {
				rptr->Rinv ^= 1;
				lptr->Rinv ^= 1;
				rptr->R->Linv ^= 1;
				lptr->R->Linv ^= 1;

				auto tmp = rptr->R;
				rptr->R = lptr->R;
				lptr->R = tmp;

				rptr->R->L = rptr;
				lptr->R->L = lptr;
			} else if (rinv == 1 && linv == 1) {
				rptr->Linv ^= 1;
				lptr->Rinv ^= 1;
				rptr->L->Rinv ^= 1;
				lptr->R->Linv ^= 1;

				auto tmp = rptr->L;
				rptr->L = lptr->R;
				lptr->R = tmp;

				rptr->L->R = rptr;
				lptr->R->L = lptr;
			}
			rinv ^= 1;
			linv ^= 1;
			auto tmp = rptr;
			rptr = lptr;
			lptr = tmp;
			auto tmp2 = linv;
			linv = rinv;
			rinv = tmp2;
		} else if (q == 'Q') {
			char X;
			cin >> X;
			if (X == 'L'){
				ans.push_back(lptr->val);
			} else {
				ans.push_back(rptr->val);
			}
			// cout << ans.back() << endl;
		}
	}
	cout << ans << endl;
}