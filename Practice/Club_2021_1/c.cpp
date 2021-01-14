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
const int MAXN = 1e5+7;

ll e_song[MAXN];

int main() {
	int n,m;
	scanf("%d %d", &n, &m);
	ll time = 0;

	e_song[0] = 0;

	rep(i,1,n+1){
		ll c,t;
		scanf("%lld%lld", &c, &t);
		time += c*t;
		e_song[i] = time+1;
	}

	rep(i,0,m){
		int v;
		scanf("%d", &v);
		int lo=0,hi=n;
		while(hi-lo>1){
			int md = (hi+lo)/2;
			if (e_song[md]>v) hi = md;
			else lo = md;
		}
		printf("%d\n", lo+1);
	}

}