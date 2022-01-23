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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	vector<pair<pair<int, int>, int>> cards;
	int tcost = 0;
	rep(i,1,t+1){
		int c, r;
		cin >> c >> r;
		cards.push_back({{c,r},i});
		if (i==t){
			tcost = c;
		}
	}
	sort(all(cards));
	vi c(t), r(t), n(t);
	c[0] = cards[0].first.first;
	r[0] = cards[0].first.second;
	n[0] = cards[0].second;
	rep(i,1,sz(cards)){
		c[i] = cards[i].first.first;
		if (cards[i].first.second >= r[i-1]) {
			r[i] = cards[i].first.second;
			n[i] = cards[i].second;
		} else {
			r[i] = r[i-1];
			n[i] = n[i-1];
		}
	}

	int i=0;
	vi choices;
	int res = 1;
	while(res < tcost){
		while(i<t && c[i]<=res) i++;
		if (i==0 || r[i-1]<=res){
			res = -1;
			break;
		}
		res = r[i-1];
		choices.push_back(n[i-1]);
	}
	if (res == -1) {
		cout << "No such luck" << endl;
	} else {
		choices.push_back(t);
		cout << choices.size() << endl;
		rep(i,0,sz(choices)){
			cout << choices[i];
			if (i!=sz(choices)-1) {
				cout << " ";
			}
		}
		cout << endl;
	}

}