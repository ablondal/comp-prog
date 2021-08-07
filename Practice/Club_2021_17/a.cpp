#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char out[(int)1e5+7] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m = 0;
	int nn = 0;
	rep(i,0,2*n){
		int x;
		cin >> x;
		out[x] ^= 1;
		if (out[x]) nn++;
		else nn--;
		m = max(m, nn);
	}
	cout << m << endl;
}