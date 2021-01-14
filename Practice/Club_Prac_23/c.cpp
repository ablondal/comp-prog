#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string S;

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		cin >> S;
		int n1=0, n0=0;
		for(auto s : S){
			if (s=='0') n0++;
			else n1++;
		}
		if ( min(n1, n0) % 2 == 0 ){
			printf("NET\n");
		}else{
			printf("DA\n");
		}
	}
}