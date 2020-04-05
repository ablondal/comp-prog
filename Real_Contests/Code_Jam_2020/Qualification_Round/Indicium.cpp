#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
typedef vector<int> vi;
typedef vector<vi> vvi;

int gcd(int a, int b){
	if (a==0) return b;
	return (b%a, a);
}

int main(){
	int T;
	cin >> T;
	for(int t=1; t<=T; ++t){
		int N, K;
		cin >> N >> K;
		cout << "Case #" << t << ": ";
		if(K<N || K>N*N){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		if( gcd(K,N)==1 ){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		int n = K / N;
		cout << "POSSIBLE" << endl;
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				cout << (i+j+n)%N + 1;
				if (j!=N-1) cout << " ";
			}
			cout << endl;
		}
	}
}