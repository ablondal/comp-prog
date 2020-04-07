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

// DONE

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
		// Now search for palindromes extending
		int l_pal=f;
		int r_pal=b;
		for(int i=f; i<=b; ++i){
			bool is_pal=true;
			for(int x=0; x<= (i-f)/2; ++x){
				if (s[f+x] != s[i-x]) is_pal = false;
			}
			if (is_pal) l_pal = i;
		}
		for(int i=b-1; i>f; --i){
			bool is_pal=true;
			for(int x=0; x<= (b-i)/2; ++x){
				if (s[b-x] != s[i+x]) is_pal = false;
			}
			if (is_pal) r_pal = i;
		}
		string ou = s.substr(0,f);
		if (b-r_pal > l_pal-f){
			ou += s.substr(r_pal, s.size());
		}else{
			ou = s.substr(0,l_pal+1);
			ou += s.substr(b+1, s.size());
		}
		cout << ou << endl;
	}
}





























