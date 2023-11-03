#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	
	// try{
	while(cin >> t) {
		int state = 0;
		state = t | (t << 6);
		// cout << log2(state) << endl;
		vi ns;
		rep(j,0,47) {
			int rnd = 0;
			rep(i,0,16) {
				int rs_bit = (state & 1) ^ ((state & (1<<4))>>4) ^ ((state & (1<<10))>>10) ^ ((state & (1<<11))>>11);
				state = (state >> 1) | (rs_bit << 12);
				rnd = (rnd << 1) | (rs_bit);
			}
			ns.push_back(rnd);
		}
		rep(i,42, 47){
			cout << ns[i] << " ";
		}
		cout << endl;
	}
	// } catch (...) {;}

}