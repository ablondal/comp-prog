#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h, n;
	cin >> w >> h >> n;
	vector<long long> ans;
	set<int> xs, ys;
	xs.insert(0);
	xs.insert(w);
	ys.insert(0);
	ys.insert(h);
	priority_queue< pair<int, pair<int, int>> > Qx, Qy;
	Qy.push({h, {0, h}});
	Qx.push({w, {0, w}});
	rep(i,0,n){
		char c; int p;
		cin >> c >> p;
		if (c == 'H'){
			ys.insert(p);
			auto it = ys.find(p);
			auto it2 = it;
			it2--;
			Qy.push({p - *it2, {*it2, p}});
			it2++; it2++;
			Qy.push({*it2 - p, {p, *it2}});

			if (Qy.top().second.first < p && Qy.top().second.second > p){
				while(true){
					auto l = Qy.top().second;
					auto a = ys.find(l.first);
					auto b = ys.find(l.second);
					a++;
					if (a==b) break;
					else Qy.pop();
				}
			}
		}else{
			xs.insert(p);
			auto it = xs.find(p);
			auto it2 = it;
			it2--;
			Qx.push({p - *it2, {*it2, p}});
			it2++; it2++;
			Qx.push({*it2 - p, {p, *it2}});

			if (Qx.top().second.first < p && Qx.top().second.second > p){
				while(true){
					auto l = Qx.top().second;
					auto a = xs.find(l.first);
					auto b = xs.find(l.second);
					a++;
					if (a==b) break;
					else Qx.pop();
				}
			}
		}
		ans.push_back((ll)Qy.top().first*(ll)Qx.top().first);
	}
	for(auto e : ans){
		cout << e << endl;
	}
	// cout << endl;
}