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

int ask[10007] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		int a;
		cin >> a;
		ask[a]++;
	}
	ll tot = 0;
	rep(i,1,10007){
		while(ask[i]>0){
			tot += i+1;
			ask[i] -= i+1;
		}
	}
	cout << tot << endl;
}