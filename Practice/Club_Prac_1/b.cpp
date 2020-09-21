#include <iostream>
#include <set>
#include <vector>
#include <utility>
// #include <cmath>

using namespace std;

typedef pair<int, int> pt;

set <pt> hashed[2018][2018];

// unsigned int L[100001][2];

int hs[6][2] = {
	{2018,0}, {-2018,0},
	{1680, 1118}, {1680, -1118}, {-1680, 1118}, {-1680, -1118}
};


int main(){
	int n;
	cin >> n;
	int x, y;
	int hx, hy, dx, dy;
	int num = 0;
	for(int k=0; k<n; ++k){
		cin >> x >> y;
		hx = x % 2018;
		hy = y % 2018;
		dx = x / 2018;
		dy = y / 2018;

		for(int i=0; i<6; ++i){
			for(int j=0; j<2; ++j){
				int nx, ny, nhx, nhy, ndx, ndy;
				if (j==0) {nx = x + hs[i][0]; ny = y + hs[i][1];}
				else {nx = x + hs[i][1]; ny = y + hs[i][0];}
				if (nx < 0 || ny < 0) continue;
				nhx = nx % 2018;
				nhy = ny % 2018;
				ndx = nx / 2018;
				ndy = ny / 2018;
				num += hashed[nhx][nhy].count({ndx, ndy});
			}
		}
		
		hashed[hx][hy].insert({dx, dy});
	}
	cout << num << endl;
}










