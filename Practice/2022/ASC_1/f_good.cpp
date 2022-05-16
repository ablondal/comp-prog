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
const double eps = 1e-9;

cd pts[307];
vi adj[307];
char vis[307] = {0};
double ang[307] = {0};
bool g = true;

void dfs(int v, double curr_ang){
	if (vis[v]){
		if ( abs(curr_ang - ang[v]) > 1 ) {
			g = false;
		}
		return;
	}
	vis[v] = true;
	ang[v] = curr_ang;
	for(auto& e : adj[v]){
		cd n_p = pts[e] * polar(1., -arg(pts[v]));
		dfs(e, curr_ang + arg(n_p));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream in("out.in");
	ofstream out("out.out");

	int n;
	in >> n;
	vector<pair<cd, double>> circs;
	rep(i,0,n){
		double x, y, r;
		in >> x >> y >> r;
		circs.push_back({cd(x,y), r});
	}
	double x,y,r;
	in >> x >> y >> r;
	rep(i,0,n){
		circs[i].first -= cd(x,y);
		circs[i].second += r;
		pts[i] = circs[i].first;
		rep(j,0,i){
			cd d = circs[i].first-circs[j].first;
			double rr = circs[i].second + circs[j].second;
			if (abs(d) + eps < rr) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	rep(i,0,n){
		if (!vis[i]) dfs(i, arg(pts[i]));
	}
	if (g) {
		out << "YES" << endl;
	} else {
		out << "NO" << endl;
	}
}