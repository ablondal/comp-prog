#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// const int MAXN = 2007;

int e;
vi adj[2507];
char vis[2507] = {0};

int main() {
	scanf("%d", &e);
	rep(i,0,e){
		int n;
		scanf("%d", &n);
		rep(j,0,n){
			int f;
			scanf("%d", &f);
			adj[i].push_back(f);
		}
	}
	int t;
	scanf("%d", &t);
	queue<int> Q;
	rep(i,0,t){
		int b;
		scanf("%d", &b);
		int M = 0;
		int day = -1;
		int d = 1;
		int curr = 0;
		memset(vis, false, 2507);
		while(!Q.empty()) Q.pop();
		for(auto e: adj[b]){
			Q.push(e);
			vis[e] = true;
		}
		Q.push(-1);
		
		vis[b] = true;
		while(true){
			// printf("%d %d\n", Q.front(), Q.size());
			if (Q.front() == -1){
				Q.pop();
				if (curr > M){
					M = curr;
					day = d;
				}
				d++;
				curr = 0;
				if (Q.empty()) break;
				Q.push(-1);
			}else{
				curr++;
				for(auto e: adj[Q.front()]){
					if (!vis[e]){
						vis[e] = true;
						Q.push(e);
					}
				}
				Q.pop();
			}
		}
		if (M == 0){
			printf("0\n");
		}else{
			printf("%d %d\n", M, day);
		}
	}
}



















