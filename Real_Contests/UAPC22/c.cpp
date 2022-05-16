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
const int MAXN = 1e5+7;

int UF[MAXN];
int find(int v){
	return (UF[v]==-1 ? v : UF[v] = find(UF[v]));
}
void comb(int i, int j){
	i = find(i);
	j = find(j);
	if (i!=j){
		UF[i] = j;
	}
}

map<int, vector<int>> d1, d2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		int r,c;
		UF[i] = -1;
		cin >> r >> c;
		d1[r-c].push_back(i);
		d2[r+c].push_back(i);
	}
	for(auto &[d, v]: d1){
		auto it = d1.find(d+1);
		if (it != d1.end()){
			comb(it->second.back(), v.back());
		}
		rep(i,0,sz(v)-1){
			comb(v[i], v[i+1]);
		}
	}
	for(auto &[d, v]: d2){
		auto it = d2.find(d+1);
		if (it != d2.end()){
			comb(it->second.back(), v.back());
		}
		rep(i,0,sz(v)-1){
			comb(v[i], v[i+1]);
		}
	}
	int tot = 0;
	rep(i,0,n){
		tot += UF[i]==-1;
	}
	cout << tot << endl;
}