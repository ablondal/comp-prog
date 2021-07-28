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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s += s;
	int i=1;
	int ee = -1;
	for(;i<n && ee==-1;++i){
		for(int j=0;j<n;++j){
			if (s[j]<s[i+j]){
				ee = i;
				break;
			}else if(s[j]>s[i+j]) break;
		}
	}
	if (ee==-1) ee = n;
	for(int l=0;l<k;++l){
		cout << s[l%ee];
	}
	cout << endl;
}