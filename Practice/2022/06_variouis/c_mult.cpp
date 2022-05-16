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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int c=0, d=0;
	rep(i,0,sz(a)) c += (a[i]=='S');
	rep(i,0,sz(b)) d += (b[i]=='S');
	d *= c;
	rep(i,0,d){
		cout << "S(";
	}
	cout << "0";
	rep(i,0,d){
		cout << ")";
	}
	cout << endl;
}