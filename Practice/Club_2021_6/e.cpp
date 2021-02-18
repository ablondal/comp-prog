#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int ct(vi &a, int x){
	int tot = 0;
	for(auto b : a){
		if (b<=x) tot++;
	}
	return tot;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	sort(all(a));
	int lo = 0;
	int hi = 1e9+1;
	while(hi-lo>1){
		int mid = (hi+lo)>>1;
		int tot = ct(a, mid);
		if (tot==k){
			lo = hi = mid;
		}else if (tot<k){
			lo = mid;
		}else{
			hi = mid;
		}
	}
	if (hi!=lo){
		cout << -1 << endl;
	}else{
		cout << lo << endl;
	}
}