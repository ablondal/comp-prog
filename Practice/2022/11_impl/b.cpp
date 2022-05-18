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
const double PI = acos(-1);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vi l(m), t(n);
	rep(i,0,n){
		cin >> t[i];
	}
	rep(i,0,m){
		cin >> l[i];
	}
	sort(all(t));
	sort(all(l));
	int i=0, j=0, tot=0;
	while(i<sz(t) && j<sz(l)){
		while (j < sz(l) && t[i] > l[j] ){
			j++;
		}
		if (j < sz(l) && t[i] <= l[j]){
			tot++;
			i++;
			j++;
		}
	}
	cout << tot << endl;
}