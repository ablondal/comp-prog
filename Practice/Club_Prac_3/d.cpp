#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)

typedef pair <int, int> pt;
typedef long long ll;

int DP[201][201];

int main(){
	for(int i=0; i<101; ++i){
		DP[i][0] = DP[0][i] = 0;
	}
	DP[1][1] = 0;
	for(int s=3; s<201; ++s){
		for(int i=1; i<s; ++i){
			int j = s-i;
			if (j>2 && i>2) {
				DP[i][j] = max(DP[i-2][j+1], DP[i+1][j-2]) + 1;
			} else if (j>2){
				DP[i][j] = 1+DP[i+1][j-2];
			} else if (i>2){
				DP[i][j] = 1+DP[i-2][j+1];
			} else {
				DP[i][j] = 1;
			}
		}
	}

	int a, b;
	cin >> a >> b;
	
	cout << DP[a][b] << endl;
}














