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

ll DP[107][100007] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		n+=2;
		vi a(n);
		rep(i,0,n){
			cin >> a[i];
		}
		sort(all(a));
		ll s = 0;
		rep(i,0,n-2){
			s += a[i];
		}
		if (a[n-2] == s){
			a.pop_back();
			a.pop_back();
		} else {
			s += a[n-2];
			// cout << s-a[n-1] << endl;
			if (s-a[n-1] <= 0){
				a.clear();
			}else{
				int i=-1;
				rep(j,0,n-1){
					if (a[j] == s-a[n-1]){
						i = j;
						break;
					}
				}
				if (i==-1){
					a.clear();
				}else{
					a.erase(a.begin()+i);
					a.pop_back();
				}
			}
		}
		if (a.empty()){
			cout << -1 << endl;
		}else{
			for(auto e : a){
				cout << e << " ";
			}
			cout << endl;
		}
	}
}