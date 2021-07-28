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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int last = -1;
	ll tot = 1;
	rep(i,0,n){
		int a;
		cin >> a;
		if(a==1){
			if (last != -1){
				tot *= (i - last);
			}
			last = i;
		}
	}
	if (last == -1) tot = 0;
	cout << tot << endl;
}