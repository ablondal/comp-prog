#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi adj[3000];

char cap[3000][3000] = {{0}};
char V[3000];

int s, r, f, t;

map<string, int> state;

bool DFS(int s, int t){
	if (s == t){
		return true;
	}
	V[s] = true;
	for(auto e: adj[s]){
		if (!V[e] && cap[s][e]){
			if (DFS(e, t)){
				cap[e][s] = 1;
				cap[s][e] = 0;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int s, r, f, t;
	cin >> s >> r >> f >> t;
	// scanf("%d %d %d %d", &s, &r, &f, &t);
	rep(i,2,r+2){
		string a;
		cin >> a;
		state[a] = i;
		adj[0].push_back(i);
		cap[0][i] = 1;
	}
	rep(i,r+2,r+f+2){
		string a;
		cin >> a;
		state[a] = i;
		adj[i].push_back(1);
		cap[i][1] = 1;
	}
	int n_s = r+f+2;
	rep(i,s+2, t+s+2){
		adj[i].push_back(i+t);
		adj[i+t].push_back(i);
		cap[i][i+t] = 1;
		int n;
		cin >> n;
		rep(j,0,n){
			string a;
			cin >> a;
			if (state.find(a) == state.end()){
				state[a] = n_s++;
			}
			int p = state[a];
			adj[p].push_back(i);
			adj[i].push_back(p);
			adj[i+t].push_back(p);
			adj[p].push_back(i+t);
			cap[p][i] = 1;
			cap[i+t][p] = 1;
		}
	}

	int tot = 0;
	memset(V, false, 3000);
	while(DFS(0, 1)){
		tot++;
		memset(V, false, 3000);
	}
	printf("%d\n", tot);
		
}



















