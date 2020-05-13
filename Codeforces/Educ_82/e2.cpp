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

// DONE :D

bool solve(string s, string t){
	int nxt[s.size()+1][26];
	int last[26];
	for (auto &l : last){
		l = -1;
	}
	for(int i=s.size(); i>=0; --i){
		for(int j=0; j<26; ++j){
			nxt[i][j] = last[j];
		}
		if (i!=0)
			last[s[i-1]-'a'] = i;
	}
	// for(int i=0; i<=s.size(); ++i){
	// 	for(int j=0; j<26; ++j){
	// 		cout << nxt[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// if you can choose starting from x, nxt[x][a] is the first appearance of a
	for (int asize=0; asize<t.size(); asize++){
		string aa = t.substr(0,asize);
		string bb = t.substr(asize,t.size());
		int x = aa.size();
		int y = bb.size();
		vector <int> a(x), b(y);
		for (int i=0; i<x; ++i) a[i] = aa[i]-'a';
		for (int i=0; i<y; ++i) b[i] = bb[i]-'a';
		int DP[x+1][y+1];
		for(int i=0; i<=x; ++i){
			for(int j=0; j<=y; ++j){
				if (i==0 && j==0){
					DP[i][j] = 0;
					continue;
				}
				int o1, o2;
				if (i==0 || DP[i-1][j]==-1){
					o1 = -1;
				}else{
					o1 = nxt[DP[i-1][j]][a[i-1]];
				}

				if (j==0 || DP[i][j-1]==-1){
					o2 = -1;
				}else{
					o2 = nxt[DP[i][j-1]][b[j-1]];
				}

				if (o1==-1 && o2==-1){
					DP[i][j] = -1;
				}else if(o1==-1){
					DP[i][j] = o2;
				}else if(o2==-1){
					DP[i][j] = o1;
				}else{
					DP[i][j] = min(o1,o2);
				}
			}
		}
		if (DP[x][y]!=-1){
			// for(int i=0;i<=x;++i){
			// 	for(int j=0;j<=y;++j){
			// 		cout << DP[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }
			return true;
		}
	}
	return 0;
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