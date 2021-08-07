#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

struct edge{
	ll a,b,c;
	edge(ll a,ll b, ll c):a(a),b(b),c(c){}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vi val(n+1);
	vi fund(n+1,0);
	vector<edge> ved;
	rep(i,0,m){
		ll a,b,c;
		cin >> a >> b >> c;
		ved.emplace_back(a,b,c);
	}
	rep(i,0,n){
		cin >> val[i+1];
	}
	for(auto e : ved){
		if (val[e.a] > val[e.b]){
			fund[e.a]+=e.c;
			fund[e.b]-=e.c;
		}else if (val[e.a] < val[e.b]){
			fund[e.a]-=e.c;
			fund[e.b]+=e.c;
		}else if (val[e.a] == val[e.b]){
			if (e.a < e.b){
				fund[e.a]+=e.c;
				fund[e.b]-=e.c;
			}else{
				fund[e.a]-=e.c;
				fund[e.b]+=e.c;
			}
		}
	}
	ll tot = 0;
	rep(i,1,n+1){
		tot += val[i]*fund[i];
	}
	printf("%lld\n",tot);
	rep(i,1,n+1){
		if (i!=1) printf(" ");
		printf("%lld", fund[i]);
	}
	printf("\n");
}