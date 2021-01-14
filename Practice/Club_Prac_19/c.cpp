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

int main() {
	int t;
	scanf("%d", &t);
	if (t==1){
		printf("1\n1\n");
	}else if (t==2){
		printf("1\n1\n");
	}else if (t==3){
		printf("2\n1 3\n");
	}else{
		printf("%d\n", t);
		for(int i=2; i<=t; i+=2){
			printf("%d ", i);
		}
		for(int i=1; i<=t; i+=2){
			printf("%d", i);
			if (i>=t-1){
				printf("\n");
			}else
				printf(" ");
		}
	}
}