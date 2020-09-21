#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <unordered_set>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a[11];
int b[11];
int ai, bi, at=0, bt=0;

ll get_num(){
	ll tot = 0;
	for(int i=at; i!=ai; i = (i+1)%11){
		tot *= 11;
		tot += a[i];
		tot %= (ll)1e18;
	}
	tot *= 11;
	for(int i=bt; i!=bi; i = (i+1)%11){
		tot *= 11;
		tot += b[i];
		tot %= (ll)1e18;
	}
	return tot;
}

int t, k1, k2;
int main(){
	scanf("%d", &t);
	// vector<int> SOR(t);
	scanf("%d", &k1);
	rep(i,0,k1) scanf("%d",a+i);
	// rep(i,0,k1) SOR[i] = a[i];
	scanf("%d", &k2);
	rep(i,0,t-k1) scanf("%d",b+i);
	// rep(i,0,t-k1) SOR[i+k1] = b[i];
	// sort(SOR.begin(), SOR.end());
	// rep(i,0,k1){
	// 	rep(j,0,SOR.size()){
	// 		if (a[i]==SOR[j]){
	// 			a[i] = j;
	// 			break;
	// 		}
	// 	}
	// }
	// rep(i,0,k2){
	// 	rep(j,0,SOR.size()){
	// 		if (b[i]==SOR[j]){
	// 			b[i] = j;
	// 			break;
	// 		}
	// 	}
	// }
	ai = k1;
	bi = t-k1;

	unordered_set<ll> S;

	int c = 0;

	while(!S.count(get_num())){
		S.insert(get_num());
		if(at==ai || bt==bi) break;
		c++;
		if(a[at]>b[bt]){
			a[ai] = b[bt];
			ai = (ai+1)%11;
			a[ai] = a[at];
			ai = (ai+1)%11; 
		}else if(a[at]<b[bt]){
			b[bi] = a[at];
			bi = (bi+1)%11;
			b[bi] = b[bt];
			bi = (bi+1)%11; 
		}
		at = (at+1)%11;
		bt = (bt+1)%11;
	}
	if (at==ai){
		printf("%d 2\n", c);
	}else if (bt==bi){
		printf("%d 1\n", c);
	}else{
		printf("-1\n");
	}
}
























