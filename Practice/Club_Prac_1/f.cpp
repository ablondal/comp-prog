#include <iostream>
#include <vector>
using namespace std;

char Map[51][51] = {{0}};
bool V[51][51] = {{0}};

int d[4][2] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};

void DFS(int i, int j){
	if (V[i][j]) return;
	V[i][j] = true;
	if (Map[i][j] != 'L' && Map[i][j] != 'C' ) return;
	for(int k=0; k<4; ++k){
		int ni=i+d[k][0];
		int nj=j+d[k][1];
		if (ni>=0 && nj>=0) {
			DFS(ni, nj);
		}
	}
}

int main(){
	int r, c;
	cin >> r >> c;
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			cin >> Map[i][j];
		}
	}
	int n_times = 0;
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			if (!V[i][j] && Map[i][j]=='L'){
				n_times++;
				DFS(i,j);
			}
		}
	}
	cout << n_times << endl;
}









