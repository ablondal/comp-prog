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
	string s;
	cin >> s;
	auto it = s.find(')') - s.begin();
	if (sz(s) % 2 == 1 || it*2 != sz(s)) {
		cout << "fix" << endl;
	} else {
		cout << "correct" << endl;
	}
}