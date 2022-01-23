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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	const int N = 10000007;
	vi sumdiv(N, 0);
	// int sumdiv[N] = {0};
	rep(i,1,N){
		for(int j=i; j<N; j+=i){
			sumdiv[j] += i;
		}
	}

	// cout << sumdiv[100] << endl;
	vi mn(N, -1);
	rep(i,1,N){
		if (sumdiv[i]<N && mn[sumdiv[i]]==-1){
			mn[sumdiv[i]] = i;
		}
	}


	int t;
	cin >> t;
	while(t--){
		int c;
		cin >> c;
		cout << mn[c] << endl;
	}
}