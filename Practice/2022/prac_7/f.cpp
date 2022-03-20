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
typedef complex<double> cd;

typedef vector<double> vd;
typedef vector<vd> vvd;

vvd matmul(vvd &a, vvd &b){
	int n = sz(a);
	vvd c(n, vd(n, 0));
	rep(i,0,n) rep(j,0,n) rep(k,0,n){
		c[i][j] = a[i][k]*b[k][j];
	}
	return c;
}

vector<pair<int, double>> adj[100];
vi ad[100];
map<pair<int, int>, int> M;
int Mi = 0;
int gi(int a, int b){
	if (M.count({a,b})) return M[{a,b}];
	return M[{a,b}] = Mi++;
}

char G[31][31] = {{0}};


void dijkstra(int s, vector<double> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l,w;
	cin >> l >> w;
	int n = 80;
	int si, sj, ti, tj;
	rep(i,0,l){
		string s;
		getline(cin, s);
		rep(j,0,w){
			G[i][j] = s[j];
			if (i && G[i][j] == ' ' && G[i-1][j] == ' '){
				ad[gi(i,j)].push_back(gi(i-1,j));
				ad[gi(i-1,j)].push_back(gi(i,j));
			}

			if (j && G[i][j] == ' ' && G[i][j-1] == ' '){
				ad[gi(i,j)].push_back(gi(i,j-1));
				ad[gi(i,j-1)].push_back(gi(i,j));
			}
			if (G[i][j] == 'E'){
				si = i; sj = j;
			} else if (G[i][j] == 'D'){
				ti = i; tj = j;
			}
		}
	}
	vvd c(Mi, vd(Mi, 0));
	rep(i,0,Mi){
		// c[to][from]
		for(auto to: ad[i]){
			c[to][i] = 1.0/((double)ad[i].size());
		}
	}
	rep(i,0,100){
		c = matmul(c, c);
	}

	int S = gi(si, sj);
	int T = gi(ti, tj);

	vector<double> Cost(Mi, 0);
	rep(i,0,Mi-2){
		Cost[i] = (c[i][0] + c[i][1]) / 2;
	}

	rep(i,0,l){
		rep(j,0,w){
			if (i && G[i][j] != '#' && G[i-1][j] != '#'){
				adj[gi(i,j)].push_back({gi(i-1,j), Cost[gi(i-1,j)]});
				adj[gi(i-1,j)].push_back({gi(i,j), Cost[gi(i,j)]});
			}

			if (j && G[i][j] != '#' && G[i][j-1] != '#'){
				adj[gi(i,j)].push_back({gi(i,j-1), Cost[gi(i,j-1)]});
				adj[gi(i,j-1)].push_back({gi(i,j), Cost[gi(i,j)]});
			}
			if (G[i][j] == 'E'){
				si = i; sj = j;
			} else if (G[i][j] == 'D'){
				ti = i; tj = j;
			}
		}
	}





}