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
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	sort(all(a));
	int mx = 0;
	int i=0;
	while(i<sz(a)){
		if (a[i]<=i){
			mx = i+1;
		}
		i++;
	}
	cout << mx << endl;
	
}