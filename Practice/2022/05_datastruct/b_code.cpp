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
	vi st;
	string s;
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	int tot = 0;
	int dt = 0;
	int cur = 0;
	int i = 0;
	rep(j,0,400){
		while(i <sz(a) && a[i]<=j){
			i++;
			cur++;
		}
		if (dt + cur >= 20){
			tot++;
			cur = 0;
			dt = 0;
		}
		dt += cur;
	}
	cout << tot << endl;
}