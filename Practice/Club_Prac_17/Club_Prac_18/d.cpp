#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string S, T;

int main() {
	int t;
	cin >> t;
	getline(cin, S);
	while(t--){
		getline(cin, S);
		getline(cin, T);
		if (sz(T)==0){
			printf("%d\n", sz(S));
			continue;
		}
		int is, it=0;
		int del = 0;
		for(is=0;is<sz(S);++is){
			if (S[is] == T[it]){
				it++;
				it %= sz(T);
			}else{
				del++;
			}
		}
		del += it;
		printf("%d\n", del);
	}
}