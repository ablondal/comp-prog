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

	vector<string> notes{"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
	vector<int> sc_ns = {0, 2, 4, 5, 7, 9, 11};

	int n;
	cin >> n;
	vector<string> ns(n);
	rep(i,0,n) cin >> ns[i];

	vi ans;

	rep(i,0,12){
		bool w = true;
		for (auto n : ns){
			bool inn = false;
			for(int j=0; j<7; ++j){
				if (notes[(sc_ns[j] + i)%12] == n){
					inn = true;
				}
			}
			if (inn == false) {
				w = false;
				break;
			}
		}
		if (w) ans.push_back(i);
	}

	if (ans.empty()){
		cout << "none";
	}

	for(auto aa: ans){
		cout << notes[aa] << " ";
	}
	cout << endl;
}