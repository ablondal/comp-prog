
#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e6+7;

int S[MAXN] = {0};
int si = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	int tot = 0;
	rep(i,0,t){
		int a;
		cin >> a;
		while(si && S[si-1]<a){
			tot++;
			si--;
		}
		if (si) tot++;
		S[si] = a;
		si++;
	}
	cout << tot << endl;
}