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
vi p[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		int b;
		cin >> b;
		p[b].push_back(i);
	}
	int m = 1e9;
	rep(j,1,MAXN){
		if (sz(p[j])==0) continue;
		if (sz(p[j])==1) m = min(m, n-1);
		int M = p[j][0] + n - p[j][sz(p[j])-1]-1;
		rep(i,0,sz(p[j])-1){
			M = max(M, p[j][i+1]-p[j][i]-1);
		}
		m = min(m, M);
	}
	cout << m + n << endl;
}