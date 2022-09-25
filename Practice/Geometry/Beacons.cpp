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
const double PI_CONST = acos(-1);

int UF[1007] = {0};
int find(int x){
	return UF[x] == -1 ? x : UF[x] = find(UF[x]);
}
void merge(int a, int b){
	// cout << "merging " << a << " " << b << endl;
	a = find(a); b = find(b);
	if (a != b) {
		UF[a] = b;
		// cout << "merged" << endl;
	}
	// cout << "done" << endl;
}
double cross(cd a, cd b){
	return imag(conj(a) * b);
}
double dot(cd a, cd b){
	return real(conj(a) * b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	double x, y, r;
	vector<cd> beacon(n), peak_loc(m);
	vector<double> peak_rad(m, 0);
	vector<bool> visible(n, 1);
	vector<double> dist_peak_edge(m, 0);
	set<tuple<double, int, int>> ang_sweep;
	set<pair<double, int>> beacons_in_sweep;
	rep(i,0,n){
		cin >> x >> y;
		beacon[i] = {x, y};
		UF[i] = -1;
	}
	rep(i,0,m){
		cin >> x >> y >> r;
		peak_loc[i] = {x, y};
		peak_rad[i] = r;
	}

	rep(i,0,n-1){
		visible.assign(n, 1);
		ang_sweep.clear();
		beacons_in_sweep.clear();
		// cout << "building sweep" << endl;
		rep(j,i+1,n){
			// cout << j << endl;
			double ang = arg(beacon[j]-beacon[i]);
			// cout << i << endl;
			// cout << ang << " " << 0 << " " << j << endl;
			ang_sweep.insert(make_tuple(ang, 0, j));
			// cout << "a" << endl;
			ang_sweep.insert(make_tuple(ang - 2*PI_CONST, 0, j));
			// cout << "b" << endl;
			ang_sweep.insert(make_tuple(ang + 2*PI_CONST, 0, j));
			// cout << "what" << endl;
		}
		// cout << "building peaks" << endl;
		rep(k,0,m){
			cd ray = peak_loc[k] - beacon[i];
			double ang = arg(ray);
			double thet = asin(peak_rad[k] / abs(ray));
			dist_peak_edge[k] = cos(thet) * abs(ray);
			ang_sweep.insert(make_tuple(ang - thet, 1, k));
			ang_sweep.insert(make_tuple(ang + thet, -1, k));
		}
		// Perform sweep
		// cout << "sweeping" << endl;
		// sort(all(ang_sweep));
		for(auto [ang, type, id] : ang_sweep){
			// cout << ang << " " << type << " " << id << endl;
			// auto [type, id] = info;
			if (type == 1) {
				beacons_in_sweep.insert({dist_peak_edge[id], id});
			} else if (type == -1) {
				// cout << "erasing" << endl;
				beacons_in_sweep.erase({dist_peak_edge[id], id});
				// cout << "done" << endl;
			} else if (
				type == 0 &&
				beacons_in_sweep.size() != 0 &&
				beacons_in_sweep.begin()->first < abs(beacon[id]-beacon[i])
			){
				visible[id] = false;
			}
		}
		// cout << "done sweep" << endl;
		rep(j, i+1, n){
			// cout << "huh1" << endl;
			if (visible[j]) {
				// cout << "huh" << endl;
				merge(i, j);
			}
		}
		// cout << "done merging" << endl;
	}
	int tot_components = 0;
	// cout << "counting" << endl;
	rep(i,0,n) tot_components += (UF[i] == -1);
	cout << tot_components-1 << endl;

}