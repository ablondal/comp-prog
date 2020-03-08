#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Done! This works excellently

typedef struct pt{
	double x=0;
	double y=0;
}Pt;

double dist(Pt &a, Pt &b){
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}


int main(){
	int n, b1, b2;
	int CC = 0;
	while(true){
		CC++;
		cin >> n >> b1 >> b2;
		if (n==0)
			break;

		vector <Pt> I(n);
		for(int i=0; i<n; ++i){
			cin >> I[i].x >> I[i].y;
		}
		double DP[n][n];
		int P[n][n];
		double d[n][n];
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				d[i][j] = dist(I[i],I[j]);
				DP[i][j] = 1e9;
			}
		}
		// two ns are the leading islands
		// We'll do this twice, and swap b1 and b2 for the second
		
		DP[0][0] = 0;
		if (b2 != 1)
			DP[1][0] = d[1][0];
			P[1][0] = 0;
		if (b1 != 1)
			DP[0][1] = d[1][0];
			P[0][1] = 0;
		
		P[0][0] = -1;
		for(int k = 2; k<n; ++k){
			for(int j=0;j<k-1;++j){
				if(k!=b2){
					if (DP[k-1][j]+d[k-1][k] < DP[k][j]){
						DP[k][j] = DP[k-1][j]+d[k-1][k];
						P[k][j] = k-1;
					}
					if (DP[j][k-1]+d[j][k] < DP[k][k-1]){
						DP[k][k-1] = DP[j][k-1]+d[j][k];
						P[k][k-1] = j;
					}
				}
				if(k!=b1){
					if (DP[k-1][j]+d[j][k] < DP[k-1][k]){
						DP[k-1][k] = DP[k-1][j]+d[j][k];
						P[k-1][k] = j;
					}
					if (DP[j][k-1]+d[k-1][k] < DP[j][k]){
						DP[j][k] = DP[j][k-1]+d[k-1][k];
						P[j][k] = k-1;
					}
				}
			}
		}
		double mindist = 1e9;
		int a,b;
		for(int i=0;i<n-1;++i){
			if (DP[n-1][i]+d[i][n-1] < mindist){
				mindist=DP[n-1][i]+d[i][n-1];
				a = n-1;
				b = i;
			}
			if (DP[i][n-1]+d[i][n-1] < mindist){
				mindist=DP[i][n-1]+d[i][n-1];
				a = i;
				b = n-1;
			}
		}
		printf("Case %d: %0.2f\n", CC, mindist);
		//cout << "Case " << CC << ": " << setprecision(2) << mindist << endl;
		vector <int> path1;
		vector <int> path2;
		while(a!=0 || b!=0){
			if (a > b){
				path1.push_back(a);
				a = P[a][b];
			}else{
				path2.push_back(b);
				b = P[a][b];
			}
		}
	
		if(path2[path2.size()-1]==1){
			printf("0 ");
			for(int i=path2.size()-1; i>=0; --i){
				printf("%d ", path2[i]);
			}
			for(int i=0; i<path1.size(); ++i){
				printf("%d ", path1[i]);
			}
			printf("0\n");
		}else{
			printf("0 ");
			for(int i=path1.size()-1; i>=0; --i){
				printf("%d ", path1[i]);
			}
			for(int i=0; i<path2.size(); ++i){
				printf("%d ", path2[i]);
			}
			printf("0\n");
		}
	}
}











