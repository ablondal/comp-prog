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

int N;
using mat = vector<vector<double>>;
mat matmul(mat a, mat b){
	mat c(N, vector<double>(N,0));
	rep(i,0,N) rep(j,0,N) rep(k,0,N){
		c[i][j] += a[i][k]*b[k][j];
	}
	return c;
}

mat binpow(mat& a, int x){
	mat res(N, vector<double>(N, 0));
	rep(i,0,N) res[i][i] = 1;
	mat b(N, vector<double>(N, 0));
	rep(i,0,N) rep(j,0,N) b[i][j] = a[i][j];
	// cout << endl << x << endl;

	while(x){
		if (x & 1){
			res = matmul(res, b);
		}
		b = matmul(b, b);
		x >>= 1;
	}

	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r,c,k;
	double p;
	cin >> r >> c >> k;
	cin >> p;
	N = r*c;
	vi too(N);
	rep(i,0,N) too[i] = i;
	rep(i,0,k){
		int s, e;
		cin >> s >> e;
		too[s-1] = e-1;
	}
	mat a(N, vector<double>(N, 0));
	rep(i,0,N){
		rep(j,1,7){
			int to = min(i+j, N-1);
			to = too[to];
			a[to][i] += 1 / (double) 6.0;
		}
	}
	int lo = 0, hi = 2e8;
	while(hi > lo){
		int md = (hi+lo)/2;
		mat b = binpow(a, md);
		if (b[N-1][0] >= p) {
			hi = md;
		} else {
			lo = md+1;
		}
	}
	cout << lo << endl;
}