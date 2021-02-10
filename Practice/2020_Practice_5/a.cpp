#include <bits/stdc++.h>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 8007;
const int M2 = 807;
const ll INF = 1e18+7;

ll DP[M2][MAXN] = {0};
ll C[MAXN];
ll S[MAXN] = {0};

ll cost(int a, int b){
	return ((ll)b-a)*(S[b]-S[a]);
}

void div_conq(int l, int r, int optl, int optr, int i){
	if (l>r) return;
	int mid = (l+r)>>1;
	int optm;
	pair<ll, int> b = {INF, -1};

	rep(k, optl, min(mid, optr)+1){
		b = min(b, {DP[i-1][k]+cost(k,mid), k});
	}

	DP[i][mid] = b.first;
	int opt = b.second;

	div_conq(l, mid-1, optl, opt, i);
	div_conq(mid+1, r, opt, optr, i);	
}

int main() {
	int l, g;
	scanf("%d%d", &l, &g);
	rep(i,0,l){
		scanf("%d", C+i);
		if (i) S[i] = S[i-1]+C[i];
		else S[i] = C[i];
		// S[i+1]=S[i]+C[i];
		DP[1][i] = ((ll)i+1)*S[i];
	}
	rep(i,2,g+1){
		div_conq(0,l-1,0,l-1,i);
	}
	printf("%lld\n", DP[g][l-1]);
	

}