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
	int n;
	cin >> n;
	while(n--){
		int t;
		cin >> t;
		vi b(t);
		map<int, int> M;
		rep(i,0,t){
			cin >> b[i];
			M[b[i]]++;
		}
		for(int i=0; i<sz(b); ++i){
			if (M[b[i]]==1){
				cout << i+1 << endl;
			}
		}
	}
}