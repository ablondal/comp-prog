#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll DP[100007] = {0};
int usedup[307] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	scanf("%d%d", &n, &k);
	vector<pair<int, ll>> j;
	rep(i,0,n){
		int a,b;
		scanf("%d%d", &a,&b);
		j.push_back({a,b});
	}
	sort(all(j), [](auto a, auto b){return a.second*b.first > a.first*b.second;});
	// reverse(all(j));
	bool used;
	int m = 0;
	rep(i, 0, n){
		if (usedup[j[i].first]) continue;
		used = false;
		for(int l = min(k-j[i].first, m); l>=0; --l){
			if (DP[l+j[i].first] < DP[l]+j[i].second){
				m = max(m, l+j[i].first);
				used = true;
				DP[l+j[i].first] = DP[l]+j[i].second;
			}
		}
		// rep(l,0,k+1) printf("%d %d: %lld\n", i, l, DP[l]);
		if (used==false) usedup[j[i].first] = true;
	}
	ll mm = 0;
	rep(i, 1, k+1){
		printf("%lld ", max(mm, DP[i]));
		mm = max(mm, DP[i]);
	}
	printf("\n");

}