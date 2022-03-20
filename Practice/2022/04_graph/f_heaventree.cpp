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
	int t;
	cin >> t;
	while(t--){
	int n, m;
	cin >> n >> m;
	unordered_set<int> A;
	rep(i,1,n+1){
		A.insert(i);
	}
	rep(i,0,m){
		int a,b,c;
		cin >> a >> b >> c;
		if (A.count(b)){
			A.erase(A.find(b));
		}
	}
	int M = *A.begin();
	rep(i,1,n+1){
		if (i!=M){
			cout << M << " " << i << endl;
		}
	}
	}
}