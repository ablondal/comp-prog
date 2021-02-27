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
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	sort(all(a));
	bool works = false;
	rep(i,0,n-2){
		if (a[i] + a[i+1] > a[i+2]) {
			works = true;
			break;
		}
	}
	if (works) cout << "YES" << endl;
	else cout << "NO" << endl;
}