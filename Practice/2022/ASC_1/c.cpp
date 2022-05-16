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
const int MX = 500007;
vi deps[MX];
int DP[MX][2] = {{0}}; // 1 for gets grant, 0 for doesn't
int gg[MX] = {0};
int p[MX];

void get_DP(int v){
	int tot = 0;
	for(auto &e : deps[v]){
		get_DP(e);
		tot += DP[e][0];
	}
	DP[v][1] = tot;
	DP[v][0] = DP[v][1];
	gg[v] = 0;
	for(auto& e : deps[v]){
		DP[v][0] = max(DP[v][0], DP[v][1] - DP[e][0] + DP[e][1] + 1);
		if (DP[v][0] == DP[v][1] - DP[e][0] + DP[e][1] + 1){
			gg[v] = e;
		}
	}
}

vi res;

void put_on_res(int v, int ch){
	if (ch) {
		res.push_back(v);
		for(auto& e: deps[v]){
			put_on_res(e, 0);
		}
	} else {
		for(auto& e: deps[v]){
			put_on_res(e, e==gg[v]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream in("grant.in");
	ofstream out("grant.out");
	int n;
	in >> n;
	rep(i,2,n+1){
		in >> p[i];
		deps[p[i]].push_back(i);
	}
	get_DP(1);
	put_on_res(1, 0);
	out << sz(res) * 1000 << endl;
	sort(all(res));
	for(auto& e : res){
		out << e << " ";
	}
	out << endl;




}