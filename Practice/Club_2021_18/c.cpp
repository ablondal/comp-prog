#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

stack<pair<ll,ll>> S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> ans;
	while(n){
		ll m = 0;
		rep(i,0,n){
			ll tmp;
			cin >> tmp;
			ll lastb = i;
			while(!S.empty() && S.top().first > tmp){
				lastb = min(lastb, S.top().second);
				m = max( m, S.top().first * (i - S.top().second) );
				S.pop();
			}
			S.push({tmp, lastb});
		}
		while(!S.empty()){
			m = max(m, S.top().first * (n - S.top().second) );
			S.pop();
		}
		cout << m << endl;

		cin >> n;
	}
}