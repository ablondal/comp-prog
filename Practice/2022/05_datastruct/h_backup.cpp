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

map<string, int> files;
set<string> backs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	while(true){
		getline(cin, s);
		if (s.empty()) break;
		files[s] = 1;
	}
	while(cin.peek() != EOF){
		getline(cin, s);
		// if (s.empty()) break;
		auto it = s.rfind('_');
		it = s.rfind('_', it-1);
		// cout << it << endl;
		auto it2 = files.find(s.substr(0,it));
		if (it2 != files.end()) it2->second--;
		else backs.insert(s);
	}
	bool w = true;
	for(auto &a : backs){
		cout << "F " << a << endl;
		w = false;
	}
	for(auto &[a, f] : files){
		if (f==1) {
			cout << "I " << a << endl;
			w = false;
		} 
	}
	if (w) {
		cout << "No mismatches." << endl;
	}
}