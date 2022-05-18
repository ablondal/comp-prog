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
const double PI = acos(-1);

// Apply a transformation so no two points have the same x-coord
inline cd get_pt(){
	int a, b;
	cin >> a >> b;
	return polar(1.0, 0.1000001) * cd(a, b);
}

bool le(cd a, cd b){
	return (real(a)==real(b) ? imag(a)<imag(b) : real(a)<real(b));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	while(cin >> n >> m >> k){
		if (n==0) break;

		cd s = get_pt(), t = get_pt();
		vector<cd> spts, vpts, trees;

		rep(i,0,n) trees.push_back(get_pt());
		rep(i,0,m) spts.push_back(get_pt());
		rep(i,0,k) vpts.push_back(get_pt());

		vector<cd> pts;
		pts.push_back(s);
		for(auto p : spts) pts.push_back(p);
		pts.push_back(t);
		reverse(all(vpts));
		for(auto p : vpts) pts.push_back(p);

		sort(all(trees), le);

		list<int> markers;

		rep(i,0,sz(pts)){
			int j = (i+1)%sz(pts);
			// int st, en, d;

			vector<int> mk;
			auto pta = pts[i], ptb = pts[j];
			if (real(pta)>real(ptb)) swap(pta, ptb);

			// cout << pta << " " << ptb << endl;

			rep(k,0,sz(trees)){
				if (real(pta) <= real(trees[k]) && real(trees[k]) <= real(ptb)) {
					cd y_sect = pta
						+ (ptb-pta) * (real(trees[k])-real(pta)) / (real(ptb)-real(pta));
					if ( imag(y_sect) > imag(trees[k]) ) {
						mk.push_back(k+1);
					} else {
						mk.push_back(-k-1);
					}
				}
			}



			if (real(i) > real(j)) reverse(all(mk));
			for(auto m : mk) {
				// cout << m << endl;
				markers.push_back(m);
			}
		}

		auto it1 = markers.begin(), it2 = it1;
		it2++;
		int nwithout = 0;
		while(markers.size()>1 && nwithout < sz(markers)+5){
			if (*it1 == *it2){
				markers.erase(it1);
				it1 = it2 = markers.erase(it2);
				if (it1 == markers.begin()) it1 = markers.end();
				it1--;
				if (it2 == markers.end()) it2 = markers.begin();
				nwithout = 0;
			} else {
				it1++;
				it2++;
				if (it1 == markers.end()) it1 = markers.begin();
				if (it2 == markers.end()) it2 = markers.begin();
				nwithout++;
			}
			// for(auto a : markers){
			// 	cout << a << " ";
			// }
			// cout << endl;
		}
		// while (!markers.empty()){
		// 	it1 = markers.begin();
		// 	it2 = markers.end();
		// 	it2--;
		// 	if (it1 != it2 && *it1 == *it2){
		// 		it1 = markers.erase(it1);
		// 		it2 = markers.erase(it2);
		// 		it2--;
		// 	} else {
		// 		break;
		// 	}
		// }
		if (markers.empty()) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
			// for(auto a : markers){
			// 	cout << a << " ";
			// }
			// cout << endl;
		}


	}
}