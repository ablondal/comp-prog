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

vi generate(int i, int p){
	if (p == 1) return {1};
	int pos = (i % (2*p));
	if (pos >= p) pos = (2*p - 1 - pos);
	pos = p - 1 - pos;
	vi a = generate(i / p, p - 1);
	a.insert(a.begin()+pos, p);
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int f = 1;
	rep(i,2,n+1) f *= i;
	rep(i,0,f){
		vi a = generate(i, n);
		for(auto b: a){
			cout << b << " ";
		}
		cout << endl;
	}
}