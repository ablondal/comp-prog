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
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,c,o,d,i;
	cin >> t >> c >> o >> d >> i;
	vector<int> dice;
	while(t--) dice.push_back(4);
	while(c--) dice.push_back(6);
	while(o--) dice.push_back(8);
	while(d--) dice.push_back(12);
	while(i--) dice.push_back(20);
	map<ll, ll> sums, sums2;
	sums[0] = 1;
	for(auto a: dice){
		sums2.clear();
		for(auto [s, amt]: sums){
			rep(i,1,a+1){
				sums2[s+i] += amt;
			}
		}
		swap(sums, sums2);
	}
	vector<pll> fin(all(sums));
	sort(all(fin), [](pll &a, pll &b){return a.second > b.second;});
	for(auto f: fin){
		cout << f.first << " " << f.second << endl;
	}
	for(auto f: fin){
		cout << f.first << " ";
	}
	cout << endl;
}