#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// o(n^2) solution :/

int main(){
	// set <int> D;
	map <int,int> M;

	int n;
	cin >> n;
	vector <int> P(n);
	vector <int> T(n);
	vector <int> Z(n);

	for(int i=0; i<n; ++i){
		cin >> T[i] >> P[i];
		Z[i] = i;
	}
	sort(Z.begin(),Z.end(),[&P](int a,int b){
		return P[a]>P[b];
	});
	// for(int i=0; i<n; ++i){
	// 	cout << Z[i] << endl;
	// }

	vector <bool> zas(2e6+1,false);
	int money = 0;

	for(int i=0; i<n; ++i){
		int j;
		for(j= T[ Z[i] ]; j>0 && zas[j]; --j){;}

		if (j>0){
			zas[j] = true;
			money += P[ Z[i] ];
		}
	}
	
	cout << money << endl;

	
}










