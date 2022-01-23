#include "bits/stdc++.h"
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

using vvd = vector<vector<double>>;
// void matmul(vvd& a, vvd& b, vvd& c){
// 	int n = sz(a);
// 	// vvd res(n, vector<double>(n,0));
// 	rep(i,0,n){
// 		rep(j,0,n){
// 			c[i][j] = 0;
// 			rep(k,0,n){
// 				c[i][j] += a[i][k] * b[j][k];
// 			}
// 		}
// 		// cout << i << endl;
// 	}
// }

vector<double> solve(vvd A, vector<double> b){
	int n = sz(A);
	rep(i,0,n){
		int mxr = i;
		rep(j,i+1,n){
			if (abs(A[j][i]) > abs(A[mxr][i])) mxr = j;
		}
		swap(A[mxr], A[i]);
		swap(b[mxr], b[i]);
		double inv = 1/A[i][i];
		rep(j,i,n){
			A[i][j] *= inv;
		}
		b[i] *= inv;
		rep(j,i+1,n){
			double v = A[j][i];
			rep(k,i,n){
				A[j][k] -= A[i][k] * v;
			}
			b[j] -= b[i] * v;
		}
	}
	for(int i=n-1; i>=0; --i){
		rep(j,0,i){
			b[j] -= A[j][i] * b[i];
			A[j][i] = 0;
		}
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int h = n * (n+1);
	h /= 2;
	// cout << h << endl;
	vector<double> v(h);
	vector<double> probs(h);
	vector<double> newprobs(h);
	vi row(h);
	vector<vector<pair<int, double>>> adj;
	int rr = 1;
	int cct = 1;
	rep(i,0,h){
		cin >> v[i];
		row[i] = rr;
		cct--;
		if (cct==0) {
			rr++;
			cct = rr;
		}
	}

	vvd mat(h, vector<double>(h, 0));
	vector<double> B(h, 0);

	rep(i,0,h){
		double a,b,c,d,e;
		cin >> a >> b >> c >> d >> e;
		if (a != 0) {
			mat[i][i-row[i]] = a;
			// adj[i].push_back({i-row[i], a});
		}
		if (b != 0) {
			mat[i][i-row[i]+1] = b;
			// adj[i].push_back({i-row[i]+1, b});
		}
		if (c != 0) {
			mat[i][i+row[i]] = c;
			// adj[i].push_back({i+row[i], c});
		}
		if (d != 0){
			mat[i][i+row[i]+1] = d;
			// adj[i].push_back({i+row[i]+1, d});
		}
		if (e != 0){
			B[i] = -e*v[i];
			mat[i][i] = -1;
			// adj[i].push_back({i+h, e});
		}
		// mat[h][i+h] = 1;
	}
	// mat[h][h] = 1;

	// rep(i,0,h+1){
	// 	mat[i][i] -= 1;
	// }

	// rep(i,0,sz(mat)){
	// 	rep(j,0,sz(mat)){
	// 		cout << mat[i][j] << "\t";
	// 	}
	// 	cout << "|\t" << B[i];
	// 	cout << endl;
	// }

	auto x = solve(mat, B);

	// rep(i,0,sz(x)){
	// 	cout << x[i] << "\t";
	// }
	// cout << endl;

	cout << setprecision(12) << x[0] << endl;


	// rep(rr, 0, 100){
	// 	rep(i,0,h+1){
	// 		rep(j,0,h+1){
	// 			mat3[i][j] = mat[j][i];
	// 		}
	// 	}
	// 	// cout << rr << " " << h << endl;
	// 	matmul(mat, mat3, mat2);
	// 	swap(mat2, mat);
	// }

	// rep(i,0,sz(mat)){
	// 	rep(j,0,sz(mat)){
	// 		cout << setprecision(4) << mat[i][j] << "\t";
	// 	}
	// 	cout << endl;
	// }

	// double sum = 0;
	// rep(j,h,2*h){
	// 	sum += (mat[j][0] * v[j-h]);
	// }
	// cout << setprecision(6) << mat[h][0] << endl;

}