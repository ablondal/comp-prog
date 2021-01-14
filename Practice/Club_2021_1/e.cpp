#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int F[307] = {0};
int p[307];
int newp[307];

int find(int v){
	return (F[v]==-1 ? v : F[v] = find(F[v]));
}

int main() {
	int n;
	scanf("%d", &n);
	rep(i, 0, n){
		F[i] = -1;
		scanf("%d", &p[i]);
	}
	rep(i,0,n){
		rep(j,0,n){
			char t;
			scanf(" %c", &t);
			if (t=='1' && find(i) != find(j)){
				F[find(i)] = find(j);
			}
		}
	}
	vector<int> locs[307];
	vector<int> nums[307];
	rep(i,0,n){
		locs[find(i)].push_back(i);
		nums[find(i)].push_back(p[i]);
	}
	rep(i,0,n){
		sort(all(nums[i]));
		sort(all(locs[i]));
		rep(j,0,sz(nums[i])){
			newp[locs[i][j]] = nums[i][j];
		}

	}
	rep(i,0,n){
		if(i) printf(" ");
		printf("%d", newp[i]);
	}
	printf("\n");
}