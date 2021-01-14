#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[400][200] = {{0}};

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		vi t(n);
		rep(i,0,n) scanf("%d", &t[i]);
		
		int h = 1;
		queue<int> Q;
		int i=1;
		int l = 0;
		Q.push(t[0]);
		Q.push(-1);
		while(i<n){
			if (t[i]<l){
				Q.pop();
				if (Q.front()==-1){
					Q.pop();
					Q.push(-1);
					h++;
				}
				l = 0;
			}
			l = t[i];
			Q.push(t[i]);
			i++;
		}
		printf("%d\n", h);
	}
}