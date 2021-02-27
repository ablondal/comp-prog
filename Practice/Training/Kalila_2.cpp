#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef struct{
	ll m, b;
} pt;
// #define x real
// #define y imag
const ll INF = 1e18+7;
const int MAXN = 1e5+7;

ll DP[MAXN];
ll a[MAXN], b[MAXN];

vector<pt> lines;
vector<double> intersects;

double inter(pt x, pt y){
	return ((double) y.b - x.b)/((double) x.m - y.m);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n) cin >> a[i];
	rep(i,0,n) cin >> b[i];

	DP[0] = 0;
	lines.push_back({b[0], DP[0]});
	intersects.push_back(0);
	rep(i,1,n){
		int lo = 0, hi = intersects.size();
		while(hi-lo > 1){
			int mid = (lo+hi)>>1;
			if (intersects[mid] <= a[i]) lo = mid;
			else hi = mid;
		}
		// cout << lo << endl;
		auto line = lines[lo];
		DP[i] = line.m * a[i] + line.b;

		pt nl = {b[i], DP[i]};
		// lines.push_back(nl);

		while(inter(nl, lines.back()) <= intersects.back()){
			intersects.pop_back();
			lines.pop_back();
		}
		intersects.push_back(inter(nl, lines.back()));
		lines.push_back(nl);
		// cout << "lines:" << endl;
		// rep(j,0,sz(intersects)) cout << lines[j].m << " x + " << lines[j].b << " at " << intersects[j] << endl;
		
	}
	cout << DP[n-1] << endl;
}