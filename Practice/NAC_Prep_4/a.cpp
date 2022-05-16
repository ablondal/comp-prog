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
const int MX = 1e5+7;

vi adj[MX];
char vis[MX] = {0};
int d[MX] = {0};
int M = 0;

int dfs(int v, int p){
    vi ch_s;
    vis[v] = true;
    for(auto e:adj[v]){
        if (e == p) continue;
        ch_s.push_back(dfs(e, v));
        d[v] = max(d[v], d[e]+1);
    }
    sort(all(ch_s));
    int n = sz(ch_s);
    // cout << v << ": " << d[v] << endl;

    if (n>=2){
        M = max(M, ch_s[n-1]+ch_s[n-2]+2);
    }
    M = max(M, d[v]);
    return d[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, l;
    cin >> c >> l;
    rep(i,0,l){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi a;
    rep(i,0,c){
        if (!vis[i]){
            M = 0;
            dfs(i, -1);
            // cout << M << endl;
            a.push_back( M );
        }
    }
    sort(all(a));
    int n = sz(a);
    M = a[n-1];
    if (n>=2) {
        M = max(M, ((a[n-1]+1)/2) + ((a[n-2]+1)/2) + 1);
    }
    if (n>=3) {
        M = max(M, ((a[n-3]+1)/2) + ((a[n-2]+1)/2) + 2);
    }
    cout << M << endl;

}