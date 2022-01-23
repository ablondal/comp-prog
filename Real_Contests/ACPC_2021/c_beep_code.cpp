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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n){
		cin >> a[i];
	}
	vi outp(20); // 0 is x, 1 is A, 2 is B, 3 is ?
	int k = 0;
	int m = n-1;
	while(m){
		k++;
		m>>=1;
	}
	int skip = 1;
	int a0f = 0;
	rep(i,0,k){
		int d = a[0] - a[skip];
		skip <<= 1;
		if (d == 0) {
			outp[i] = 0;
		} else if (d==1){
			outp[i] = 1;
			a0f++;
		} else {
			outp[i] = 2;
		}
	}
	if (a[0] - a0f == 20 - k) {
		rep(i, k, 20){
			outp[i] = 1;
		}
	} else {
		rep(i, k, 20){
			outp[i] = 3;
		}
	}

	rep(i,0,20){
		if (outp[i] == 0) {
			cout << "x";
		} else if (outp[i] == 1){
			cout << "A";
		} else if (outp[i] == 2){
			cout << "B";
		} else if (outp[i] == 3){
			cout << "?";
		}
		cout << " ";
	}
	cout << endl;
}