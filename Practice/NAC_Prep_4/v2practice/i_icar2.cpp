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
const double eps = 1e-9;
// ugh okay I'll stop

int n;

struct pt{
	double x, y;
	bool operator<(pt b){
		return tie(y, x) < tie(b.y, b.x);
	}
};

struct para{
	double x, y;
	double at(double t) {
		double tpassed = t-x;
		if (tpassed < 0) return NAN;
		return y + (tpassed * tpassed / 2);
	}
	double xfromy(double ny){
		double dy = ny - y;
		if (dy < 0) return NAN;
		return x+sqrt(2*(dy));
	}
	bool operator<(para b){
		return tie(y, x) < tie(b.y, b.x);
	}
};

pair<int, para> ptisec(pt a, pt b){
	if (b.y == a.y) return {0, {0, 0}};
	if (b.y < a.y) swap(a, b);
	if (b.x < a.x) return {0, {0, 0}};
	double ave_v = (b.y - a.y) / (b.x - a.x);
	double va = ave_v - ((b.x-a.x)/2);
	double x = a.x - va;
	double y = a.y - (va*va)/2;
	if (x > a.x) return {0, {0, 0}};
	return {1, {x, y}};
}

pair<int, para> paraptisec(para a, pt b){
	if (b.x < a.x || a.at(b.x) < b.y) return {0, {1, 0}};
	double lo = a.x, hi = b.x;
	while(hi-lo > 1e-9){
		double nx = (hi+lo)/2;
		double ny = a.at(nx);
		if (para{nx, ny}.at(b.x) < b.y){
			lo = nx;
		} else {
			hi = nx;
		}
	}
	para r{lo, a.at(lo)};
	if ( abs(r.at(b.x) - b.y) > 1e-6 ) return {0, {2, 0}};
	return {1, r};
}

vector<tuple<int, int, int>> lights;

int farthest(para a){
	int k = ceil((a.y+eps)/1000.0);
	while(k<n){
		auto &[t, g, r] = lights[k];
		double x = a.xfromy(k*1000);
		if (fmod(x+t, g+r) < g) k++;
		else break;
	}
	return k;
}

double M = 1e9;
void DFS(int p){
	// cout << p << endl;
	if (paras[p].second == n) {
		M = min(M, paras[p].first.xfromy(n*1000));
		// cout << M << endl;
	}
	vis[p] = true;
	rep(i, p, sz(paras)){
		if (paras[i].first.y == paras[p].first.y) continue;
		if (paras[p].second*1000 < paras[i].first.y) break;
		if (!vis[i] && paras[i].first.y - paras[p].first.at(paras[i].first.x) < eps) {
			DFS(i);
		}
	}
}

void solve(){
	cin >> n;
	lights.resize(n);
	lights[0] = {0, 2000, 0};
	pts.push_back({0, 0});
	rep(i,1,n){
		double t,g,r;
		cin >> t >> g >> r;
		lights[i] = {t, g, r};
		// t = t - g - r;
		// rep(j,0,16){
		// 	lights[i].push_back({t-eps, i*1000.0});
		// 	pts.push_back({t, i*1000.0});
		// 	gpts.push_back({t, i*1000.0});
		// 	t += g;
		// 	lights[i].push_back({t+eps, i*1000.0});
		// 	pts.push_back({t, i*1000.0});
		// 	rpts.push_back({t, i*1000.0});
		// 	t += r;
		// }
	}
	rep(i,0,sz(pts)){
		if (pts[i].y < 0) continue;
		double dx = sqrt(2*pts[i].y);
		if (pts[i].x - dx < -eps) continue;
		int k = 1;
		para r{pts[i].x-dx, 0};
		while(k < n && pass_light(k, r)) k++;
		if (k*1000 > pts[i].y) paras.push_back({r, k});
	}
	sort(all(pts));
	// int k = 1;
	// while(k < n && pass_light(k, para{0, 0})) k++;
	// paras.push_back({para{0, 0}, k});
	rep(i,0,sz(gpts)){
		rep(j,i+1,sz(rpts)){
			auto r = ptisec(gpts[i], rpts[j]);
			if (!r.first || r.second.y < 0) continue;
			int k = ceil(pts[i].y/1000);
			while(k < n && pass_light(k, r.second)) k++;
			if (k*1000 > pts[j].y) paras.push_back({r.second, k});
		}
	}
	// int we = sz(paras);
	rep(i,0,sz(paras)){
		// cout << sz(paras) << endl;
		rep(j,0,sz(pts)){
			auto r = paraptisec(paras[i].first, pts[j]);
			if (!r.first) continue;
			int k = ceil(r.second.y/1000);
			if (k < 0) continue;
			while(k < n && pass_light(k, r.second)) k++;
			if (k*1000 > pts[j].y) paras.push_back({r.second, k});
		}
	}
	// cout << "hi" << endl;
	sort(all(paras), [](pair<para, int> &a, pair<para, int> &b){return a.first < b.first;});
	// rep(i,0,sz(paras)){
	// 	cout << paras[i].first.x << " " << paras[i].first.y << " " << paras[i].second << endl;
	// }
	vis.resize(sz(paras),0);
	// cout << sz(paras) << endl;
	int i=0;
	while(paras[i].first.y<0) i++;
	DFS(i);
	cout << setprecision(10) << M << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}