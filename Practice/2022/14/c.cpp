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
const ll MOD = (1e9 + 7);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	rep(T,0,t){
		if (n % 2 == 0){
			cout << 2 << endl;
			int x, y;
			while(cin >> x >> y){
				if (x == -1) exit(0);
				if (x == 0) break;
				int nx = (n + 1 - x);
				int ny = (n + 1 - y);
				cout << nx << " " << ny << endl;
			}
		} else {
			cout << 1 << endl;
			cout << n/2 << " " << n/2 << endl;
			int x, y;
			while(cin >> x >> y){
				if (x == -1) exit(0);
				if (x == 0) break;
				int nx = (n + 1 - x);
				int ny = (n + 1 - y);
				cout << nx << " " << ny << endl;
			}
		}
	}
}