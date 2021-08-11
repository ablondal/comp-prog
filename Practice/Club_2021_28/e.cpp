#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5+7;

vector<ll> pos[maxn];
vector<ll> tim[maxn];

unordered_map<ll, int> ans;

inline ll getpos(ll i, ll t){
	int lo = 0, hi = tim[i].size();
	while(hi-lo>1){
		int md = (hi+lo)>>1;
		if (tim[i][md]<t) lo = md;
		else hi = md;
	}
	if (lo==tim[i].size()-1) return -1;
	return (pos[i][lo+1]-pos[i][lo] > 0 ? pos[i][lo]+(t-tim[i][lo]) : pos[i][lo] - (t-tim[i][lo]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i,1,n+1){
		int k;
		scanf("%d", &k);
		pos[i].resize(k);
		tim[i].resize(k+1, 0);
		rep(j,0,k){
			scanf("%lld", &pos[i][j]);
			if (j) tim[i][j] = tim[i][j-1]+abs(pos[i][j]-pos[i][j-1]);
		}
	}
	while(m--){
		int a, b;
		scanf("%d%d", &a, &b);
		if (a>b) swap(a,b);
		auto it = ans.find((ll)a*1e7 + (ll)b);
		if (it != ans.end()){
			printf("%d\n", it->second);
			continue;
		}
		int tot = 0;


		if (pos[b].size() < pos[a].size()) swap(a,b);

		ll la = pos[a][0];
		ll lb = pos[b][0];

		ll ca, cb;
		rep(i,1,pos[a].size()){
			ca = pos[a][i];
			cb = getpos(b, tim[a][i]);
			// cout << tim[a][i] << " " << ca << " " << cb << endl;
			if (cb == -1) break;
			if ( (la-lb)*(ca-cb) < 0 ) tot++;
			la = ca;
			lb = cb;
		}
		if (cb == -1){
			int i = pos[b].size()-1;
			cb = pos[b][i];
			ca = getpos(a,tim[b][i]);
			if ( (la-lb)*(ca-cb) < 0 ) tot++;
			la = ca;
			lb = cb;
		}

		if (a>b) swap(a,b);

		ans[(ll)a*1e7 + (ll)b] = tot;
		printf("%d\n", tot);
	}
}