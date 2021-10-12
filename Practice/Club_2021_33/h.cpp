#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi pi(const string& s){
	vi p(sz(s));
	rep(i,1,sz(s)){
		int g = p[i-1];
		while (g && s[i] != s[g]) g=p[g-1];
		p[i] = g+(s[i]==s[g]);
	}
	return p;
}

int match(const string& s, const string& pat){
	vi p = pi(pat+'\0'+s);
	int res=0;
	rep(i, sz(p)-sz(s), sz(p))
		if (p[i]==sz(pat)) res++;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin >> n){
		if (n==0) break;
		vector<pair<int, string>> pats(n);
		rep(i,0,n){
			cin >> pats[i].second;
		}
		string s;
		cin >> s;
		rep(i,0,n){
			pats[i].first = match(s, pats[i].second);
		}
		stable_sort(all(pats));
		// vector<string> res;
		int l = sz(pats)-1;
		while(l>0 && pats[l-1].first == pats[sz(pats)-1].first) l--;
		cout << pats[sz(pats)-1].first << endl;
		rep(k, l, sz(pats)){
			cout << pats[k].second << endl;
		}
	}
}