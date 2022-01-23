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
typedef valarray<int> row;
typedef valarray<valarray<int>> matrix;

int p, m, n;

int inv(int x){
	int r = 1;
	int a = p-2;
	while(a){
		if (a & 1) r = (x*r)%p;
		x = (x*x)%p;
		a>>=1;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> p;
	int N = n*m;
	matrix M(row(0, N+1), N);
	vector<vi> g(n, vi(m, 0));
	rep(i,0,n){
		rep(j,0,m){
			cin >> g[i][j];
			M[i*m + j][N] = p-g[i][j];
			rep(k,0,n) M[k*m+j][i*m+j] = 1;
			rep(k,0,m) M[i*m+k][i*m+j] = 1;
		}
	}

	// Debug - Print matrix
	// rep(i,0,N){
	// 	rep(j,0,N+1){
	// 		cout << M[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	// Get RREF
	rep(i,0,N){
		if (M[i][i] == 0) {
			rep(j,i+1,N){
				if (M[j][i]) {
					swap(M[j], M[i]);
					break;
				}
			}
		}
		M[i] *= inv(M[i][i]);
		M[i] %= p;
		rep(j,i+1,N){
			int t = M[j][i];
			M[j] += M[i] * (p-t);
			M[j] %= p;
		}
	}
	// Solve
	for(int i=N-1; i>=0; --i){
		rep(j,0,i){
			M[j] += M[i] * (p-M[j][i]);
			M[j] %= p;
		}
	}

	// Debug - Print matrix
	// rep(i,0,N){
	// 	rep(j,0,N+1){
	// 		cout << M[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// I hate edge cases
	// Just simulate our solution and see if it works \shrug
	int ssum = 0;
	rep(i,0,N) {
		if (!M[i][i]){
			M[i][N] = 0;
			continue;
		}
		ssum += M[i][N];
		int y=i/m;
		int x=i%m;
		g[y][x] -= M[i][N];
		rep(k,0,n){
			g[k][x] += M[i][N];
		}
		rep(k,0,m){
			g[y][k] += M[i][N];
		}
	}
	rep(i,0,N){
		if (g[i/m][i%m] % p){
			cout << -1 << endl;
			return 0;
		}
	}

	// Print solution
	cout << ssum << endl;
	if (!ssum) return 0;
	rep(i,0,N){
		while(M[i][N]--){
			cout << i+1 << " ";
		}
	}
	cout << endl;
}