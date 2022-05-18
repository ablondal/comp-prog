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

char DP[107][10007] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
    cin >> k;
    bool w = true;
    rep(i,0,k){
        int s, n;
        cin >> s >> n;
        s++;
        rep(i,0,s) DP[0][i] = 1;
        rep(i,0,n){
            rep(j,0,s) DP[i+1][j] = 0;
            int a, b;
            cin >> a >> b;
            int c = b-a;
            rep(j,0,s){
                if (DP[i][j]){
                    if (j+c<s) DP[i+1][j+c] = 1;
                    if (j-c>=0) DP[i+1][j-c] = 1;
                }
            }
        }
        bool ww = false;
        rep(j,0,s){
            if (DP[n][j]) ww = true;
        }
        w = w & ww;
    }
    cout << (w ? "possible" : "impossible") << endl;
}