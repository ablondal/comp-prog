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
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		
		set<int> unused;
		rep(i,1,n+1) unused.insert(i);
		vi perm(n, -1);

		int len = r-l+1;
		int m = 0, M=0;
		rep(i,1,len+1){
			m += i;
			M += (n-len+i);
		}
		if (s < m || s > M){
			cout << -1 << endl;
			continue;
		}else{
			vi nums;
			int nn = n;
			for(int i=len; i>0; --i){
				while(s <= M-i){
					M -= i;
					nn--;
				}
				nums.push_back(nn);
				unused.erase(nn);
				M -= nn;
				s -= nn;
				nn--;
			}
			rep(i,0,n){
				if (l-1<=i && i<=r-1){
					cout << nums[i-l+1] << " ";
				}else{
					cout << *unused.begin() << " ";
					unused.erase(unused.begin());
				}
			}
			cout << endl;
		}

	}
}