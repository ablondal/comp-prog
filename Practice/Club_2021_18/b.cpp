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
	ll n;
	cin >> n;
	vi a(2*n);
	rep(i,0,2*n) cin >> a[i];
	int t = 0;
	rep(i,0,n){
		for(int j=2*n-1; j>=2*(i+1); --j){
			if (a[j] == a[2*i]){
				swap(a[j], a[j-1]);
				t++;
			}
		}
	}
	cout << t << endl;
}