#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll stones[107];
int siz[107];

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin >> t;
	vector<ll> ans;
	for(int cas = 1; cas<=t; ++cas){
		ll d;
		int n;
		cin >> n >> d;
		rep(i,1,n+1){
			char s;
			ll dis;
			scanf(" %c-%lld", &s, &dis);
			// cout << s << " " << dis << endl;
			stones[i] = dis;
			siz[i] = (s == 'S' ? 0 : 1);
		}
		stones[0] = 0;
		stones[n+1] = d;
		siz[0] = 1;
		siz[n+1] = 1;
		ll big = 0;
		rep(i,0,n+1){
			big = max(big, stones[i+1]-stones[i]);
		}
		rep(i,1,n+1){
			if (siz[i]==0){
				big = max(big, stones[i+1]-stones[i-1]);
			}
		}
		ans.push_back(big);
		// printf("Case %d: %lld\n", cas, big);
	}
	rep(a,1,t+1){
		printf("Case %d: %lld\n", a, ans[a-1]);
	}
	// printf("\n");
}
/*
3
1 10
B-5
1 10
S-5
2 10
B-3 S-6

*/