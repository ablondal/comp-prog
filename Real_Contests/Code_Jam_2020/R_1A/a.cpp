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

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;


string solve(){
	int n;
	cin >> n;
	vector <string> S(n);
	for(int i=0; i<n; ++i){
		cin >> S[i];
	}
	// cout << n << endl;
	// for(int j=0; j<S.size(); ++j){
	// 	cout << S[j] << endl;
	// }
	string pre = "";
	string suf = "";
	string g = "";

	for(auto s: S){
		int f(101),l(0);
		for(int i=0; i<s.size(); ++i){
			if (s[i]=='*'){
				f = min(f,i);
				l = max(l,i);
			}
		}
		bool preworks = true, sufworks = true;
		// cout << "huh1" << endl;
		for(int i=0; i<min(pre.size(),f);++i){
			if (pre[i]!=s[i]){
				preworks = false;
			}
		}
		// cout << "huh2" << endl;
		for(int i=0; i<min(suf.size(), ((int)s.size())-l-1);++i){
			if (suf[suf.size()-1-i] != s[s.size()-1-i]){
				sufworks = false;
			}
		}
		// cout << "huh3" << endl;
		if (preworks && sufworks){
			if (suf.size() < ((int)s.size())-l-1){
				// cout << l << " " << s.size() << endl;
				suf = s.substr(l+1,s.size());
				
			}
			if (pre.size() < f){
				pre = s.substr(0,f);
				
			}
			s = s.substr(0,l);
			if(s.size() > f)
				s = s.substr(f+1,s.size());

			string f = "";
			for(auto c:s){
				if (c!='*'){
					f += c;
				}
			}
			g += f;

		}else{
			return "*";
		}
	}
	
	g = pre + g + suf;
	
	return g;
}


int main(){
	int T;
	cin >> T;
	for(int t=1;t<=T;++t){
		string a = solve();
		cout << "Case #" << t << ": " << a << endl;
	}
	return 0;
}



















