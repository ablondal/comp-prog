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
string T;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	cin >> S;
	cin >> T;
	int mm = 10000;
	vi mvec;
	for(int i=0; i<=m-n; ++i){
		int nn = 0;
		vi nvec;
		rep(j,0,n){
			if (S[j]!=T[i+j]){
				nn++;
				nvec.push_back(j);
			}
		}
		mm = min(mm, nn);
		if (mm==nn){
			mvec = nvec;
		}
	}
	printf("%d\n", mm);
	rep(i,0,sz(mvec)){
		if (i!=0){
			printf(" ");
		}
		printf("%d", mvec[i]+1);
	}
	printf("\n");
}