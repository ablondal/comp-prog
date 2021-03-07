
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	vector<string> stu(n);
	rep(i,0,n){
		cin >> stu[i];
	}
	// rep(i,0,n) cout << stu[i] << endl;
	int M = 0;
	rep(pos,0,(1<<k)){
		int m = k;
		rep(i,0,n){
			int ct = 0;
			rep(j,0,k){
				if (stu[i][j]=='T' && (pos & (1<<j))) {
					ct++;
				}else if (stu[i][j]=='F' && (~pos & (1<<j))) {
					ct++;
				}
			}
			m = min(m, ct );
		}
		M = max(M, m);
	}
	cout << M << endl;
}