#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int D = 32;

double negpow2[D+7];

pair<double, int> place_with_cost(vector<pair<int, ll>>& areas, double c) {
	int last = -1e9;
	double tottot = 0;
	int k = 0;
	double last_tot = 0;
	for(int i=0; i<areas.size(); ++i){
		double curr_bonus = 0;
		int j=i;
		while(j >= 0){
			int dist = abs(areas[j].second - areas[i].second);
			int d2 = abs(areas[j].second - last);
			if (dist > D || dist >= d2) break;
			if (d2 <= D) {
				curr_bonus -= areas[j].first * negpow2[d2];
			}
			curr_bonus += areas[j].first * negpow2[dist];
			--j;
		}
		j=i+1;
		while(j < areas.size()){
			int dist = abs(areas[j].second-areas[i].second);
			int d2 = abs(areas[j].second - last);
			if (dist > D) break;
			if (d2 <= D) {
				curr_bonus -= areas[j].first * negpow2[d2];
			}
			curr_bonus += areas[j].first * negpow2[dist];
			++j;
		}
		if (curr_bonus > c) {
			if (curr_bonus < last_tot) {
				last = areas[i-1].second;
				tottot += last_tot;
				k++;
				last_tot = 0;
			}else{
				last_tot = curr_bonus;
			}
		} else {
			if (last_tot) {
				last = areas[i-1].second;
				tottot += last_tot;
				k++;
			}
			last_tot = 0;
		}
	}
	if (last_tot > c) {
		tottot + last_tot;
		k++;
	}
	return {tottot, k};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	negpow2[0] = 1;
	rep(i,1,D+7){
		negpow2[i] = negpow2[i-1]/2.0;
	}
	int n, k;
	cin >> n >> k;
	vector<pair<int, ll>> areas(n);
	rep(i,0,n){
		cin >> areas[i].first >> areas[i].second;
	}
	double lo = 0, hi = 1e9;
	double ans = 0;
	while(true){
		double md = lo/2 + hi/2;
		auto res = place_with_cost(areas, md);
		// cout << md << " " << res.first << " " << res.second << endl;
		if (res.second < k){
			hi = md;
		}else if (res.second > k){
			lo = md;
		}else{
			ans = max(ans, res.first);
			break;
		}
	}
	cout << setprecision(12) << ans << endl;

}