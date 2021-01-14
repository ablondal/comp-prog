#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[107][107] = {{0}}; // #odd, #even

int main() {
	rep(i,0,101){
		DP[i][0] = DP[0][i] = -1;
	}
	rep(i,1,101){
		rep(j,1,101){
			if(DP[i-1][j]==-1 || DP[i][j-1]==-1){
				DP[i][j] = 1;
			}else{
				DP[i][j] = -1;
			}
		}
	}
	int n;
	while(cin>>n){
			int o=0, e=0;
		int t;
		rep(i,0,n){
			scanf("%d", &t);
			if (t%2==0){
				e++;
			}else{
				o++;
			}
		}
		printf( (DP[o][e] == 1 ? "Simon wins!\n" : "Cedric wins!\n") );

	}

}