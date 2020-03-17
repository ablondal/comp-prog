#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// Correct algo, needed bigint
// so used python :P

typedef unsigned long long ll;
ll dep[50][50];
bool V[50] = {0};
int n;

void expand(int i){
	if (V[i]) return;
	for(int j=0; j<n; ++j){
		if (dep[i][j]){
			expand(j);
			for(int k=0; k<n; ++k){
				dep[i][k] += dep[i][j] * dep[j][k];
			}
		}
	}
	V[i] = true;
}

int main(){
	for(int i=0; i<50;++i)
		for(int j=0; j<50; ++j)
			dep[i][j] = 0;
	int m;
	cin >> n >> m;
	int req[n];
	for(int i=0; i<n; ++i){
		cin >> req[i];
	}
	ll newreq[50] = {0};
	
	int u,v,w;
	for(int i=0; i<m; ++i){
		cin >> u >> v >> w;
		dep[v][u] = w;
	}
	for(int i=0; i<n; ++i){
		expand(i);
		for(int j=0; j<n; ++j){
			newreq[j] += req[i] * dep[i][j];
		}
	}
	for(int i=0; i<n; ++i){
		if (i!=0) cout << " ";
		cout << newreq[i]+req[i];
	}
	cout << endl;
	cout << (ll)-1 << endl;
}











