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
const int SQ = 1024;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<bool> mem(N, 0);
	vector<int> mem2((N+SQ-1)/SQ, 0);
	rep(i,0,K){
		int l,r;
		char I;
		cin >> I >> l;
		if (I=='F'){
			l--;
			if (mem[l]){
				mem2[l/SQ]--;
				mem[l]=0;
			} else {
				mem2[l/SQ]++;
				mem[l]=1;
			}
		} else {
			int tot = 0;
			cin >> r;
			l--;
			// cout << l << r << endl;
			int j=l;
			while(j%SQ != 0 && j<r){
				tot += mem[j];
				j++;
				// cout << tot << endl;
			}
			while(j+SQ <= r){
				tot += mem2[j/SQ];
				j+=SQ;
			}
			while(j<r){
				tot += mem[j];
				j++;
			}
			cout << tot << endl;
		}
	}
}