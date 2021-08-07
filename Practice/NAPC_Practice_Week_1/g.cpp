#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
12100212
i'm helping
done helping :)
-1, 3, 1
10110000
*/

inline void help(ll tot, int n_1s, int& l, int& r, int& z){
	cout << "i'm helping" << endl;
	int ctr = (tot/n_1s);
	l = ctr - (n_1s/2);
	r = ctr + ( (n_1s+1) /2);
	ll sum = (r + l) * (n_1s+1);
	z = (sum - tot*2) / 2;
	if (z==r) r--;
	cout << "done helping :)" << endl;
}

struct piii{
	int l, r, z;
};

int main(){
	string s;
	cin >> s;
	s += '0';
	string t(sz(s), '0');
	int i=0, j=0;
	ll tot = 0;
	int n_1s = 0;
	vector<piii> segs;
	vector<ll> runtot(sz(s),0);
	vector<int> run1s(sz(s),0);
	while(j<sz(s)){
		if (j){
			runtot[j] = runtot[j-1];
			run1s[j] = run1s[j-1];
		}
		runtot[j] += (s[j]-'0')*j;
		run1s[j] += (s[j]-'0');

		if (j && s[j] == '0' && s[j-1]!='0'){
			int l, r, z;
			ll tot = runtot[j]-(i ? runtot[i-1] : 0);
			ll n_1s = run1s[j]-(i ? run1s[i-1] : 0);
			help(tot, n_1s, l, r, z);
			while (segs.size() && segs.back().r >= l){
				tot += runtot[segs.back().r];
				tot -= (segs.back().l ? runtot[segs.back().l-1] : 0);
				n_1s += run1s[segs.back().r];
				n_1s -= (segs.back().l ? run1s[segs.back().l-1] : 0);
				
				segs.pop_back();

				help(tot, n_1s, l, r, z);
			}
			segs.push_back({l, r, z});
			i = j+1;
		}
		j++;
	}
	for(auto& seg:segs){
		cout << seg.l << ", " << seg.r << ", " << seg.z << endl;
		for(int i=max(0,seg.l); i<=min(sz(s)-1, seg.r); ++i){
			if (i!=seg.z) t[i] = '1';
			else t[i] = '0';
		}
	}
	cout << t.substr(0,sz(t)-1) << endl;
}