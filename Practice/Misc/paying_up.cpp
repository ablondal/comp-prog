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
	int t;
	cin >> t;
	while(t--){
		int n, m;
		bool works = false;
		cin >> n >> m;
		vector<int> bank_notes(n);
		for(int i=0; i<n; ++i){
			cin >> bank_notes[i];
		}
		for(int mask=0; mask<(1<<n); ++mask){
			int s = 0;
			for(int j=0; j<n; ++j){
				if (mask & (1 << j)){
					s += bank_notes[j];
				}
			}
			if (s == m) works = true;
		}
		cout << (works ? "Yes" : "No") << endl;
	}
}