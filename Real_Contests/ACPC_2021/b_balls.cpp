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

// int ask[10007] = {0};

double DP[107][107][107] = {{{0}}};
int N;
double n;

double sums[307] = {0};
ll p[307] = {0};

double getval(int i, int j, int k){
	if (DP[i][j][k]!=-1) return DP[i][j][k];
	if (i>n || j>n || k>n) return 0;
	int n0s = N-i-j-k;
	int balls = i+2*j+3*k;
	DP[i][j][k] = 0;
	if (n0s) DP[i][j][k] += (n0s/n) * getval(i+1,j,k);
	if (i) DP[i][j][k] += (i/n) * getval(i-1, j+1, k);
	if (j) DP[i][j][k] += (j/n) * getval(i, j-1, k+1);
	DP[i][j][k] = max(sums[balls], DP[i][j][k]);
	// cout << i << " " << j << " " << k << " " << DP[i][j][k] << endl;
	return DP[i][j][k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int n;
	cin >> N;
	n = N;
	ll ss = 0;
	sums[0] = 0;
	rep(i,0,3*N){
		cin >> p[i+1];
		sums[i+1] = sums[i] + p[i+1];
		// cout << sums[i+1] << endl;
	}
	rep(i,0,107) rep(j,0,107) rep(k,0,107) DP[i][j][k] = -1;
	cout << setprecision(15) << getval(0,0,0) << endl;
}