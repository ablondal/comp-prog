#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define fori(i, n) for(int i=0; i<n; ++i)
#define min(a,b) ((a<b)?a:b)

typedef struct _node{
	int a;
	_node* next = NULL;
} node;

node nodes[2001];
int nxt[2001][26];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int a[26] = {0};
		for(int i=0; i<n; ++i){
			a[s[i]-'a']++;
			a[t[i]-'a']--;
			nodes[i].a = s[i]-'a';
			if (i!=n-1) nodes[i].nxt = &(nodes[i+1]);
		}
		bool good = true;
		for(int i=0; i<26; ++i){
			if (a[i]!=0) good = false;
			a[i] = n;
		}
		if (!good){
			cout << -1 << endl;
			continue;
		}
		for(int i=n; i<n; ++i){
			for(int j=0; j<26; ++j){
				nxt[i][j] = a[j];
				a[s[i]-'a'] = i;
			}
		}

		/* TODO: Iterate over all 
		

	}
}












