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
	string n, m;
	cin >> n >> m;
	// int t = m.size()-1;
	
	while(!n.empty() && n.back() == '0' && m.back() == '0'){
		n.pop_back();
		m.pop_back();
	}
	if (n.empty()) {
		cout << "0" << endl;
		return 0;
	}
	int t = m.size()-1;

	string res;

	if (t) {
		while(t){
			if (n.empty()){
				res.push_back('0');
			}
			else {
				res.push_back(n.back());
				n.pop_back();
			}
			t--;
		}
		res.push_back('.');
	}

	if (!n.empty()){
		while(!n.empty()){
			res.push_back(n.back());
			n.pop_back();
		}
	} else {
		res.push_back('0');
	}

	reverse(all(res));
	cout << res << endl;


}