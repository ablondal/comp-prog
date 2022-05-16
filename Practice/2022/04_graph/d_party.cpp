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

int d[2007] = {0};
int p[2007] = {0};

int DFS(int v){
	if (d[v]) return d[v];
	if (p[v]<=0) return d[v] = 1;
	return d[v] = DFS(p[v])+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> p[i];
	}
	int m = 0;
	rep(i,1,n+1){
		m = max(m, DFS(i));
	}
	cout << m << endl;
}