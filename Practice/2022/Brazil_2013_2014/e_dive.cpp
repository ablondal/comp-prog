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
	set<int> S;
	int n,r;
	cin >> n >> r;
	rep(i,1,n+1){
		S.insert(i);
	}
	rep(i,0,r){
		int a;
		cin >> a;
		S.erase(a);
	}
	if (S.empty()){
		cout << "*" << endl;
	} else {
		for(auto& c : S){
			cout << c << " ";
		}
		cout << endl;
	}
}