#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// const long double pi = 3.141592653589793;
const int MAXN = 1e5+7;

char pkmn[MAXN];

int main() {
	int rec[128] = {0};
	rep(i,0,128) rec[i] = -1;
	set<char> seen;
	int n;
	scanf("%d", &n);
	scanf("%s", pkmn);
	int i1 = 0;

	rep(i,0,n){
		seen.insert(pkmn[i]);
	}
	int ss = 0;
	int m = MAXN;
	rep(i,0,n){
		if (rec[(int)pkmn[i]]==-1){
			
			ss++;
		}
		rec[(int)pkmn[i]] = i;
		while(rec[(int)pkmn[i1]]>i1){
			i1++;
		}
		if (ss == sz(seen)){
			m = min(m, i-i1+1);
		}
	}
	printf("%d\n", m);

}