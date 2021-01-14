#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int Q(int a){
	cout << "? 1 " << a << endl;
	int res;
	cin >> res;
	return res;
}

int Q(int a, int b){
	cout << "? 2 " << a << " " << b << endl;
	int res;
	cin >> res;
	return res;
}

int adj[51][51] = {{0}};

int ed[51];

int main() {
	int t;
	scanf("%d", &t);
	rep(i,1,t+1){
		ed[i] = Q(i);
	}
	rep(i,1,t){
		rep(j,i+1,t+1){
			int res = Q(i, j);
			if (res == ed[i]+ed[j]){
				adj[i][j] = adj[j][i] = 0;
			}else{
				adj[i][j] = adj[j][i] = 1;
			}
		}
	}
	cout << "!" << endl;
	rep(k,1,t+1){
		printf("%d",adj[k][1]);
		rep(i,2,t+1){
			printf(" %d", adj[k][i]);
		}
		printf("\n");
	}
}



















