#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e7;

int DFS(int i) {
	long long j = i;
	if (i>=MAXN) return i;
	return DFS(i+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a = DFS(0);
	int b, c, d;
	cin >> a >> b >> c >> d;
	if (a-c > 1 && b-d > 1) {
		cout << 1 << " " << endl;
	} else {
		cout << 0 << " " << endl;
	}
}