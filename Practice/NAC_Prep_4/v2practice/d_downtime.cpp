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
	int n, k;
	cin >> n >> k;
	queue<int> Q;
	int M = 0;
	rep(i,0,n){
		int a;
		cin >> a;
		while(!Q.empty() && Q.front()<=a-1000){
			Q.pop();
		}
		Q.push(a);
		M = max(M, sz(Q));
	}
	cout << (M + k - 1) / k << endl;
}