#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", a*b);
	for(int j = a*(b-1); j>=0; j -= a){
		for(int i=1; i<=a; ++i){
			printf("%d ", i+j);
		}
	}
	printf("\n");
}