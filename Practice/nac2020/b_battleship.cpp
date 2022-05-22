#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<int, ll> DP;
int n, k;
bool no[5][5] = {{0}};

int G = 0;
vi ships;

void print_board(int C){
    rep(y,0,n){
        rep(x,0,n){
            if (C & (1<<5*y+x)) {
                cout << "O";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
}

ll DFS(int i, int C);

ll tryplace(int i, int C, int x, int y, int dx, int dy){
    int siz = ships[i];
    bool w = true;
    rep(l, 0, siz){
        int nx = x + l*dx;
        int ny = y + l*dy;
        if (no[ny][nx] || (C & (1<< (5*ny + nx) ))) {
            return 0;
        }
        C |= (1<<(5*ny+nx));
    }
    return DFS(i+1, C);
}

ll ans = 0;

ll DFS(int i, int C){
    if (i==k) {
        if ( (C & G) == G) {
            // print_board(C);
            return 1;
        }
        else return 0;
    }
    auto it = DP.find(C);
    if (it != DP.end()) return it->second;
    
    // cout << i << " " << C << endl;
    int siz = ships[i];
    ll res = 0;
    // Horizontal
    rep(ni,0,n+1-siz) {
        rep(j,0,n) {
            // Hor
            res += tryplace(i, C, ni, j, 1, 0);
            // Ver
            if (siz != 1) res += tryplace(i, C, j, ni, 0, 1);
        }
    }
    return DP[C] = res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> k;
    rep(i,0,n){
        string s;
        cin >> s;
        rep(j,0,n){
            // cout << i*5 + j << endl;
            if (s[j] == 'O') G |= ( 1<< (i*5+j));
            else if (s[j] == 'X') no[i][j] = true;
        }
    }
    // print_board(G);
    // exit(0);
    // cout << G << endl;
    ships.resize(k);
    rep(i,0,k){
        cin >> ships[i];
    }
    sort(all(ships));
    reverse(all(ships));

    cout << DFS(0, 0) << endl;
    // cout << ans << endl;

}