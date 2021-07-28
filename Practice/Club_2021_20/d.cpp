#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+7;

int a[MAXN];
ll DP[MAXN];
pair<int, int> t[MAXN*2];

void construct(int n){
	rep(i,0,n){
		t[i+n].first = a[i];
		t[i+n].second = i;
	}
	for(int i=n-1; i>=1; --i){
		t[i] = max(t[2*i], t[2*i+1]);
	}
}

pair<int, int> query(int l, int r, int n){
	pair<int, int> lm = {0,-1}, rm = {0, -1};
	l+=n, r+=n;
	for(;l<r;l/=2, r/=2){
		if (l%2){
			lm = max(lm, t[l]);
			l++;
		}
		if (r%2){
			--r;
			rm = max(rm, t[r]);
		}
	}
	return max(lm, rm);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	scanf("%d", &n);
	rep(i,0,n-1){
		scanf("%d", a+i);
		a[i]--;
	}
	construct(n-1);
	DP[n-1] = 0;
	for(int i=n-2; i>=0; --i){
		if (a[i] == n-1) DP[i] = n-i-1;
		else {
			auto q = query(i+1, a[i]+1, n-1);
			DP[i] = DP[q.second] + (n-i-1) - (a[i] - q.second);
		}
	}
	cout << accumulate(DP, DP+n, 0LL) << endl;
}