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

struct SA{
    string s;
    vi link, len, ct, t;
    int la=0, ni=1;
    vector<map<char,int>> nx;
    void add_c(char x){
        int a=la, c=ni++;
        len[c] = len[a]+1; ct[c]=1; la=c;
        while(a!=-1 && !nx[a].count(x)){
            nx[a][x]=c;a = link[a];
        }
        if (a==-1) {
            link[c] = 0;
        } else {
            int q = nx[a][x];
            if (len[a]+1==len[q]){
                link[c]=q;
            } else {
                int cl = ni++;
                link[cl] = link[q]; nx[cl]=nx[q];
                len[cl] = len[a]+1;
                while(a != -1 && nx[a][x]==q){
                    nx[a][x]=cl; a=link[a];
                }
                link[q] = link[c]=cl;
            }
        }
    }
    SA(string s):s(s),link(2*sz(s)+1, 0), len(2*sz(s)+1, 0), ct(2*sz(s)+1, 0), t(2*sz(s)+1, 0), nx(2*sz(s)+1){
        link[0]=-1; len[0]=0;
        for(auto x:s) add_c(x);
        t[la]=true;
        vi a(ni, 0); iota(all(a), 0);
        sort(all(a), [this](int b, int c){return len[b]<len[c];});
        for(int i=ni-1; i>0; --i){
            // t[link[a[i]]] = t[a[i]];
            ct[link[a[i]]] += ct[a[i]];
        }
        int v = la;
        while(v != -1){
            t[v] = true;
            v = link[v];
        }
        ct[0]=0;
    }
};

vector<pair<int, int>> adj[507];

int DP[507] = {0};
int vis[507] = {0}, instack[507] = {0};

int dfs(int v){
    if (instack[v]) return -1;
    if (vis[v]) return DP[v];
    instack[v] = true;
    vis[v] = true;
    for(auto [e, d] : adj[v]){
        int f = dfs(e);
        if (f == -1) {
            return DP[v] = -1;
        }
        DP[v] = max(DP[v], d + f);
    }
    instack[v] = false;
    return DP[v];
}

int calc_max(string &s, SA &sa){
    int v = 0;
    int m = 0;
    rep(i,0,sz(s)){
        char c = s[i];
        if (sa.nx[v].count(c)){
            v = sa.nx[v][c];
            if (sa.t[v]) m = max(m, i+1);
        } else {
            break;
        }
    }
    return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin >> n;
    vector<string> a(n);
    vector<SA> b;
    rep(i,0,n){
        cin >> a[i];
        b.emplace_back(a[i]);
    }
    rep(i,0,n){
        rep(j,0,n){
            if (i==j) continue;
            int m = calc_max(a[j], b[i]);
            if (m) {
                adj[i].push_back({j, m});
            }
            // cout << a[i] << " " << a[j] << " " << m << endl;
        }
    }
    // rep(i,0,n){
    //     cout << i << ": ";
    //     for(auto bb : adj[i]) cout << "(" << bb.first << "," << bb.second << ")" << " ";
    //     cout << endl;
    // }

    int M = 0;
    rep(i,0,n){
        int f = dfs(i);
        if (f == -1) {
            M = -1;
            break;
        }
        M = max(M, f);
    }
    if (M == -1){
        cout << "Shakespeare, who?" << endl;
    } else {
        cout << M << endl;
    }
}