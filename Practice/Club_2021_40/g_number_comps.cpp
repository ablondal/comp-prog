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

int UF[307*307] = {0};
int id[307*307] = {0};
int n, m, q;

// vi changes;

int find(int v) {
	return (UF[v]<0 ? v : UF[v] = find(UF[v]));
}

inline int connect(int a, int b){
	a = find(a);
	b = find(b);
	if (a==b) return 0;
	if (a>b) swap(a,b);
	UF[a] += UF[b];
	UF[b] = a;
	return 1;
}

inline void CCs(vector<pair<int, int>>& conns, int idd, vector<pair<int, int>>& res){
	// rep(i,0,n*m) UF[i] = -2;
	int ncomp = 0;
	for(auto& [pos, time]: conns){
		if (id[pos] != idd) {
			ncomp++;
			id[pos] = idd;
			UF[pos] = -1;
			vi changes;
			if (pos % n > 0) {
				if (id[pos-1] == idd){
					ncomp -= connect(pos, pos-1);
				}
			}
			if (pos % n < n-1) {
				if (id[pos+1] == idd){
					ncomp -= connect(pos, pos+1);
				}
			}
			if (pos / n > 0) {
				if (id[pos-n] == idd){
					ncomp -= connect(pos, pos-n);
				}
			}
			if (pos / n < m-1) {
				if (id[pos+n] == idd){
					ncomp -= connect(pos, pos+n);
				}
			}
		}
		res.push_back({ncomp, time});
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> q;
	// scanf("%d %d %d", &n, &m, &q);
	int mc = max(1000, (int)ceil(2e6/(n*m)) );
	vector<vector<pair<int, int>>> reqs1(mc+1), reqs2(mc+1);

	vi grid(n*m, 0);
	// changes = {1, -1, n, -n};

	rep(i,0,n*m){
		reqs1[0].push_back({i, -1});
	}

	rep(i,0,q){
		int x, y, c;
		// scanf("%d %d %d", &x, &y, &c);
		cin >> x >> y >> c;
		x--;y--;
		reqs1[c].push_back({y*n+x, i});
		reqs2[grid[y*n+x]].push_back({y*n+x, i-1});
		grid[y*n+x] = c;
	}

	rep(i,0,n*m){
		reqs2[grid[i]].push_back({i, q+7});
	}

	// for(auto r : reqs1){
	// 	auto [c, r2] = r;
	// 	cout << c << endl;
	// 	for(auto [pos, time] : r2){
	// 		cout << "\t" << pos << " " << time << endl;
	// 	}
	// }

	for(auto& r : reqs2){
		reverse(all(r));
		// auto [c, r2] = r;
		// cout << c << endl;
		// for(auto [pos, time] : r2){
		// 	cout << "\t" << pos << " " << time << endl;
		// }
	}

	vi resup(q+10, 0);

	int idd = 1;

	vector<pair<int, int>> res1, res2;

	for(int i=0; i<=mc; ++i){
		auto& r1 = reqs1[i];
		auto& r2 = reqs2[i];
		if (r1.empty()) {
			continue;
		}
		// cout << "here" << endl;
		res1.clear();
		res2.clear();
		CCs(r1, idd, res1);
		CCs(r2, idd+1, res2);
		idd += 2;
		// reverse(all(res2));
		// res2.push_back({0, res2.back().second+1});
		// for(int i=0; i<sz(res2)-1; ++i){
		// 	res2[i].second += 1;
		// 	res2[i].first = res2[i+1].first;
		// }
		for(int i=sz(res2)-1; i>=0; --i){
			if (i==0) {
				res2[i].first = 0;
				res2[i].second += 1;
			} else {
				res2[i].second += 1;
				res2[i].first = res2[i-1].first;
			}
		}
		// res2.pop_back();
		// cout << i << endl;
		// for(auto aa: res1){
		// 	cout << "\t" << aa.first << " " << aa.second << endl;
		// }
		for(int i=0; i<sz(res1); ++i){
			if (i==0 || res1[i-1].second < 0) {
				resup[res1[i].second] += res1[i].first;
			} else {
				resup[res1[i].second] += res1[i].first - res1[i-1].first;
			}
		}
		for (int i=sz(res2)-1; i>=0; --i) {
			if (i==sz(res2)-1) {
				resup[res2[i].second] += res2[i].first - res1.back().first;
			} else {
				resup[res2[i].second] += res2[i].first - res2[i+1].first;
			}
		}
	}

	resup[0]++;

	rep(i,0,q){
		if (i) resup[i] += resup[i-1];
		cout << resup[i] << " ";
		// printf("%d\n", resup[i]);
	}
	cout << endl;


}