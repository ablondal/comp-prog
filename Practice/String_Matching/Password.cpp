#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll p = 37;
ll m = 1e9+9;
ll h[(int)1e6+7];
ll pn[(int)1e6+7];

int main() {
	string s;
	cin >> s;
	pn[0] = 1;
	rep(i,1,1e6+7) pn[i] = (pn[i-1]*p) % m;
	h[0] = 0;
	rep(i,0,sz(s)) h[i+1] = (h[i] + (s[i]-'a'+1)*pn[i]) % m;
	int ans = -1;
	for(int i=sz(s)-2; i>0; --i){
		ll h_pref = h[i];
		ll h_suff = (h[sz(s)] - h[sz(s)-i] + m) % m;
		if (h_suff == (h_pref*pn[sz(s)-i])%m ){
			bool is_inf = false;
			for(int j=1;j+i<sz(s);++j){
				ll h_inf = (h[j+i]+m-h[j]) % m;
				if ( (h_pref * pn[j]) % m == h_inf){
					is_inf = true;
					rep(k,0,i){
						if (s[k] != s[j+k]){
							is_inf = false;
							break;
						}
					}
					if (is_inf){
						break;
					}
				}
			}
			if (is_inf){
				ans = i;
				break;
			}
		}
	}
	if (ans==-1){
		cout << "Just a legend" << endl;
	}else{
		cout << s.substr(0,ans) << endl;
	}
}














