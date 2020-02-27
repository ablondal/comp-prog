#include <vector>
#include <iostream>
using namespace std;
#define min(a,b) (a<b)?a:b
// Done
int DP[501][100];
int v[100];
int c[100];

int main(){
	int m, n;
	bool extra;
	while (cin >> m >> n){

		if (n==0){
			cout << "0" << endl;
			continue;
		}

		for(int i=0; i<501; ++i){
			for(int j=0; j<100; ++j){
				if(i==0) DP[i][j] = 0;
				else DP[i][j] = 1e8;
			}
		}
		for(int i=0; i<n; ++i){
			cin >> c[i] >> v[i];
		}
		DP[v[0]][0] = c[0];
		for(int i=1; i<100; ++i){
			for(int val=1; val < 501; ++val){
				if(val >= v[i]){
					DP[val][i] = min(DP[val][i-1], DP[val-v[i]][i-1] + c[i]);
				}else{
					DP[val][i] = DP[val][i-1];
				}
			}
		}

		int maxval = 0;
		for(int val=1; val < 501; ++val){
			if(val <= maxval) continue;
			int cc = DP[val][n-1];
			if ( (cc > 2000 && cc <= m+200) || (cc <= m) ){
				maxval = val;
			}
		}
		cout << maxval << endl;
	}
}






