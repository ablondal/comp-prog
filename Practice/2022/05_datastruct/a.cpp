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
	vi st;
	string s;
	int n;
	cin >> n;
	while(n--){
		cin >> s;
		st.clear();
		bool w = true;
		for(auto& c : s){
			if (c=='$') st.push_back(1);
			if (c=='|') st.push_back(2);
			if (c=='*') st.push_back(3);
			if (c=='t') {
				if (!st.empty() && st.back() == 2) st.pop_back();
				else {
					w = false;
					break;
				}
			}
			if (c=='j') {
				if (!st.empty() && st.back() == 3) st.pop_back();
				else {
					w = false;
					break;
				}
			}
			if (c=='b') {
				if (!st.empty() && st.back() == 1) st.pop_back();
				else {
					w = false;
					break;
				}
			}
		}
		if (!st.empty()) w = false;
		cout << (w ? "YES" : "NO") << endl;
	}
}