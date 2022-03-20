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

void printres(vector<string> &ans){
	rep(i,0,sz(ans)){
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	vector<string> a(t);
	stringstream S;
	rep(i,0,t){
		cin >> a[i];
	}
	bool w = false;
	rep(j,0,t){
		rep(i,0,a[j].size()){
			rep(k,0,10){
				if (k==0 && (i==0 && a[j].size() != 1)) continue;
				string n = a[j];
				n[i] = '0'+k;
				if (j>0 && stoll(n) < stoll(a[j-1])){
					a[j] = n;
					printres(a);
					return 0;
				}
				if (j<t-1 && stoll(n) > stoll(a[j+1])){
					a[j] = n;
					printres(a);
					return 0;
				}
			}
		}
	}
	cout << "impossible" << endl;
}