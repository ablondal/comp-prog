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

int DFS(int a){
	if (ab.size() == 1 && *ab.begin() < a){
		ans.push_back({a, *ab.begin()});
		return a+ *ab.begin();
	}
	auto it1 = ab.begin();
	while(it1 != ab.end() && *it1 <= a){	
		int aa = *it1;
		auto it2 = ab.find(a + aa);
		if (it2 != ab.end()){
			ab.erase(it1);
			auto itr = ab.find(a + aa);
			ab.erase(itr);
			int xans = DFS(a+aa);
			if (xans){
				ans.push_back({aa, a});
				return xans;
			}
			ab.insert(a+aa);
			it1 = ab.insert(aa);
		}
		while(it1 != ab.end() && *it1==aa) it1++;
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
		}
		ans.clear();
		int xans = -1;
		auto itr = ab.begin();
		while(itr != ab.end()){
			int a = *itr;
			ab.erase(itr);
			xans = DFS(a);
			if (xans){
				break;
			}
			itr = ab.insert(a);
			while(itr != ab.end() && *itr == a)
				itr++;
		}
		if (ans.size()){
			cout << "YES" << endl;
			cout << xans << endl;
			for(int i=0; i<sz(ans); ++i){
				cout << ans[i].first << " " << ans[i].second << endl;
			}
		}else{
			cout << "NO" << endl;
		}
	}
}