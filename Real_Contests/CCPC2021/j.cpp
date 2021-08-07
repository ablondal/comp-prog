#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<unordered_map>
#include<utility>
#include<string>
#include<cmath>
#include<queue>
#include<algorithm>

#include<stdlib.h>
#include<string.h>

using namespace std;
typedef unsigned long long ll;
const ll MAXBIT = 9223372036854775808;

// queue<pair<long ,long> > query;
vector<ll> ans;

ll make_query(ll l, ll r){
	if (r < l+1) return 0;
	cout << "q " << l << " " << r-1 << endl;
	ll a;
	cin >> a;
	return a;
}
// Check in [left, right)
void query_recur(ll left, ll right, ll num_father) {
	// cout << right << endl;
	if (right == left) return;
	ll mid = (left>>1) + (right>>1) + (left & 1 & right);

	ll a = make_query(left, mid);
	// ll b = make_query(mid, right);

	// printf("q %lld %lld", left, mid);
	// cout<<flush;

	// ll num_left;
	// scanf("%lld", &num_left);

	if (a == mid - left) {
		for (ll i = left; i < mid; ++i)
			ans.push_back(i);
	} else if (a > 0) {
		query_recur(left, mid, a);
	}

	ll b = num_father - a;
	if (b == right - mid) {
		for (ll i = mid; i < right; ++i)
			ans.push_back(i);
	}
	else if (b > 0) {
		query_recur(mid, right, b);
	}
}

int main(void) {
	// printf("q %lld %lld", (ll)(0), MAXBIT);
	// cout<<flush;

	ll num_total = make_query(0, MAXBIT);
	// scanf("%lld", &num_total);

	query_recur(0, MAXBIT, num_total);

	sort(ans.begin(), ans.end());

	cout << "a " << num_total;
	for(int i=0; i<ans.size(); ++i){
		cout << " " << ans[i];
	}
	cout << endl;
	// printf("a %llu", num_total);
	// for (int i = 0; i < num_total; ++i)
	// 	printf(" %llu", ans[i]);
	// printf("\n");
	return 0;
}