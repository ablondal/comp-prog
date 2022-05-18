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

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int X,Y,n;
	cin >> X >> Y >> n;
	vector<pii> Q, nxt;
	vector<vi> V(X+1, vi(Y+1, 0));
	int ct = 0;
	rep(i,0,n){
		int x, y;
		cin >> x >> y;
		Q.push_back({x, y});
		if (!V[x][y]) ct++;
		V[x][y] = 1;
	}
	// int ct = n;
	int days = 1;
	while(ct < X*Y){
		nxt.clear();
		for(auto [x, y]:Q){
			rep(i,0,4){
				int nx = x+d[i][0];
				int ny = y+d[i][1];
				if (nx>0 && nx<=X && ny>0 && ny<=Y && !V[nx][ny]){
					V[nx][ny] = 1;
					nxt.push_back({nx, ny});
					ct++;
				}
			}
		}
		swap(nxt, Q);
		days++;
	}
	cout << days << endl;
}