#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int top[507], bot[507];

int mi[507];

int t[507][507];

ll tot[250007] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	rep(i,0,n*m){
		scanf("%d%d", &a, &b);
		t[a][b] = i;
	}

	rep(i,1,n+1) {
		rep(k,1,m+1) mi[k] = 1e9;
		rep(j,i,n+1) {
			vector<pair<int, int>> p;
			top[0] = 700;
			bot[m+1] = -1;
			rep(k,1,m+1){
				top[k] = 700;
				bot[k] = -1;
				mi[k] = min(mi[k], t[j][k]);
				p.push_back({mi[k], k});
			}
			sort(all(p));
			for(int pp = m-1; pp>=0; pp--){
				int& pos = p[pp].second;
				int& tim = p[pp].first;
				top[pos] = min(pos, top[pos-1]);
				bot[pos] = max(pos, bot[pos+1]);
				top[bot[pos]] = top[pos];
				bot[top[pos]] = bot[pos];

				tot[tim] += (pos-top[pos]+1) * (bot[pos]-pos+1);
				// printf("%d %d %d: %d %d\n", i, j, pos, top[pos], bot[pos]);
				// cout << (pos-top[pos]+1) * (bot[pos]-pos+1) << endl;
			}
		}
	}
	for(int i=n*m-1; i>=0; --i){
		tot[i] += tot[i+1];
	}
	rep(i,1,n*m+1){
		cout << tot[i] << endl;
	}

}