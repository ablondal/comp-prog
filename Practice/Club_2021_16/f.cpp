#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;

char used[2007] = {0};
// int a[2007];
multiset<int> ab;
int nn;

vector<pair<int, int>> ans;

bool DFS(int x, int lef){
	if (lef==0) return true;
	auto lo = ab.begin(), hi = ab.end();
	// auto it = ab.end();
	hi--;
	int biggst = *hi;
	while(lo!=hi){
		// while(lo!=hi) lo++;
		// while(lo!=hi && used[hi]) hi--;
		
		// if (hi<=lo) break;

		if (*hi+*lo < x){
			lo++;
		}else if (*hi+*lo > x){
			hi--;
		}else{
			int a = *lo;
			int b = *hi;
			ab.erase(hi);
			auto itr = ab.find(a);
			ab.erase(itr);
			// used[lo] = used[hi] = true;
			if (DFS(b, lef-2)){
				ans.push_back({a,b});
				return true;
			}
			lo = ab.insert(a);
			hi = ab.insert(b);
			// used[lo] = used[hi] = false;
			lo++;
			if (hi==lo) break;
			hi--;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		nn = 2*n;
		ab.clear();
		rep(i,0,2*n){
			int tmp;
			cin >> tmp;
			ab.insert(tmp);
			// cin >> a[i];
			// used[i] = 0;
		}
		// sort(a, a+2*n);
		
		auto it = ab.end();
		it--;
		int biggst = *it;

		set<int> xs;
		for(auto it1 = ab.begin(); it1!=ab.end(); ++it1){
			for(auto it2 = ab.begin(); it2!=it1; ++it2){
				if (*it1+*it2 > biggst) xs.insert(*it1+*it2);
			}
		}
		ans.clear();
		int xans = -1;
		for(auto x : xs){
			// cout << x << endl;
			if (DFS(x, nn)){
				xans = x;
				break;
			}
		}
		if (ans.size()){
			cout << "YES" << endl;
			cout << xans << endl;
			for(int i=sz(ans)-1; i>=0; --i){
				cout << ans[i].first << " " << ans[i].second << endl;
			}
		}else{
			cout << "NO" << endl;
		}
	}
}