#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
// DONE
int main(){
	int t;
	cin >> t;
	while(t--){
		string inp;
		cin >> inp;
		int ones = 0;
		int first = 1000;
		int last = 0;
		for(int i=0; i<inp.size(); ++i){
			if(inp[i]=='1'){
				first = min(first,i);
				last = max(last,i);
				ones++;
			}
		}
		if(first==1000) cout << "0" << endl;
		else cout << inp.size()-ones-first - (inp.size()-1-last) << endl;
	}
}