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

int c[1000007] = {0};
int cc[1000007] = {0};
vi dbs;

int choosecard(int& i, vi& omeg){
	while(i < sz(omeg) && cc[omeg[i]]){
		i++;
	}
	cc[omeg[i]] = 1;
	int card = omeg[i] / 2;
	c[card]++;
	if (c[card] == 2) {
		dbs.push_back(card);
	}
	return card;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int s0 = 0;
	int s1 = 0;
	vi omeg0(2*n);
	vi omeg1(2*n);
	int i0 = 0, i1 = 0;

	rep(i,0,2*n){
		cin >> omeg0[i];
	}
	rep(i,0,2*n){
		cin >> omeg1[i];
	}

	int a = 0;

	while(s0+s1 < n){
		while(!dbs.empty()){
			c[dbs.back()] -= 2;
			dbs.pop_back();
			if (a) s1++;
			else s0++;
		}
		if (a) {
			int card1 = choosecard(i1, omeg1);
			if (c[card1]==2) {
				c[card1] = 0;
				dbs.pop_back();
				s1++;
			} else {
				int card2 = choosecard(i1, omeg1);
				if (card1 == card2){
					c[card1] = 0;
					dbs.pop_back();
					s1++;
				} else {
					a = 0;
				}
			}
		} else {
			int card1 = choosecard(i0, omeg0);
			if (c[card1]==2) {
				c[card1] = 0;
				dbs.pop_back();
				s0++;
			} else {
				int card2 = choosecard(i0, omeg0);
				if (card1 == card2){
					c[card1] = 0;
					dbs.pop_back();
					s0++;
				} else {
					a = 1;
				}
			}
		}
	}

	if (s0 > s1) {
		cout << 0 << endl;
	} else if (s1 > s0) {
		cout << 1 << endl;
	} else{
		cout << -1 << endl;
	}


}