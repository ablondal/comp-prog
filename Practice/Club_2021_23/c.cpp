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
	int k;
	// priority_queue<int, vi, greater<int>> Q;
	// int tot = 0
	cin >> k;
	rep(t,0,k){
		int n;
		cin >> n;
		vi a(n);
		rep(j,0,n) cin >> a[j];
		set<pair<int, int>> S;
		int tot = 0;
		rep(i,0,n){
			auto it = S.begin();
			while(it != S.end() && it->first * a[i] <= 2*i+1){
				if (it->first * a[i] == i+1+it->second) tot++;
				it++;
			}
			S.insert({a[i], i+1});
		}
		cout << tot << endl;
	}
}