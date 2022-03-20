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
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	int tot = reduce(all(a), 0);
	int m = *max_element(all(a));
	if (m*2 > tot || tot%2 == 1){
		cout << "no" << endl;
		return 0;
	}
	priority_queue<pair<int, int>> Q;
	rep(i,0,n) if (a[i] != 0) Q.push({a[i], i+1});
	cout << "yes" << endl;
	while(!Q.empty()){
		auto [a, b] = Q.top();
		Q.pop();
		auto [c, d] = Q.top();
		Q.pop();
		a--;
		c--;
		if (a>0) Q.push({a,b});
		if (c>0) Q.push({c,d});
		cout << b << " " << d << endl;
	}
}