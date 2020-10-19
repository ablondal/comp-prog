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
typedef vector<ll> vi;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while(n || m){
		vi knit(m);
		vi head(n);
		rep(i,0,n) cin >> head[i];
		rep(i,0,m) cin >> knit[i];
		sort(all(head));
		sort(all(knit));
		if (head[n-1] > knit[m-1]){
			printf("Loowater is doomed!\n");
		}else{
			int ki = 0;
			ll tot = 0;
			bool ye = true;
			rep(i,0,n){
				if (ki >= m){
					ye = false;
					break;
				}
				while(knit[ki]<head[i]) ki++;
				tot+=knit[ki];
				ki++;
			}
			if (ye)
				printf("%lli\n", tot);
			else
				printf("Loowater is doomed!\n");
		}

		scanf("%d%d", &n, &m);
	}
}