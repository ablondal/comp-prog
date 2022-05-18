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
	int n;
	cin >> n;
	vector<string> a, b;
	a.push_back("0");
	a.push_back("1");
	rep(i,0,n-1){
		b.clear();
		rep(i,0,sz(a)){
			b.push_back("0"+a[i]);
		}
		rep(i,1,sz(a)+1){
			b.push_back("1"+a[sz(a)-i]);
		}
		swap(a,b);
	}
	rep(i,0,sz(a)){
		cout << a[i] << endl;
	}
}