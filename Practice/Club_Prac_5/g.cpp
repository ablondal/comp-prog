#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

ll facm[1000007] = {0};

int main(){
	facm[0] = 1;
	for(int i=1; i<=1e6; ++i){
		facm[i] = (i * facm[i-1]);
		while(facm[i] % 10 == 0){
			facm[i] /= 10;
		}
		facm[i] %= 10000000;
	}
	int n;
	while(cin >> n){
		if (n==0) break;
		cout << facm[n] % 10 << endl;
	}
}
