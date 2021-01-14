#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int n, a, b, c;
		char S[107] = {0};
		char B[107];
		scanf("%d%d%d%d", &n, &a, &b, &c);
		scanf(" %s", B);
		int win = 0;
		rep(i,0,n){
			if (B[i]=='R' && b) {
				win++;
				b--;
				S[i] = 'P';
			}else if (B[i]=='P' && c) {
				win++;
				c--;
				S[i] = 'S';
			}else if (B[i]=='S' && a) {
				win++;
				a--;
				S[i] = 'R';
			}
		}
		if (win*2 < n) {
			printf("NO\n");
			continue;
		}
		rep(i,0,n){
			if (!S[i]) {
				if (a) {
					S[i] = 'R';
					a--;
				}else if (b) {
					S[i] = 'P';
					b--;
				}else{
					S[i] = 'S';
					c--;
				}
			}
		}
		printf("YES\n%s\n", S);
	}
}