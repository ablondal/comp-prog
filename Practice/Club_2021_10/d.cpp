#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,d;
	cin >> n >> d;
	vi a(n);
	rep(i,0,n){
		cin >> a[i];
	}
	sort(all(a));
	int i=0;
	int ans = 0;
	while(i<sz(a)-1){
		if (a[i+1]-a[i] <= d){
			ans++;
			i+=2;
		}else{
			i++;
		}
	}
	cout << ans << endl;
}