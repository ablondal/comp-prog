#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define max(a, b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define fori(i, n) for(ll i=0; i<n; ++i)
typedef long long ll;

ll n, d, a, x, h;
int main(){
	scanf("%lli%lli%lli", &n, &d, &a);
	d = 2*d;
	vector<pair<ll, ll> > mons, bombs;
	fori(i, n){
		scanf("%lli%lli", &x, &h);
		ll nh = h / a;
		if (h % a != 0) nh++;
		mons.emplace_back(x,nh);
	}
	sort(mons.begin(), mons.end());
	ll bi = 0;
	ll bt = 0;
	ll totB = 0;
	fori(i, n){
		while(bi<bombs.size() && mons[i].first - bombs[bi].first > d){
			bt -= bombs[bi].second;
			bi++;
		}
		mons[i].second -= bt;
		if (mons[i].second > 0){
			bombs.push_back({mons[i].first,mons[i].second});
			bt += mons[i].second;
			totB += mons[i].second;
		}
	}
	printf("%lli\n", totB);
}















