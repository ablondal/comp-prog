#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double PI = acos(-1);

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	double d, h, v, e;
	cin >> d >> h >> v >> e;
	double invol = (d/2)*(d/2)*PI*h;
	double ratep = (d/2)*(d/2)*PI*e;
	if (ratep >= v) {
		cout << "NO" << endl;
		exit(0);
	}
	v -= ratep;
	cout << "YES" << endl;
	cout << setprecision(10) << invol/v << endl;
}