#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll GCD(ll a, ll b){
	if (a<b) return GCD(b, a);
	if (b == 0) return 0;
	return GCD(b, a%b) + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	rep(i, 0, t+1){
		rep(j,0,t+1){
			if (i==0) {
				printf("%02d ", j);
			} else if (j==0) {
				printf("%02d ", i);
			} else {
				int a = GCD(i,j);
				printf("\033[%dm%02d\033[0m ", a+30, a);
			}
		}
		printf("\n");
	}
}