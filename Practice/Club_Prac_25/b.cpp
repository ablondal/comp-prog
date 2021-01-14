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
	char S[1024];
	scanf(" %s", S);
	int y = true;
	rep(i,0,t-1){
		if (S[i]!=S[i+1]) {
			S[i+2] = '\0';
			printf("YES\n%s\n", S+i);
			y = false;
			break;
		}
	}
	if (y) {
		printf("NO\n");
	}
}