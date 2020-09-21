#include <iostream>
#include <vector>

using namespace std;
#define MOD 1000000007

long long C[1000][1000];
long long pow2[1000];

int main(){
	C[0][0] = 1;
	for(int i=1; i<1000; ++i){
		for(int j=0; j<=i; ++j){
			if (j==0) {
				C[i][j] = 1;
			} else if (j==1){
				C[i][j] = i;
			}
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
		}
	}
	pow2[0] = 1;
	for(int i=1; i<1000; ++i){
		pow2[i] = (pow2[i-1]*2) % MOD;
	}
	int n, m, t;
	cin >> n >> m;
	vector <int> L(n,0);
	for(int i=0; i<m; ++i){
		cin >> t;
		L[t-1] = 1;
	}
	vector <int> blanks;
	int l = 0;
	for(int i=0; i<n; ++i){
		if (L[i]){
			if (i-l) {
				blanks.push_back(i-l);
			}
			l = i+1;
		}
	}
	if (n-l) {
		blanks.push_back(n-l);
	}

	long long N = 1;
	long long prevnums = 0;
	long long thisB;
	for(int i=0; i<blanks.size(); ++i){
		if (i==0 && L[0] == 0){
			prevnums += blanks[i];
			continue;
		}else if (i==blanks.size()-1 && L[n-1]==0) {
			prevnums += blanks[i];
			thisB = C[prevnums][blanks[i]];
			N *= thisB;
			N %= MOD;
		}else{
			thisB = pow2[blanks[i]-1];
			prevnums += blanks[i];
			thisB *= C[prevnums][blanks[i]];
			thisB %= MOD;
			N *= thisB;
			N %= MOD;
		}
	}
	cout << N << endl;


}










