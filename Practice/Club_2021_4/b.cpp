#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// char s[100007];
// unordered_map<int, int> first;

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int n,k;
		scanf("%d%d", &n, &k);
		int lo = 0, hi = 1e9+7;
		vi holes(n);
		rep(i,0,n){
			scanf("%d", &holes[i]);
		}
		while(hi-lo>1){
			int mid = (hi+lo)/2;
			int i=0;
			rep(j,0,k){
				if(i<n){
					int last = holes[i]+mid;
					while(holes[i]<last && i<n) i++;
				}
			}
			if (i==n) hi = mid;
			else lo = mid;
		}
		printf("%d\n", hi);
	}	
}