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

    freopen("game.in","r",stdin);
	int t;
	cin >> t;
	while(t--){
		map<string, int> M;
		int n;
		cin >> n;
		vector<string> a(n);
		rep(i,0,n){
			cin >> a[i];
			if (sz(a[i])%2==1){
				M[a[i]]++;
			}
		}
		int aa = 0;
		for(auto m : M){
			aa ^= m.second;
		}
		if (aa) {
			cout << "Pillow" << endl;
		} else {
			cout << "Khaled" << endl;
		}

	}
}