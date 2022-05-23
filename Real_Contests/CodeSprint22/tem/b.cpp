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

int xtra;

bool is_good(vector<bool> &ch, vi& t, int ss){
	if (ss == 12) {
		int a=-1;
		rep(k,0,14){
			if (a == -1 && !ch[k]) a = k;
			else if (a != -1 && !ch[k]){
				if (t[a] == t[k]) return true;
				return false;
			}
		}
	}
	rep(i,0,14){
		if (ch[i]) continue;
		rep(j,i+1,14){
			if (ch[j]) continue;
			rep(k,j+1,14){
				if (ch[k]) continue;
				vi b({t[i], t[j], t[k]});
				sort(all(b));
				if (b[0] == b[1] && b[1] == b[2]){
					ch[i] = ch[j] = ch[k] = 1;
					if (is_good(ch, t, ss+3)) return true;
					ch[i] = ch[j] = ch[k] = 0;
				} else if (b[0]+1 == b[1] && b[1]+1 == b[2]){
					ch[i] = ch[j] = ch[k] = 1;
					if (is_good(ch, t, ss+3)) return true;
					ch[i] = ch[j] = ch[k] = 0;
				}
			}
		}
	}
	return false;
}

int score_hand(vector<int> a){
	sort(all(a));
	vector<bool> ch(14, 0);
	if (is_good(ch, a, 0)) {
		int ct = 1;
		rep(i,0,14){
			if (a[i] == xtra) ct++;
		}
		return ct;
	} else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> xtra;
	vi a(14);
	rep(i, 0, 14){
		cin >> a[i];
	}
	sort(all(a));
	// cout << score_hand(a) << endl;
	map<int, int> left;
	rep(i,1,10){
		left[i] = 4;
	}
	rep(i,0,14) left[a[i]]--;
	double M = 0;
	rep(i,0,14){
		vi b;
		rep(j,0,14){
			if (i != j) {
				b.push_back(a[j]);
			}
		}
		double ex = 0;
		for(auto &[n, ct] : left){
			if (ct){
				b.push_back(n);
				ex += (ct / 22.0) * score_hand(b);
				b.pop_back();
			}
		}
		M = max(M, ex);
	}
	cout << setprecision(10) << M << endl;

}