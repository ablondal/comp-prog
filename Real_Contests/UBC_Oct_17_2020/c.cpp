#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi adj[20001];
vi adj2[20001];

int lct[20001] = {0};

map<string, int> lang;
int li = 0;
int getlang(string s){
	if (lang.find(s) == lang.end()){
		lang[s] = li++;
		return lang[s];
	}
	return lang[s];
}

char V[20001];
char V2[20001];

void DFS(int v){
	if (V[v]) return;
	V[v] = true;
	for(auto e : adj[v]){
		DFS(e);
	}
}

void DFS2(int v){
	if (V2[v]) return;
	V2[v] = true;
	for(auto e : adj2[v]){
		DFS2(e);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	rep(i,0,t){
		string tmp;
		cin >> tmp;
		string sp;
		cin >> sp;
		// cout << sp;
		int me = getlang(sp);
		lct[me]++;
		while(cin.peek() != EOF && cin.peek() != '\n'){
			cin >> sp;
			int f = getlang(sp);
			adj[f].push_back(me);
			adj2[me].push_back(f);
			// printf("%d -> %d\n", f, me);
		}
	}
	int most = 0;
	rep(i,0,t){
		memset(V,0,20001);
		memset(V2,0,20001);
		DFS(i);
		DFS2(i);
		int m = 0;
		rep(j,0,t){
			if(V[j]&&V2[j]){
				m+=lct[j];
			}
		}
		// printf("%d %d\n", i, m);
		most = max(most, m);
	}

	printf("%d\n", t-most);

}


















