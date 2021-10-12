#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;

ll DP[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		int M = 0;
		for (int i=0; i<sz(a); ++i){
			for (int j=i+1; j<=sz(a); ++j){
				if (b.find(a.substr(i, j-i)) != string::npos) {
					M = max(M, j-i);
				}
			}
		}
		cout << sz(a)+sz(b)-M-M << endl;
	}
}