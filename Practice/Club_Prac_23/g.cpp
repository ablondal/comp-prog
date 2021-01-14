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
// dones
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string S;
string T;

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		cin >> S;
		int mm = 102948;
		rep(i,0,n){
			if (S[i]=='>'){
				mm = i;
				break;
			}
		}
		for(int i=sz(S)-1; i>=0; --i){
			if (S[i]=='<'){
				mm = min(mm, sz(S)-1-i);
				break;
			}
		}
		printf("%d\n", mm);
	}
}