#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// const long double pi = 3.141592653589793;
// const int MN = 2e5+7;

// const ll MOD = 1e9+7;

// int cta[MN][26] = {{0}};
// int ctb[MN][26] = {{0}};

// int eq(int a1, int a2, int b1, int b2){
// 	rep(i,0,26){
// 		if (cta[a2]+ctb[b2]-cta[a1]-ctb[b1] != 0){
// 			return 0;
// 		}
// 	}
// 	return 1;
// }

// ll ha[MN][18] = {{0}};
// ll hb[MN][18] = {{0}};

void srt(string &a, int i, int j){
	if (j%2==1) return;
	srt(a,i,j/2);
	srt(a,i+j/2,j/2);
	bool sm = 1;
	rep(k,0,j/2){
		if (a[i+k]>a[i+j/2+k]){
			sm=0;
			break;
		}else if (a[i+k]<a[i+j/2+k]) break;
	}
	if (!sm){
		string b = a.substr(i, j/2);
		rep(k,0,j/2){
			a[i+k]=a[i+j/2+k];
			a[i+j/2+k]=b[k];
		}
	}
	return;
}

ll r[26];

int main() {
	string a, b;
	cin >> a >> b;
	srt(a, 0, sz(a));
	srt(b, 0, sz(b));
	// cout << a << " " << b << endl;
	printf((a)==(b) ? "YES\n" : "NO\n");
	// int step = 1;
	// int i=0;
	// r[0] = 101;
	// rep(i,0,25){
	// 	r[i+1] = r[i]*101;
	// 	r[i+1] %= MOD;
	// }

	// int i = 0;
	// for(i = 0; (1<<i) <= sz(a); ++i){
	// 	for(int j=0; j<sz(a); j+= (1<<i) ){
	// 		if (i==0){
	// 			ha[j][i] = (1<<(a[j]-'a')) % MOD;
	// 			hb[j][i] = (1<<(b[j]-'a')) % MOD;
	// 		}else{
	// 			ha[j][i] = (ha[j][i-1]+ha[j+(1<<(i-1))][i-1]) % MOD;
	// 			hb[j][i] = (hb[j][i-1]+hb[j+(1<<(i-1))][i-1]) % MOD;
	// 			ha[j][i] *= ha[j][i];
	// 			ha[j][i] %= MOD;
	// 			hb[j][i] *= hb[j][i];
	// 			hb[j][i] %= MOD;
	// 		}
	// 		// printf("%d %d: %lld %lld\n", j, i, ha[j][i], hb[j][i]);
	// 	}
	// }
	// if (ha[0][i-1] == hb[0][i-1]){
	// 	printf("YES\n");
	// }else{
	// 	printf("NO\n");
	// }
}