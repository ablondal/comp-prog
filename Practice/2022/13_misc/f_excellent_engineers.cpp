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
const int inf = 1e9;

struct pt{
	int x, y, z;
};
bool cmpx(pt a, pt b){return a.x < b.x;}
bool cmpy(pt a, pt b){return a.y < b.y;}
bool cmpz(pt a, pt b){return a.z < b.z;}

struct kdnode{
	vector<pt> pts;
	int mx, Mx, my, My, mz, Mz;
	int dim;
	kdnode *a=0, *b=0;
	kdnode(vector<pt>&& inp, int d):pts(inp), dim(d){
		// cout << "making node" << endl;
		mx = my = mz = inf;
		Mx = My = Mz = -inf;
		for(auto& p:pts){
			mx = min(mx, p.x);
			my = min(my, p.y);
			mz = min(mz, p.z);
			Mx = max(Mx, p.x);
			My = max(My, p.y);
			Mz = max(Mz, p.z);
		}
		if (dim == 0){
			sort(all(pts), cmpx);
		} else if (dim == 1){
			sort(all(pts), cmpy);
		} else {
			sort(all(pts), cmpz);
		}
		if (sz(pts)>1){
			int mid = sz(pts)/2;
			a = new kdnode({pts.begin(), pts.begin()+mid}, (d+1)%3);
			b = new kdnode({pts.begin()+mid, pts.end()}, (d+1)%3);
		}
	}
};

bool tree_find(kdnode* curr, pt p){
	if (curr == nullptr) return false;
	if (curr->Mx < p.x && curr->My < p.y && curr->Mz < p.z) return true;
	if (curr->mx >= p.x || curr->my >= p.y || curr->mz >= p.z) return false;
	if (tree_find(curr->b, p)) return true;
	if (tree_find(curr->a, p)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pt> pts(n);
		rep(i,0,n){
			cin >> pts[i].x >> pts[i].y >> pts[i].z;
		}
		kdnode* root = new kdnode({pts.begin(), pts.end()}, 0);
		int tot = 0;
		rep(i,0,n){
			// cout << "looking" << endl;
			tot += !tree_find(root, pts[i]);
		}
		cout << tot << endl;
	}


}