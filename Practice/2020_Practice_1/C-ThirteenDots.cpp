#include <iostream>
#include <vector>

#define max(a,b) (a>b)?a:b

using namespace std;

vector <vector <int> > DP;
vector <int> v, c;



int main(){
	int m, n;
	bool extra;
	while (cin >> m >> n){
		if (m > 1800) extra = true;
		else extra = false;

		DP.clear();
		DP.resize(1+m+200*extra, vector<int>(n,0));
		v.resize(n);
		c.resize(n);

		//cout << DP.size() << " " << DP[0].size() << DP[0][0] <<  " "  << endl;

		for(int i=0; i<n; ++i){
			cin >> c[i] >> v[i];
		}
		if(c[0] <= m+200*extra)
			DP[c[0]][0] = v[0];

		for(int i=1; i<n; ++i){
			for(int j=0; j<=m+200*extra; ++j){
				if( j<c[i] )
					DP[j][i] = DP[j][i-1];
				else
					DP[j][i] = max( DP[j][i-1], DP[ j-c[i] ][i-1] + v[i] );
			}
		}

		int r, maxx=0;
		for(r=m+200*extra; r>=0; --r){
			if (DP[r][n-1] > maxx && (r>2000 || r<=m))
			{
				maxx = DP[r][n-1];
			}
		}

		cout << maxx << endl;

	}
}