#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Calculates # magic nums **strictly less** than n
ll func(ll n){
	// vector of digits is better
	vi a;
	while(n){a.push_back(n%10); n/=10;}
	reverse(a.begin(), a.end());
	
	ll smal[20][3] = {{0}};
	ll big[20][3] = {{0}};
	big[0][0] = 1;

	for(int i=0;i<a.size();++i){
		if (a[i]==6) big[i+1][1] = big[i][0]+big[i][1];
		else if (a[i]==8) big[i+1][2] = big[i][0]+big[i][1];
		else {
			big[i+1][0] = big[i][0];
			big[i+1][1] = big[i][1];
			big[i+1][2] = big[i][2];
		}
		smal[i+1][0] = smal[i][0]*8; // 8 non-6,8 choices
		smal[i+1][1] = smal[i][1]*9 + smal[i][0];
		smal[i+1][2] = smal[i][2]*9 + smal[i][0];

		for (int j=0; j<a[i]; ++j){
			if (j==6){
				smal[i+1][1] += big[i][0]+big[i][1];
			} else if (j==8){
				smal[i+1][2] += big[i][0]+big[i][2];
			} else{
				smal[i+1][0] += big[i][0];
				smal[i+1][1] += big[i][1];
				smal[i+1][2] += big[i][2];
			}
		}
	}
	return smal[a.size()][1]+smal[a.size()][2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	cout << func(n) << endl;;
}