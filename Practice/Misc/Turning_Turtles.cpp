#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int h, w;
vector<vector<char>> V;


int main() {
	
	scanf("%d%d", &h, &w);
	V.resize(h, vector<char>(w));
	rep(i,0,h){
		rep(j,0,w){
			scanf("%c", &V[i][j]);
		}
	}
}