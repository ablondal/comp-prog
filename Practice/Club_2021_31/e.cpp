#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i,0,n) cin >> a[i];
	priority_queue<ll, vector<ll>, greater<ll> > Q;
	ll ct = 0;
	ll hp = 0;
	rep(i,0,n){
		if (a[i] >= 0) {
			ct++;
			hp += a[i];
			// Q.push(a[i]);
		} else if (hp >= -a[i]){
			ct++;
			hp += a[i];
			Q.push(a[i]);
		} else {
			if (Q.size() && Q.top() < a[i]){
				hp -= Q.top();
				hp += a[i];
				Q.pop();
				Q.push(a[i]);
			}
		}
	}
	cout << ct << endl;
}