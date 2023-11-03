#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, M, Q;
char G[2001][2001];
int MX[2001][2001][12] = {{{0}}};

void solve(){
    cin >> N >> M;
    rep(i,0,N){
        string s;
        cin >> s;
        rep(j,0,M){
            G[i][j] = s[j];
            if (s[j] == '#') {
                MX[i][j][0] = 0;
            } else if (i==0 || j==0) {
                MX[i][j][0] = 1;
            } else if (MX[i-1][j][0] == MX[i][j-1][0]) {
                int k = MX[i-1][j][0];
                if (G[i-k][j-k] == '.') {
                    MX[i][j][0] = k+1;
                } else {
                    MX[i][j][0] = k;
                }
            } else {
                MX[i][j][0] =
                    min(MX[i-1][j][0], MX[i][j-1][0])+1;
            }
            // cout << MX[i][j][0] << " ";
        }
        // cout << endl;
    }
    rep(k,1,12){
        // cout << k << endl;
        rep(i,0,N){
            rep(j,0,M){
                int ni = min(N, i+(1<<(k-1)));
                int nj = min(M, j+(1<<(k-1)));
                MX[i][j][k] = max(MX[ni][nj][k-1],
                    max(MX[i][nj][k-1], max(
                        MX[ni][j][k-1], MX[i][j][k-1])));
                // cout << MX[i][j][k] << " ";
            }
            // cout << endl;
        }
        // cout << endl << endl;
    }
    cin >> Q;
    rep(q, 0, Q){
        int r, c;
        cin >> r >> c;
        r--; c--;
        int lo = 0, hi = min(N, M)+1;
        while(hi-lo > 1){
            int md = (hi+lo)/2;
            int big = 0, s = floor(log2(md));
            int nr = max(r, min(N - (1<<s), r+md-(1<<s)));
            int nc = max(c, min(M - (1<<s), c+md-(1<<s)));
            big = max(big, MX[r][c][s]);
            big = max(big, MX[nr][c][s]);
            big = max(big, MX[r][nc][s]);
            big = max(big, MX[nr][nc][s]);
            if (big >= md) lo = md;
            else hi = md;
        }
        cout << lo*lo << endl;
    }
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}