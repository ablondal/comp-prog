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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	double a, b;
	cin >> n >> m >> a >> b;
	vector<double> A(n+2), B(m), l(m);
	A[0] = -(1e18);
	A[n+1] = (1e18);
	rep(i,0,n) cin >> A[i+1];
	rep(i,0,m) cin >> B[i];
	rep(i,0,m) cin >> l[i];
	int i = 0;
	double md = 1e18;
	int x=1, y=1;
	rep(j,0,m){
		// cout << j << endl;
		while(A[i] < a*B[j]/b){
			i++;
		}
		double d1 = sqrt((b-a)*(b-a) + (B[j]-A[i-1])*(B[j]-A[i-1])) + sqrt(A[i-1]*A[i-1] + a*a);
		double d2 = sqrt((b-a)*(b-a) + (B[j]-A[i])*(B[j]-A[i])) + sqrt(A[i]*A[i] + a*a);

		if (d1 + l[j] < md){
			md = d1 + l[j];
			x = i-1;
			y = j+1;
		}
		if (d2 + l[j] < md){
			md = d2 + l[j];
			x = i;
			y = j+1;
		}
	}
	cout << x << " " << y << endl;


}