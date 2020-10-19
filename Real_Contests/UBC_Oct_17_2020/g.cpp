#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1 << 15;
const ll INF = (ll)1e17;

ll DP[MAXN];
vi spd;
int n;

int sm(int a){
	rep(i,0,MAXN) if(a & (1<<i)) return i;
	return -1;
}

ll getDP(ll i){
	if (DP[i]!=INF) return DP[i];
	rep(a,0,n){
		if((1<<a)&i){
			rep(b,0,a){
				if((1<<b)&i){
					ll ii = i ^ ((1<<a) | (1<<b));
					if (ii==0) DP[i] = min(DP[i], 0LL+max(spd[a], spd[b]));
					int smm = sm(~ii);
					DP[i] = min(
						getDP(ii^(1<<smm))+max(spd[a],spd[b])+spd[smm],
						DP[i]);
				}
			}
		}
	}
	return DP[i];
}

int main() {
	rep(i,0,MAXN) DP[i] = INF;
	scanf("%d", &n);
	rep(i,0,n){
		int s;
		scanf("%d", &s);
		spd.push_back(s);
	}
	sort(all(spd));
	rep(i,0,sz(spd)){
		DP[(1<<i)] = spd[i];
	}
	DP[0] = 0;
	printf("%lli\n", getDP((1<<n)-1));
}

























