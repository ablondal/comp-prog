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