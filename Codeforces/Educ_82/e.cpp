#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

typedef pair <int,int> pii;
bool solve(string s, string t){
	for(int x = 0; x<=t.size(); ++x){
		string a = t.substr(0,x);
		string b = t.substr(x,t.size());
		// cout << a << " " << b << endl;
		set <pii> possible;
		set <pii> new_poss;
		possible.insert({0,0});
		for(int i=0; i<s.size(); ++i){
			for(auto p=possible.begin(); p!=possible.end(); p++){
				bool used = false;
				int aa = p->first, bb = p->second;
				if ( aa<a.size() && s[i] == a[aa] ){
					used = true;
					new_poss.insert({aa+1,bb});
				}
				if ( bb<b.size() && s[i] == b[bb] ){
					used = true;
					new_poss.insert({aa,bb+1});
				}
				if (!used) new_poss.insert(*p);
			}
			possible.clear();
			possible = new_poss;
			new_poss.clear();
		}
		if ( possible.find({a.size(),b.size()}) != possible.end() )
			return true;
	}
	return false;
}




int main(){
	int t;
	cin >> t;
	while(t--){
		string s, t;
		cin >> s >> t;
		if (solve(s,t))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}