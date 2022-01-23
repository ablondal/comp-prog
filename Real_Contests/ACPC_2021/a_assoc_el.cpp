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

int ask[10007] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b, c;
	cin >> a >> b >> c;
	if (c == "1") {
		cout << "What an excellent example!" << endl;
	} else if (c == "2" and b == "2") {
		cout << "What an excellent example!" << endl;
	} else if (a == "1") {
		cout << "What an excellent example!" << endl;
	}else{
		cout << "Oh look, a squirrel!" << endl;
	}
}