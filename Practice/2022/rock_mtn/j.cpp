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
	int S, N;
	cin >> S >> N;
	vi a(N);
	rep(i,0,N){
		cin >> a[i];
	}
	int tot = 0;
	rep(i,1,N){
		tot += (a[i] - a[i-1] - 2) / 2;
	}
	tot += (a[0]+S - a[N-1] - 2) / 2;
	cout << tot << endl;

}