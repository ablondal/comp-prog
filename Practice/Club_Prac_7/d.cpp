#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define max(a, b) ((a>b)?a:b)
#define fori(i, n) for(int i=0; i<n; ++i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;

const int MAXN = 1e5+3;
vpii G[MAXN];
int P[MAXN][33];
int m[MAXN][33] = {0};
int M[MAXN][33] = {0};

int n, a, b, c;
int main(){
	scanf("%d", &n);
	fori(i, n-1){
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}

}















