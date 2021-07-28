#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = (1<<25)+7;
const int INF = 1e5;

// char V[MAXN][25] = {{0}};
unordered_set<int> S;
int n;

int DFS(int, int, int);

void printstate(int state, int x=-1, int y=-1){
	rep(j,0,n){
		rep(i,0,n){
			if (j==y && i==x) cout << "@";
			else if (state & (1<<(i+5*j))) cout << "#";
			else cout << ".";
		}
		cout << endl;
	}
	cout << endl;
}

void DFS2(int state, int x, int y, queue<pii>& Q){
	if (x<0 || x==n || y<0 || y==n) return;
	if (state & (1<<(x+5*y))) return;
	int state2 = 0;
	state |= (1<< (x+5*y));
	rep(xx,0,n){
		rep(yy,0,n){
			int ct = 0;
			for (int dx :{-1, 0, 1}){
				for(int dy:{-1,0,1}){
					int xxx = xx+dx;
					int yyy = yy+dy;
					if (xxx>=0 && xxx<n && yyy>=0 && yyy<n) {
						if (state & (1 << (xxx + 5*yyy))) {
							ct++;
						}
					}
				}
			}
			// cout << ct << endl;
			if (state & (1<<(xx + 5*yy))){
				if (ct == 3 || ct == 4) state2 |= (1<< (xx + 5*yy));
			}else if (ct==3){
				state2 |= (1<<(xx + 5*yy));
			}
		}
	}
	// printstate(state2);
	state2 &= ~(1<<(x+5*y));

	if (S.count( (state2<<5) + (x+5*y))) return;
	S.insert((state2<<5) + (x+5*y));
	Q.push({state2, x+5*y});
	
	// return DFS(state2, x, y);
}

void DFS(int state, int x, int y, queue<pii>& Q){
	// printstate(state, x, y);
	// if (state==0) return 0;
	// if (S.count( (state)<<5 + (x+5*y))) return;

	// S.insert((state)<<5 + (x+5*y));
	
	int m = INF;
	for (int dx : {-1, 0, 1}){
		for(int dy:{-1,0,1}){
			if (dx==0&&dy==0) continue;
			DFS2(state, x+dx, y+dy, Q);
		}
	}
	// if (m < INF) printstate(state, x, y);
	// return m+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while(n){
		int state = 0;
		int x, y;
		rep(j,0,n){
			string a;
			cin >> a;
			rep(i,0,n){
				if (a[i]=='#') state |= (1<< (i+5*j));
				else if (a[i]=='@'){
					x = i, y=j;
				}
			}
		}
		S.clear();
		queue<pair<int, int>> Q;
		Q.push({state, x+5*y});
		S.insert((state<<5) + x+5*y);
		int dep = 0;
		bool win = 0;
		while(!win && !Q.empty()){
			int l = Q.size();
			rep(j,0,l){
				int state = Q.front().first;
				int pos = Q.front().second;
				// printstate(state, pos%5, pos/5);
				if (state==0){
					win = true;
					break;
				}
				DFS(state, pos%5, pos/5, Q);
				Q.pop();
			}
			dep++;
		}

		// int m = DFS(state, x, y);
		if (!win){
			dep = 0;
		}
		cout << dep-1 << endl;
		cin >> n;
	}
	
}