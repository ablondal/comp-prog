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
	l--;r--;
	__gnu_cxx::rope <char> rp;
	rep(i,0,n){
		char tmp;
		cin >> tmp;
		rp.push_back(tmp);
		// cin >> nds[i].val;
		// if (i) nds[i].D[0] = &nds[i-1];
		// if (i!=n-1) nds[i].D[1] = &nds[i+1];
	}
	int m;
	cin >> m;
	string ans;
	rep(mm, 0, m){
		char q;
		cin >> q;
		if (q == 'S') {
			char X, Y;
			cin >> X >> Y;
			if (X == 'L') {
				if (Y == 'R') l++;
				else l--;
			} else {
				if (Y == 'R') r++;
				else r--;
			}
		} else if (q == 'R') {
			auto bef = rp.substr(0,l);
			auto aft = rp.substr(r+1,n-r);
			auto mid = rp.substr(l, r-l+1);
			reverse(all(mid));
		} else if (q == 'Q') {
			char X;
			cin >> X;
			if (X == 'L'){
				ans.push_back(rp[l]);
			} else {
				ans.push_back(rp[r]);
			}
			cout << ans.back() << endl;
		}
	}
	cout << ans << endl;
}