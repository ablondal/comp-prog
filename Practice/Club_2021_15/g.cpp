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
	ll w, m;
	cin >> w >> m;
	ll ww = 1;
	vi curr;
	vi last;
	last.push_back(0);
	while(ww<m){
		ww *= w;
	}
	while(ww>0){
		for(auto a : last){
			if (a < m){
				if ( abs(a + ww - m) < abs(a-m) )
					curr.push_back(a + ww);
				else
					curr.push_back(a);
			}else{
				if ( abs(a - ww - m) < abs(a-m) )
					curr.push_back(a - ww);
				else
					curr.push_back(a);
			}
			// curr.push_back(a);
		}
		sort(all(curr));
		auto it = unique(all(curr));
		curr.resize(it-curr.begin());
		last.clear();
		swap(last, curr);
		ww /= w;
	}
	if (binary_search(all(last), m)){
		cout << "YES" << endl;
	}else{
		cout << "NO"<<endl;
	}
}