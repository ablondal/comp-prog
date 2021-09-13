#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const double PI = acos(-1);

vi adj[3007];

struct fter{
	int x, y, a, r;
	// friend istream operator>>(fter);
};

istream& operator>>(istream& in, fter& f){
	return in >> f.x >> f.y >> f.a >> f.r;
}

inline double angdist(double a , double b){
	return min(abs(a-b), min(abs(a-b+360), abs(a-b-360)));
}

inline bool cansee(fter& a, fter& b){
	double ang = atan2(b.y - a.y, b.x - a.x) * 180 / PI;
	return angdist(ang, a.a) <= a.r;
}

vector<int> toposort(int n){
	vi ans;
	int ct[3007] = {0};
	vi zeroes;
	rep(i,0,n){
		for(auto e : adj[i]){
			ct[e]++;
		}
	}
	rep(i,0,n){
		if (ct[i]==0){
			zeroes.push_back(i);
		}
	}
	while(zeroes.size()){
		ans.push_back(zeroes.back());
		zeroes.pop_back();
		for(auto e: adj[ans.back()]){
			ct[e]--;
			if (ct[e]==0){
				zeroes.push_back(e);
			}
		}
	}
	if (ans.size() == n){
		return ans;
	}else{
		return {};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	// vi x(n), y(n), a(n), r(n);
	vector<fter> f(n);
	rep(i,0,n){
		cin >> f[i];
	}
	rep(i,0,n){
		rep(j,0,n){
			if (i==j) continue;
			if (cansee(f[i], f[j])) {
				adj[i].push_back(j);
				// cout << i << "->" << j << endl;
			}
		}
	}
	vi ans = toposort(n);
	if (ans.size()){
		for(auto e : ans){
			cout << e+1 << " ";
		}
		cout << endl;
	}else{
		cout << -1 << endl;
	}
}