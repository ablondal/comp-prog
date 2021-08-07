#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int len[1007][1007];
int nx[1007][1007];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<string> S;
	string B;
	cin >> B;
	char s[20];
	rep(i,1,sz(B)){
		rep(j,i+1,sz(B)+1){
			int n = 2;
			s[0] = B[i-1];
			s[1] = B[j-1];
			int l,m,k;
			l = i;
			m = j;
			while(l+m<=sz(B)){
				k = l+m;
				l = m;
				m = k;
				s[n++] = B[k-1];
			}
			string a(s,s+n);
			// cout << a << endl;
			S.insert(a);
		}
	}
	cout << sz(S) << endl;

}