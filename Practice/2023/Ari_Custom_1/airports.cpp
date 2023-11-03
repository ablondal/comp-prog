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

// We can do this with max matching!
const int MAXN = 507;
vi adj[MAXN];
int M[MAXN] = {0};
bool vis[MAXN] = {0};
// Match flight endpoints with flight beginnings
int match(int v){
	if (vis[v]) return false;
	vis[v] = true;
	for (auto to: adj[v]) {
		// if (vis[to]) continue;
		// vis[to] = true;
		if (M[to] == -1 || match(M[to])) {
			M[to] = v;
			return true;
		}
	}
	return false;
}

int max_matches(int m){
	// Initialize max matching
	rep(i,0,MAXN) M[i] = -1;
	int tot = 0;

	// Try matching each element
	rep(i,0,m){
		memset(vis, 0, MAXN);
		tot += match(i);
	}
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	// Get Inspection Times
	vi inspection_time(n+1);
	rep(i,1,n+1) cin >> inspection_time[i];

	// Get distances
	vector<vi> d(n+1, vi(n+1));
	rep(i,1,n+1){
		rep(j,1,n+1){
			// Time to travel from i to j
			cin >> d[i][j];
			// Add on extra inspection time at the end
			d[i][j] += inspection_time[j];
		}
	}

	// Get all flight info
	vector<tuple<int, int, int, int>> flights(m);
	rep(i,0,m){
		int s, f, t, e;
		// Start, Finish, Departure Time, End time (including inspection)
		cin >> s >> f >> t;

		e = t + d[s][f];
		flights[i] = {s, f, t, e};
	}

	// Calculate all-pairs minimum distances
	rep(k,1,n+1){
		rep(i,1,n+1){
			rep(j,1,n+1){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	// Figure out which flights can connect to which other flights
	// Can you go from the end of flight i to the beginning of flight j?
	rep(i,0,m){
		auto [s, f, t, e] = flights[i];
		rep(j,0,m){
			if (i == j) continue; // Can't connect with yourself
			auto [s1, f1, t1, e1] = flights[j];
			if (s1 == f && e <= t1) {
				adj[i].push_back(j);
			} else if (e + d[f][s1] <= t1) {
				adj[i].push_back(j);
			}
		}
	}
	

	// Get answer
	cout << m - max_matches(m) << endl;
}