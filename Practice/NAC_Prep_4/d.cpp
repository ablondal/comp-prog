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
	int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    sort(all(a));
    int lo = 0, hi = 0;
    int M = 0;
    rep(i,0,n){
        int ct = a[i];
        // cout << ct << endl;
        // cout << a[lo] << endl;
        while(a[lo] <= ct-1000) lo++;
        // cout << a[lo] << endl;
        M = max(M, i-lo+1);
    }
    cout << (M+k-1)/k << endl;
}