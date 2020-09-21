#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define fori(i, n) for(int i=0; i<n; ++i)
#define min(a,b) ((a<b)?a:b)


int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector <int> num0s(s.size()), num1s(s.size()), n0rev(s.size()), n1rev(s.size());
		int m = 1e9;
		int z=0, o=0;
		fori(i, s.size()){
			num0s[i] = o;
			num1s[i] = z;
			if (s[i]=='0'){
				z++;
			}else{
				o++;
			}
		}
		z=0, o=0;
		for(int i=s.size()-1; i>=0; i--){
			n0rev[i] = o;
			n1rev[i] = z;
			if (s[i]=='0'){
				z++;
			}else{
				o++;
			}
		}
		for(int i=0; i<s.size(); ++i){
			m = min(m, num1s[i]+n0rev[i]);
			m = min(m, num0s[i]+n1rev[i]);
		}
		cout << m << endl;
	}
}
















