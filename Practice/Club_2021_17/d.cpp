#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int F[2507];

int f(int x){
	return (F[x] == x) ? x : F[x] = f(F[x]);
}

char iswall[2507];

char maze[57][57] = {{0}};

int num(int i, int j){
	return i*50 + j;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);	
	while(t--){
		memset(iswall, true, 2507);
		memset(maze, 0, 57*57);
		rep(i,0,2507) F[i] = i;
		int n, m;
		scanf("%d%d", &n, &m);
		rep(i,0,n){
			rep(j,0,m){
				scanf(" %c", &maze[i][j]);
			}
		}
		rep(i,0,n) rep(j,0,m){
			if (maze[i][j] == '.' || maze[i][j] == 'G'){
				if(i && maze[i-1][j]=='B') continue;
				if(j && maze[i][j-1]=='B') continue;
				if(maze[i+1][j]=='B') continue;
				if(maze[i][j+1]=='B') continue;
				iswall[num(i,j)] = false;
				if (i && !iswall[num(i-1,j)]) {
					int a = f(num(i-1,j));
					int b = f(num(i,j));
					if (a!=b) F[a] = b;
				}
				if (j && !iswall[num(i,j-1)]) {
					int a = f(num(i, j-1));
					int b = f(num(i,j));
					if (a!=b) F[a] = b;
				}
			}
		}
		int good = f(num(n-1,m-1));
		bool works = true;
		if (maze[n-1][m-1]=='B') works = false;
		rep(i,0,n) rep(j,0,m){
			if (maze[i][j] == 'G' && f(num(i,j)) != good) works = false;
		}
		printf(works ? "Yes\n" : "No\n");
	}
}