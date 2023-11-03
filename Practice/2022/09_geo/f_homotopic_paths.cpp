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

inline cd get_pt(){
	int a, b;
	cin >> a >> b;
	return cd(a, b);
}

bool le(cd a, cd b){
	return (real(a)==real(b) ? imag(a)<imag(b) : real(a)<real(b));
}

void populate_and_reduce(vector<cd> &path, vector<cd> &trees, list<int> &m){
	int i = 0;
	while(real(trees[i]) <= real(path[0])) i++;

	// populate
	rep(j, 1, sz(path)){
		auto p = path[j-1], q = path[j];
		if (real(p) == real(q)) continue;

		double slope = (imag(q)-imag(p))/(real(q)-real(p));

		while(real(trees[i]) <= real(q)) {
			double y = imag(p) + (real(trees[i])-real(p))*slope;
			if (y > imag(trees[i])) m.push_back(i);
			else m.push_back(-i);
			i++;
		}

		while(real(trees[i-1]) > real(q)) {
			double y = imag(p) + (real(trees[i-1])-real(p))*slope;
			if (y > imag(trees[i-1])) m.push_back(i-1);
			else m.push_back(-(i-1));
			i--;
		}
	}

	// reduce
	auto it = m.begin();
	auto it2 = m.begin();
	while(it2 != m.end()){
		if (it == it2) {
			it2++;
		}

		if (*it2 == *it) {
			m.erase(it);
			it = it2 = m.erase(it2);
			if (it != m.begin()) it--;
		} else {
			it++;
			it2++;
		}
	}
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

		vector<cd> pts1, pts2;
		pts1.push_back(s);
		pts2.push_back(s);
		for(auto p : spts) pts1.push_back(p);
		for(auto p : vpts) pts2.push_back(p);
		pts1.push_back(t);
		pts2.push_back(t);

		trees.push_back(cd(-1e7, -1e7));
		trees.push_back(cd(1e7, 1e7));
		sort(all(trees), le);
		// rep(i,0,sz(trees)) cout << trees[i] << " ";
		// cout << endl;

		list<int> m1, m2;

		populate_and_reduce(pts1, trees, m1);
		populate_and_reduce(pts2, trees, m2);

		vi a(all(m1));
		vi b(all(m2));

		if (a == b) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
			// for(auto a : m1){
			// 	cout << a << " ";
			// }
			// cout << endl;
			// for(auto a : m2){
			// 	cout << a << " ";
			// }
			// cout << endl;
		}


	}
}