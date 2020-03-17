#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

double PD[101][17]; // Prob Distribution of 1
double p[101];
int b[101];

int main(){
	for(int i=0; i<101; ++i){

		for(int j=0; j<17; ++j){
			PD[i][j] = 0;
		}
	}

	int k, vt;
	cin >> k >> vt;
	vt--;


	for(int v=1; v<=vt; ++v){

		cin >> p[v] >> b[v];
	}


	for(int v=1; v<=vt; ++v){
		double carry = 0;
		for(int j=0; j<k; ++j){
			if ( ( b[v] >> j ) & 1 ){
				PD[v][j] = ( 1 - PD[v-1][j] )*p[v]* (1-carry);
				carry = carry * (PD[v-1][j] + p[v]) + PD[v-1][j]*p[v];
			}else{
				PD[v][j] = PD[v-1][j]* (1-carry);
				carry = carry * (PD[v-1][j]);
			}
		}
	}

	int ans = 0;
	for(int j=0; j<k; ++j){
		cout << PD[vt][j] << endl;
		if (PD[vt][j] < 0.5){

			ans = ans | ( 1 << j );
		}
	}

	cout << ans << endl;
		
	

}












