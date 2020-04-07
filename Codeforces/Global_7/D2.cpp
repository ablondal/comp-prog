#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

typedef vector <int> vi;
typedef long long ll;
typedef vector <ll> vll;

int main(){
	int t;
	for(cin >> t; t>0; --t){
		string s;
		cin >> s;
		int f=0,b=s.size()-1;
		while(f<s.size()/2 && s[f]==s[b]){
			f++;
			b--;
		}
		if (b <= f){
			cout << s << endl;
			continue;
		}
		// Now we search for palindromes from f onwards up to b
		vi af_f;
		int l_pal=f;
		int r_pal=b;
		for(int i=f; i<=b; ++i){
			if (s[i] == s[f]) af_f.push_back(i);
		}
		for(int j=af_f.size()-1; j>=0; --j){
			int i = af_f[j];
			bool isP = true;
			for(int x=1;x<=(i-f)/2; ++x){
				if (s[i-x]!=s[f+x]){
					isP = false;
					break;
				}
			}
			if (isP){
				l_pal = i+1;
				break;
			}
		}

		vi bf_b;
		for(int i=b; i>f; --i){
			if (s[i] == s[b]) bf_b.push_back(i);
		}
		for(int j=bf_b.size()-1; j>=0; --j){
			int i = bf_b[j];
			bool isP = true;
			for(int x=1;x<=(b-i)/2; ++x){
				if (s[i+x]!=s[b-x]){
					isP = false;
					break;
				}
			}
			if (isP){
				r_pal = i-1;
				break;
			}
		}

		string ou;
		if (b-r_pal > l_pal-f){
			ou = s.substr(0,f);
			ou += s.substr(r_pal+1, s.size());
		}else{
			ou = s.substr(0,l_pal);
			ou += s.substr(b+1, s.size());
		}
		cout << ou << endl;
	}
}





























