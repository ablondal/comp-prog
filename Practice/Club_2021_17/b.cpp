#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e3+7;

int p[MX];
char c[MX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,1,n+1){
		int x;
		cin >> x;
		p[i] = x;
	}
	rep(i,1,n+1){
		memset(c,false,MX);
		int px = i;
		while(c[px]==false){
			c[px] = true;
			px = p[px];
		}
		cout << px << " ";
	}
	cout << endl;
}