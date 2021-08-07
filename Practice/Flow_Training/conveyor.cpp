#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const long long MAXN = 90900+7;
const ll S = MAXN-2;
const ll T = MAXN-1;

int n, k, m;

vi adj[MAXN];
// char cap[MAXN][MAXN] = {{0}};
unordered_map<ll, int> cap;
char visited[MAXN];

int DFS(int n, int t){
	if (n==t) return 1;
	visited[n] = true;
	for(auto e: adj[n]){
		if (!visited[e] && cap[n*MAXN+e]>0) {
			int f = DFS(e, t);
			if (f) {
				cap[n*MAXN+e]--;
				cap[e*MAXN+n]++;
				return f;
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d%d%d", &n, &k, &m);
	rep(i,0,m){
		int a,b;
		scanf("%d%d", &a, &b);
		rep(j,0,k){
			adj[(k*a)+j].push_back((k*b) + ((j+1)%k));
			adj[(k*b) + ((j+1)%k)].push_back((k*a)+j);
			if (cap.find(((k*a)+j)*MAXN + (k*b) + ((j+1)%k)) == cap.end()){
				cap[((k*a)+j)*MAXN + (k*b) + ((j+1)%k)] = 0;
			}
			if (cap.find(((k*a)+j) + ((k*b) + ((j+1)%k))*MAXN ) == cap.end()){
				cap[((k*a)+j)*MAXN + ((k*b) + ((j+1)%k))*MAXN] = 0;
			}
			cap[((k*a)+j)*MAXN + (k*b) + ((j+1)%k)] += 1;
		}
	}
	rep(j,1,k+1){
		adj[S].push_back((k*j)+(j%k));
		cap[S*MAXN + (k*j) + (j%k)] = 1;
		adj[(k*n)+(j%k)].push_back(T);
		cap[ ((k*n)+(j%k))* MAXN + T] = 307;
	}
	int flow = 0;
	while(true){
		memset(visited, 0, MAXN);
		int f = DFS(S, T);
		if (f) flow++;
		else break;
	}
	printf("%d\n",flow);
}