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
	string s;
	cin >> s;
	long double aa = 0;
	// reverse(all(s));
	rep(i,0,sz(s)){
		aa *= 10;
		aa += s[i];
	}
	int i=0;
	long double facc = 1;
	while(abs(facc - aa) > (aa*0.9)) {
		i++;
		facc *= i;
	}
	cout << i << endl;
}