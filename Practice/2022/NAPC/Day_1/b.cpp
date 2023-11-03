#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	cin.tie(0) ->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	sort(all(a));
	int M = 0;
	rep(i,0,n){
		M = max(M, a[i] + (n-i));
	}
	cout << M+1 << endl;
}