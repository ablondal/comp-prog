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

struct pt{
	int x, y;
};

inline int dist(pt a, pt b){
	int e = a.x-b.x;
	int f = a.y-b.y;
	if ((e <= 0 && f <= 0) || (e>=0 && f>=0)){
		return max(abs(e), abs(f));
	} else {
		return abs(e)+abs(f);
	}
}

int maxdist(vector<pt>& pts, pt a){
	int M = 0;
	rep(i,0,sz(pts)){
		M = max(M, dist(pts[i], a));
	}
	return M;
}

int getminy(vector<pt>& pts, int x, pt& res){
	int lo = 0, hi = 6e5;
	while(hi-lo>=5){
		int md = (hi+lo)/2;
		if (maxdist(pts, {x,md}) < maxdist(pts, {x,md+1})) {
			hi = md+1;
		} else {
			lo = md;
		}
	}
	rep(i,lo+1,hi+1){
		if (maxdist(pts, {x, i}) < maxdist(pts, {x, lo})) lo = i;
	}
	res = {x, lo};
	return maxdist(pts, {x, lo});
}

pt find_min_dist(vector<pt>& pts){
	int lo = 0, hi = 6e5;
	pt res;
	while(hi-lo>=5){
		int md = (hi+lo)/2;
		if (getminy(pts, md, res) < getminy(pts, md+1, res)){
			hi = md+1;
		} else {
			lo = md;
		}
	}
	rep(i, lo+1, hi+1) if (getminy(pts, i, res) < getminy(pts, lo, res)) lo = i;
	int x = getminy(pts, lo, res);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pt> pts(n, {0,0});
	int minx = 1e6, maxx = 0, miny = 1e6, maxy = 0;
	int mind = 1e6, maxd = -1e6;
	rep(i,0,n){
		string s;
		cin >> s;
		rep(j,0,sz(s)){
			if (s[j]=='N') pts[i].x++;
			else pts[i].y++;
		}
		// cout << pts[i].x << " " << pts[i].y << endl;
		minx = min(minx, pts[i].x);
		maxx = max(maxx, pts[i].x);
		miny = min(miny, pts[i].y);
		maxy = max(maxy, pts[i].y);

		mind = min(mind, pts[i].x-pts[i].y);
		maxd = max(maxd, pts[i].x-pts[i].y);
	}

	int diag = mind + (maxd-mind)/2;
	int x, y;
	if (maxx-minx > maxy-miny){
		x = minx + (maxx-minx+1)/2;
		y = x - diag;
	} else {
		y = miny + (miny-maxy+1)/2;
		x = diag + y;
	}

	pt ans = {x, y};

	// pt ans = find_min_dist(pts);
	// if (ans.x == 0 && ans.y == 0) ans = {1,1};
	// cout << ans.x << " " << ans.y << " " << maxdist(pts, ans) << endl;
	cout << maxdist(pts, ans) << endl;
	rep(i,0,ans.x) cout << "N";
	rep(i,0,ans.y) cout << "B";
	cout << endl;

	// cout << (res+1)/2 << endl;
}



















