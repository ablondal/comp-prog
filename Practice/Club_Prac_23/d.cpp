#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// const int MAXN = 2e5+7;
int T[(int)2e5+7];

int main() {
	int n, k;
	priority_queue<int, vi, greater<int> > Q;
	scanf("%d%d", &n, &k);
	int l = -1;
	rep(i,0,n){
		scanf("%d", T+i);
		if (T[i]<0) T[i]=-1;
		else T[i]=0;
		if (l<0 && T[i]) l = i;
	}
	if (l==-1) {
		printf("0\n");
		return 0;
	}
	int sp = 0;
	int sw = 1;
	rep(i,l,n){
		int t = T[i];
		if (t<0) {
			if (sp){ Q.push(sp); sw++; }
			sp=0;
			k--;
		}else{
			if (sp==0) sw++;
			sp++;
		}
		// printf("%d %d %d\n", i, sp, sw);
	}
	int k1 = k;
	int sw1 = sw;
	if (sp) {
		k1 = k-sp;
		if(k1>=0)
			sw1--;
	}
	if (k<0){
		printf("-1\n");
		return 0;
	}
	while(!Q.empty() && k>=Q.top()){
		k -= Q.top();
		if (k1>=Q.top()){
			k1-=Q.top();
			sw1 -= 2;
		}
		Q.pop();
		sw-=2;
	}
	printf("%d\n", min(sw, sw1));
}