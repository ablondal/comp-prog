#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, int> DP[30007];
int maxx[30007] = {0};
int gems[30007] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	// vi a(n);
	rep(i,0,n){
		int p;
		cin >> p;
		gems[p]++;
	}
	DP[d][d] = gems[d];
	maxx[d] = gems[d];
	int M = 0;
	rep(i,d,30001){
		for(auto& [dis, g] : DP[i]) {
			if (dis < 3) {
				int nd = 1;
				// bool flag = false;
				if (nd + i < 30001) {
					auto it = DP[i+nd].find(nd);
					if (it == DP[i+nd].end()){
						DP[i+nd][nd] = g + gems[i+nd];
					} else {
						it->second = max(it->second, g + gems[i+nd]);
					}
					maxx[i+nd] = max(maxx[i+nd], g + gems[i+nd]);
				} else {
					M = max(M, g);
				}
				if (maxx[i] == g) break;
				continue;
			}
			for(int nd = dis-1; nd <= dis+1; ++nd){
				if (nd<1) continue;
				if (i+nd < 30001) {
					auto it = DP[i+nd].find(nd);
					if (it == DP[i+nd].end()){
						DP[i+nd][nd] = g + gems[i+nd];
					} else {
						it->second = max(it->second, g + gems[i+nd]);
					}
					maxx[i+nd] = max(maxx[i+nd], g + gems[i+nd]);
				} else {
					M = max(M, g);
				}
			}
		}
	}
	cout << M << endl;
}