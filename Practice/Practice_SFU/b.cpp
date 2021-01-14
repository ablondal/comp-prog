#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int t;
	string S, T;
	scanf("%d", &t);
	getline(cin, S);
	while(t--){
		string S, T;
		getline(cin, S);
		getline(cin, T);
		// cin >> S >> T;
		int i=0;
		int ct = 0;
		rep(j,0,sz(S)){
			if (S[j]==T[i]){
				i++;
				i %= sz(T);
			}else{
				ct++;
			}
		}
		ct += i;
		printf("%d\n", ct);
	}
}