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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
    cin >> s;
    int tot = 0;
    rep(i,0,sz(s)){
        if (i%3 == 0 && s[i] != 'P') tot++;
        if (i%3 == 1 && s[i] != 'E') tot++;
        if (i%3 == 2 && s[i] != 'R') tot++;
    }
    cout << tot << endl;
}