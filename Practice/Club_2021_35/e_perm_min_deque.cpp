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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi p(n);
		vi sm;
		rep(i,0,n){
			cin >> p[i];
			if (sz(sm)==0 || p[i] < p[sm.back()]){
				sm.push_back(i);
			}
		}
		reverse(all(sm));
		vi ans;
		for(auto s : sm){
			ans.push_back(p[s]);
			p[s] = 0;
		}
		for(auto pp : p){
			if (pp!=0) ans.push_back(pp);
		}
		for(auto a : ans){
			cout << a << " ";
		}
		cout << endl;

	}
}