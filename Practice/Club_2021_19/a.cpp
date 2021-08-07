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
	vi a(t);
	int mx = -1;
	int l = 0;
	int cl = 0;
	rep(i,0,t){
		cin >> a[i];
		if (a[i] > mx) {
			mx = a[i];
			cl = 1;
			l = 1;
		}else if(a[i]==mx){
			cl++;
			l = max(l, cl);
		}else{
			cl = 0;
		}
	}
	cout << l << endl;
}