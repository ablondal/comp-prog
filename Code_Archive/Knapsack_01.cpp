#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)

typedef pair <int, int> pt;
typedef long long ll;

ll DP[2007][2007] = {{0}};

ll W[2007];

ll V[2007];

int main(){
	int T;
	cin >> T;
	
	while (T--) {
		int C, N; // Capacity, number of items

		cin >> C >> N;

		for(int i=1; i<=N; ++i){
			cin >> W[i] >> V[i];
		}

		ll maxV = 0;

		for(int j=1; j<=N; ++j){
			for(int i=0; i<C; ++i){
				if (W[j] <= i){
					DP[i][j] = max(DP[i][j-1], DP[i-W[j]][j-1] + V[j]);
				}else{
					DP[i][j] = DP[i][j-1];
				}
				maxV = max(maxV, DP[i][j]);
			}
		}
		cout << maxV << endl;

	}
}














