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
	int n, m;
	cin >> n >> m;
	map<string, ll> cts;
	for(int i=0; i<n; ++i){
		string s;
		cin >> s;
		ll ct1 = 0;
		for(int j=0; j<m; ++j){
			if (s[j]=='1') ct1++;
		}
		if (ct1 >= 8 && ct1 <= 15){
			cts[s]++;
		}
	}
	int maxct = 0;
	for(auto it = cts.begin(); it != cts.end(); it++){
		if (it->second > maxct) {
			maxct = it->second;
		}
	}
	if (maxct == 0){
		for (int i=0; i<m; ++i){
			if (i<8) cout << "1";
			else cout << "0";
		}
		cout << endl;
	} else {
		string s = "";
		for(auto it = cts.begin(); it!=cts.end(); it++){
			if (it->second == maxct){
				s = it->first;
				break;
			}
		}
		cout << s << endl;
	}
}