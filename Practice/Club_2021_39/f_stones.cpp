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

vi adj[100007];
int DP[100007];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i,0,n){
		cin >> a[i];
	}
	sort(all(a));
	int i=0;
	while(i<a[0]){
		DP[i++]=0;
	}
	while(i<=k){
		for(auto aa: a){
			if (i-aa >= 0){
				if (!DP[i-aa]){
					DP[i] = 1;
				}
			}
		}
		++i;
	}
	cout << (DP[k] ? "First" : "Second") << endl;
}