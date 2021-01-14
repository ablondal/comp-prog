#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char s[100007], y[100007];

int main() {
	scanf(" %s %s", s, y);
	int diff = 0;
	for(int i=0; s[i]!=0; ++i){
		if (s[i]!=y[i]) diff++;
	}
	if (diff%2==1){
		printf("impossible\n");
	}else{
		for(int i=0; s[i]!=0; ++i){
			if (s[i]==y[i]){
				printf("%c", s[i]);
			}else{
				printf("%c", (diff%2==0 ? s[i]: y[i]));
				diff--;
			}
		}
		printf("\n");
	}
}