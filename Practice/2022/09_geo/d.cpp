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
typedef complex<ll> ci;
const double PI = acos(-1);

pair<double, cd> do_commands(vector<pair<string, int>> &cmds){
	double rot = 0;
	cd pos = 0;
	for(auto &[cmd, x] : cmds){
		if (cmd == "fd"){
			pos += exp(1i * rot) * (double) x;
		} else if (cmd == "lt") {
			rot += (double) x * (PI / 180.0);
		} else if (cmd == "rt") {
			rot -= (double) x * (PI / 180.0);
		} else if (cmd == "bk") {
			pos -= exp(1i * rot) * (double) x;
		}
	}
	return make_pair(rot, pos);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		vector<pair<string, int>> cbef, caft;
		string qcmd;
		int n;
		cin >> n;
		rep(i,0,n){
			string cmd, x;
			cin >> cmd >> x;
			if (x == "?"){
				qcmd = cmd;
				swap(cbef, caft);
			} else {
				stringstream ss;
				ss << x;
				int xx;
				ss >> xx;
				caft.emplace_back(cmd, xx);
			}
		}
		auto [rot1, pos1] = do_commands(cbef);
		auto [rot2, pos2] = do_commands(caft);
		int ans = 0;
		if (qcmd == "lt"){
			rep(i,0,360){
				if ( abs(pos1 + exp(1i * (rot1 + (i*PI/180.0)))*pos2) < 1e-6 ){
					ans = i;
				}
			}
		} else if (qcmd == "rt"){
			rep(i,0,360){
				if ( abs(pos1 + exp(1i * (rot1 - (i*PI/180.0)))*pos2) < 1e-6 ){
					ans = i;
				}
			}
		} else if (qcmd == "fd"){
			cd totd = (pos1 + exp(1i*rot1)*pos2);
			// cout << totd / exp(1i*rot1) << endl;
			ans = -round(real(totd / exp(1i*rot1)));
			// cout << totd << " " << rot1 << endl;
			// ans = (int)(-1 * )
		} else if (qcmd == "bk"){
			cd totd = (pos1 + exp(1i*rot1)*pos2);
			// cout << totd / exp(1i*rot1) << endl;
			ans = round(real(totd / exp(1i*rot1)));
		}
		// cout << rot1 << " " << pos1 << endl;
		// cout << rot2 << " " << pos2 << endl;
		cout << ans << endl;

	}
}
















