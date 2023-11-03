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

struct line{
	ll m, b; // mx + b
	double isec(line a){
		return (a.b - b) / ((double) m - a.m);
	}
	ll at(ll x){
		return m * x + b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	// Get rectangles
	vector<tuple<ll, ll, ll>> rects(n);
	rep(i,0,n){
		ll w, h, a;
		cin >> w >> h >> a;
		rects[i] = {w, h, a};
	}
	// and sort them by w (guaranteed to be unique)
	sort(all(rects));

	// Proceed by increasing w values (decreasing h values)
	ll mx = 0;
	vector<line> lines; // This is a stack of currently useful lines
	lines.push_back({0, 0});
	int j = 0; // Index of line

	rep(i,0,n){
		auto [w, h, a] = rects[i];		
		// Move forward to find the best line for this height
		while( j < sz(lines)-1 && lines[j+1].at(h) >= lines[j].at(h) ) {
			j++;
		}

		// Get best value including this rect and construct a new line
		auto l = lines[j];
		ll ntot = l.at(h) + w*h - a;
		mx = max(mx, ntot);
		line newl({-w, ntot});

		// Get rid of redundant lines
		int sl;
		while( (sl=sz(lines)) > 1 ) {
			if (newl.isec(lines[sl-2]) > lines[sl-1].isec(lines[sl-2])) {
				lines.pop_back(); // Get rid of redundant lines
			} else {
				break;
			}
		}
		lines.push_back(newl);
	}
	cout << mx << endl;
}