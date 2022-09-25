#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

bitset<100007> BS = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c;
	cin >> n >> c;
	BS[0] = 1;
	vi a(n);
	int s = 0;
	rep(i,0,n){
		cin >> a[i];
		s += a[i];
	}
	a.push_back(0);
	sort(all(a));
	reverse(all(a));
	int j = c;
	int M = 0;
	rep(i,0,n+1){
		while(j >= a[i]){
			if (j + s <= c) {
				if (BS[c-j-s]) {
					M = max(M, j);
				}
			}
			j--;
		}
		BS |= (BS << a[i]);
		s -= a[i];
	}
	cout << c-M << endl;
}