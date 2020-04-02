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
string isposs(string pwd){
	int nb[26] = {0};
	bool p[26] = {0};
	
	int a;
	int currpos = 0;
	int minpos = 0;
	int maxpos = 0;
	nb[pwd[0]-'a'] = 0;
	p[pwd[0]-'a'] = 1;
	string oup = "";
	oup += pwd[0];
	for(int i=1; i<pwd.size(); ++i){
		a = pwd[i] - 'a';
		if (!p[a]){
			if (currpos==maxpos){
				nb[a] = currpos+1;
				maxpos++;
				currpos++;
				p[a] = 1;
				oup = oup + pwd[i];
			}else if(currpos==minpos){
				nb[a] = currpos-1;
				minpos--;
				currpos--;
				p[a] = 1;
				oup = pwd[i] + oup;
			}else{
				// cout << i <<" "<< currpos << endl;
				return "";
			}
		}else{
			if (nb[a] == currpos+1){
				currpos++;
				continue;
			}else if (nb[a] == currpos-1){
				currpos--;
				continue;
			}else{
				// cout << i << " "<<currpos << endl;
				return "";
			}
		}
	}
	// string oup = "";
	// for(int i=minpos; i<=maxpos; ++i){
	// 	for(int j=0; j<26; ++j){
	// 		if (p[j] && nb[j]==i){
	// 			oup += (j+'a');
	// 		}
	// 	}
	// }
	for(int j=0; j<26; ++j){
		if (!p[j]){
			oup += (j+'a');
		}
	}
	return oup;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string inp;
		cin >> inp;
		string oup = isposs(inp);
		if (oup != ""){
			cout << "YES" << endl;
			cout << oup << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}