#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char s[100007];
unordered_map<int, int> first;

int main() {
	int n;
	scanf("%d %s", &n, s);
	int M = 0;
	first[0] = -1;
	int sum = 0;
	rep(i,0,n){
		sum += s[i]=='1'? 1 : -1;
		if (first.count(sum)) {
			M = max(M, i - first[sum]);
		}else{
			first[sum] = i;
		}
	}

	printf("%d\n", M);
}