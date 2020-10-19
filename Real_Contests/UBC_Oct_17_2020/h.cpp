#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char c[107][107];

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		string msg;
		cin >> msg;
		int n = ceil(sqrt(sz(msg)));
		rep(i,0,n*n){
			if (i<sz(msg)){
				c[i%n][i/n] = msg[i];
			}else{
				c[i%n][i/n] = 0;
			}
		}
		rep(i,0,n*n){
			if (c[i/n][n-(i%n)-1]){
				printf("%c",c[i/n][n-(i%n)-1] );
			}
		}
		printf("\n");
	}
}