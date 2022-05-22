#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
int b[31] = {0};
int M = 1e6;

vector<vi> nxtQ, Q;
set<vi> vis;

void add_part(vi& a){
    // sort(all(a));
    reverse(all(a));
    while(!a.empty() && a.back() == 1) a.pop_back();
    M = min(M, accumulate(all(a), 0));

    auto it = vis.find(a);
    if (it == vis.end()){
        vis.insert(a);
        nxtQ.push_back(a);
        // for(auto aa : a){
        //     cout << aa << " ";
        // }
        // cout << endl;
    }
}

vi currp;

set<pair<vi, int>> V;

void dfs(vi &p, int i, int left, int used){
    if (M == 0) return;
    if (left > n-used) return;
    vi hi(all(currp));
    sort(all(hi));
    if (V.count({hi, left})) return;
    V.insert({hi, left});
    if (i == sz(p)) {
        if (left <= n-used) {
            add_part(hi);
        }
        return;
    }
    used += p[i];
    rep(j,1,min(p[i], left+1)) {
        currp.push_back(p[i]-j);
        currp.push_back(j);
        dfs(p, i+1, left-j, used);
        currp.pop_back();
        currp.pop_back();
    }
    currp.push_back(p[i]);
    dfs(p, i+1, left, used);
    currp.pop_back();
    if (left >= p[i]) {
        currp.push_back(p[i]);
        dfs(p, i+1, left-p[i], used);
        currp.pop_back();
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m;
    rep(i,0,m) {
        cin >> b[i];
        b[i] = min(b[i], n-b[i]);
    }
    sort(b, b+m);
    reverse(b, b+m);

    nxtQ.push_back({n});
    rep(i,0,m){
        // cout << i << endl << endl;
        swap(Q, nxtQ);
        nxtQ.clear();

        for(auto p:Q){
            V.clear();
            dfs(p, 0, b[i], 0);
            if (M == 0) break;
        }
        if (M == 0) break;

    }

    cout << n - M << endl;

}

     