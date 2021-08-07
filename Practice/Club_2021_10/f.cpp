#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// unordered_map <int, int> a, b;

int A[4000], B[4000], C[4000], D[4000];

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		scanf(" %d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}
	vi a(n*n), b(n*n);
	rep(i,0,n){
		rep(j,0,n){
			int v1 = A[i] + B[j];
			int v2 = C[i] + D[j];
			a[n*i+j] = v1;
			b[n*i+j] = v2;
		}
	}
	sort(all(a));
	sort(all(b));
	ll tot = 0;
	for(auto j : a){
		tot += upper_bound(all(b), -j) - lower_bound(all(b), -j);
	}
	cout << tot << endl;
}