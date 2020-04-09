#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <set>
#include <cassert>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE, involves a "fun" perfect matcher

void printSQ(int SQ[101][101], int n){
	for(int y=1; y<=n; ++y){
		for(int x=1; x<=n; ++x){
			if (x!=1) cout << " ";
			cout << SQ[x][y];
		}
		cout << endl;
	}
}

//bool C[101][101];

set <int> C[101];

bool assigner(int x, int n, vector <bool> &open, vector<int> &M){
	for(auto it = C[x].begin(); it!=C[x].end(); ++it){
		if (!M[*it] && open[*it]){
			M[*it] = x;
			return true;
		}
	}

	for(auto it = C[x].begin(); it!=C[x].end(); ++it){
		int i = *it;
		if(open[i]){
			open[i] = false;
			if (assigner(M[i],n,open,M)){
				M[i] = x;
				return true;
			}
			// open[i] = true;
		}
	}
	return false;
}

bool perfectMatch(int n, vector<int> &M){
	M.clear();
	M.resize(n+1,0);
	for(int x=1; x<=n; ++x){
		//cout << x << endl;
		vector <bool> open(n+1,true);
		if ( ! assigner(x, n, open, M) ){
			return false;
		}
	}
	//cout << endl;
	for(int i=1; i<=n; ++i){
		C[M[i]].erase(i);
	}
	return true;
}

int main(){
	int n,k;
	cin >> n >> k;
	
	for(int i=0; i<101; ++i){
		for(int j=1; j<=n; ++j){
			C[i].insert(j);
		}
	}

	bool R[101];
	int SQ[101][101] = {{0}};
	int y, t;
	bool Y = true;

	for(y=1; y<=k; ++y){
		for(int i=1;i<=n;++i){R[i] = false;}
		for(int x=1; x<=n; ++x){
			cin >> t;
			assert( 1 <= t && t <= n);
			SQ[x][y] = t;
			if ( ! C[x].erase(t))
				Y = false;
			if (R[t])
				Y = false;
			R[t] = true;
		}
	}

	if (!Y){
		cout << "no" << endl;
		return 0;
	}
	
	vector <int> M;
	for(; y<=n && Y; ++y){
		//cout << "Matching row " << y << endl;
		if ( ! perfectMatch(n, M) ){
			Y = false;
		}else{
			for(int i=1; i<=n; ++i){
				SQ[M[i]][y] = i;
			}
		}
	}


	if (!Y){
		cout << "no" << endl;
		//printSQ(SQ,n);
		return 0;
	}

	cout << "yes" << endl;
	printSQ(SQ,n);

}






