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

int inf = 1e8;
int M, N; // M is stations, N is lines
ll A;
vector<int> G[11][107]; // Line * 100 + Station
vector<int> lines[11];

int dist[107][11][107];

int md[107][107];

// void dij()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N >> A;
	rep(i,1,N+1){
		int S;
		cin >> S;
		lines[i].resize(S);
		rep(j,0,S){
			cin >> lines[i][j];
			if (j) {
				G[i][lines[i][j-1]].push_back(lines[i][j]);
				G[i][lines[i][j]].push_back(lines[i][j-1]);
			}
		}
	}
	rep(i,0,11) rep(j,0,11) rep(k,0,107) dist[i][j][k] = inf;

	rep(l,1,N+1){
		dist[0][l][1] = 0;
	}
	rep(n_transfer, 0, M+1){
		// Update distances
		if (n_transfer != 0){
			rep(station, 1, M+1){
				int m_dist = inf;
				rep(line, 1, N+1){
					m_dist = min(m_dist,
						dist[n_transfer-1][line][station]);
				}
				rep(line, 1, N+1){	
					dist[n_transfer][line][station] = m_dist;
				}
				md[n_transfer-1][station] = m_dist;
			}
		}
		// Do Bellman-Ford kinda
		rep(l,1,N+1){
			auto& line = lines[l];
			rep(i,1,sz(line)){
				dist[n_transfer][l][line[i]] = min(
					dist[n_transfer][l][line[i]],
					dist[n_transfer][l][line[i-1]]+1
				);
			}
			for(int i = sz(line)-2; i>=0; i--){
				dist[n_transfer][l][line[i]] = min(
					dist[n_transfer][l][line[i]],
					dist[n_transfer][l][line[i+1]]+1
				);
			}
		}
		// cout << n_transfer << endl;
		// rep(i,1,N+1){
		// 	rep(j,1,M+1){
		// 		cout << dist[n_transfer][i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
	}
	int T;
	cin >> T;
	rep(i,0,T){
		ll B;
		cin >> B;
		ll m = A * md[0][M];
		rep(j,1,M){
			m = min(m, (A * md[j][M]) + (B*j));
		}
		cout << m << endl;
	}
}