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

int DP[100007][3] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	double h;
	cin >> n >> h;
	double nn = n;
	for(int i=1; i<n; ++i){
		cout << setprecision(12) << h * ( sqrt(i/nn) ) << " ";
	}
	cout << endl;
}