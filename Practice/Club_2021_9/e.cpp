#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a;
	cin >> a;
	int n1s = 0;
	int n2s = 0;
	for(auto c : a){
		if (c=='1') n1s++;
		else n2s++;
	}
	ll cost1 = 0;
	ll cost2 = 0;
	for(int i=0; i<sz(a); ++i){
		if (a[i] == '1'){
			n1s--;
			cost2 += n2s;
		}else{
			n2s--;
			cost1 += n1s;
		}
	}
	cout << min(cost1, cost2) << endl;
}