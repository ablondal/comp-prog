#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ct = 0;
		rep(i,0,n){
			int tmp;
			cin >> tmp;
			ct += tmp==1;
		}
		if (n==2) {
			cout << 1 << endl;
			continue;
		}
		if (ct <= n/2) cout << n/2 << endl;
		else cout << (n - ct) << endl;
		// vi a(n);
		// rep(i,0,n) cin >> a[i];
		// sort(all(a));
		// vi ct(a.back()+1, 0);
		// rep(i,0,n) ct[a[i]]++;
		// int j = ct.size()-1;
		// int tot = 0;
		// while(ct[1]){
		// 	// cout << "1 " << j << endl;
		// 	while(j && ct[j]==0) j--;
		// 	tot++;
		// 	ct[1]--;
		// 	int let = j-1;
		// 	ct[j]--;
		// 	int k = j;
		// 	int last = 0;
		// 	while(let){
		// 		int m = min(ct[k]-last, let);
		// 		// cout << k << " " << m << " " << last << endl;
		// 		ct[k-1] += m;
		// 		ct[k] -= m;
		// 		let -= m;
		// 		last = m;
		// 		k--;
		// 	}
		// 	// for(int sd=1; sd <= j; ++sd) cout << ct[sd] << " ";
		// 	// 	cout << endl;
		// }
		// cout << tot << endl;

	}
}