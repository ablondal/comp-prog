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
	vector<int> rs(1<<n);
	rep(i,0,(1<<n)){
		cin >> rs[i];
	}
	sort(all(rs));
	int i = 1;
	int ct = 0;
	while( i<=n ){
		int lo = (1<<n)-(1<<i);
		int hi = (1<<n)-(1<<(i-1));
		while(hi < (1<<n) && lo < ((1<<n)-(1<<(i-1)))){
			if (rs[hi]-rs[lo] <= k){
				ct++;
				hi++;
				lo++;
			} else {
				lo++;
			}
		}
		i++;
	}
	cout << ct << endl;
}