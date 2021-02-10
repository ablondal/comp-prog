#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e7+7;

int lp[MAXN] = {0};
int psum[MAXN] = {0};
int sumtot[MAXN] = {0};

int main() {
	vi pr;
	for(int i=2; i<MAXN; ++i){
		if (lp[i]==0) {
			pr.push_back(i);
			lp[i]=i;
			psum[i]=-1;
		}
		for(int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<MAXN; ++j){
			lp[i*pr[j]] = pr[j];
			psum[i*pr[j]] = (psum[i]==-1?i:psum[i])+(pr[j]==lp[i]?0:pr[j]);
		}
	}
	rep(i, 2, MAXN){
		if (psum[i]==-1 || psum[psum[i]]==-1){
			sumtot[i] = sumtot[i-1]+1;
		}else{
			sumtot[i] = sumtot[i-1];
		}
	}
	int a,b;
	scanf("%d", &a);
	while(a){
		scanf("%d", &b);

		printf("%d\n", sumtot[b]-sumtot[a-1]);

		scanf("%d", &a);
	}
}