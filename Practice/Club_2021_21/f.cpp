#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 2e5+7;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		bool z = false;
		int lz = -1;
		int lo = -1;
		bool lon = false;
		int ct = 0;
		rep(i,0,sz(s)){
			if (s[i]=='0'){
				z = true;
				if (i-lz>=3) lon = true;
				lz = i;
			}else{
				if (lo!=-1){
					if ((i-lo) % 2 == 1) lon = true;
				}
				lo = i;
				ct++;
			}
		}
		if ( (z && lon) || ct==1) {
			cout << "LIVES" << endl;
		}else{
			cout << "DIES" << endl;
		}
	}
	
}