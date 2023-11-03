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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		sort(all(s));
		string as(k, 'a');
		rep(i,0,n){
			rep(j,0,k){
				if (as[j] >= 'a'+(n/k)){
					continue;
				}
				if (as[j] == s[i]){
					as[j]++;
					break;
				}
			}
		}
		cout << as << endl;
	}
}