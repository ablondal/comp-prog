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

bitset<200000> DP1[130] = {0};
bitset<200000> DP2[130] = {0};

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	DP1[1][100000] = true;

	rep(i,0,n){
		int m = (s[i]-'A'+1)*(s[i]-'A'+1);
		rep(j,1,129){
			DP2[j] = ((DP1[j-1] << m) | (DP1[j+1] >> m)) | DP1[j];
		}
		swap(DP1, DP2);
	}
	cout << DP1[1].count() << endl;
	rep(i,0,200000){
		if (DP1[1][i]){
			cout << i-100000 << endl;
		}
	}
}