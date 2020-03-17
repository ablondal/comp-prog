#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

int main(){
	int k, v;
	cin >> k >> v;
	int k_2 = 1<<k;
	vector <double> p[v];
	for(int i=0; i<v; ++i){
		p[i].resize(k_2,0);
	}
	p[0][0] = 1;
	for(int i=1; i<v; ++i){
		double pp;
		int b;
		cin >> pp >> b;
		for(int j=0; j< (1<<k); ++j){
			p[i][ (j+b) & ( (1<<k)-1 ) ] += p[i-1][j]*pp;
			p[i][j] += p[i-1][j] * (1-pp);
		}
	}
	double prob[k];
	for(int i=0; i<k; ++i) prob[i] = 0;
	
	for(int j=0; j< (1<<k); ++j){
		cout << j << ": " << p[v-1][j] << endl;
		for(int i=0; i<k; ++i){
			if ( (j >> i) & 1 ){
				prob[i] += p[v-1][j];
			}
		}
	}

	int ans = 0;
	for(int j=0; j<k; ++j){
		cout <<j << ": "<< prob[j] << endl;
		if (prob[j] < 0.5){
			ans = ans | ( 1 << j );
		}
	}

	cout << ans << endl;

}