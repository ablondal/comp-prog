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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		priority_queue<pair<int, int>> Q;
		rep(i,0,n){
			int tmp;
			cin >> tmp;
			Q.push({tmp, i+1});
		}
		vector<pair<int, int>> ans;
		while(true){
			auto a = Q.top();
			Q.pop();
			auto b = Q.top();
			Q.pop();
			if (b.first == 0) break;
			ans.push_back({a.second, b.second});
			a.first--;
			b.first--;
			Q.push(a);
			Q.push(b);
		}
		cout << sz(ans) << endl;
		for(auto& aa : ans){
			cout << aa.first << " " << aa.second << endl;
		}
	}
}