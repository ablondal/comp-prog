#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream in("people.in");
	ofstream out("people.out");
	
	int n;
	in >> n;
	vector<pair<pair<int, int>, int>> a(n);
	rep(i,0,n){
		in >> a[i].first.first >> a[i].first.second;
		a[i].second = i+1;
		a[i].first.second *= -1;
	}
	sort(all(a));
	vector<pii> b;
	rep(i,0,n){
		b.push_back({-a[i].first.second, a[i].second});
		// cout << b[i].first <<  " " << b[i].second << endl;
	}
	// DO LIS
	vi p(n+7);
	vector<pii> LIS(n+7);
	rep(i,0,n+7) LIS[i] = {2e9, -1};
	LIS[0] = {-1e9, -1};
	int ct = 1;
	rep(i,0,n){
		int hi = ct;
		int lo = 0;
		while(hi-lo > 1){
			// cout << hi << " " << lo << endl;
			int md = (hi+lo)/2;
			if (b[i].first > LIS[md].first) lo = md;
			else hi = md;
		}

		p[b[i].second] = LIS[lo].second;
		LIS[lo+1] = b[i];
		if (lo == ct-1) {
			ct++;
		}
		// rep(j,0,ct){
		// 	cout << LIS[j].first << " " << LIS[j].second << endl;	
		// }
	}
	vi ans;
	int f = LIS[ct-1].second;
	while(f != -1){
		ans.push_back(f);
		f = p[f];
	}
	out << sz(ans) << endl;
	for(auto & e : ans){
		out << e << " ";
	}
	out << endl;


}