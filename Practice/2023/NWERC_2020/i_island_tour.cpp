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
typedef vector<vi> vvi;

vector<vi> a0, a1, b0, b1, c0, c1;

void tour(vi &d, vvi &k0, vvi &k1, vi tt){
	// int t = 0;
	int n = sz(d);
	k0.resize(n);
	k1.resize(n);
	rep(i,0,n){
		int t = 0;
		k0[i].resize(n);
		k1[i].resize(n);
		rep(j,i,i+n){
			int k = j % n;
			k0[i][k] = t;
			t += tt[k];
			k1[i][k] = t;
			t += d[k];
		}
	}
}

bool catches(vi &d, vvi &b0, vvi &f1, int bs, int fs){
	int n = sz(d);
	for(int i=fs; i != bs; i = (i+1)%n){
		if (b0[bs][i] < f1[fs][i]) return false;
	}
	return true;
}

void min_back(vi &d, vvi &b0, vvi &f1, vi &res){
	int n = sz(d);
	int j = 1;
	while((j+1)%n != 0 && catches(d, b0, f1, (j+1)%n, 0)){
		j = (j + 1)%n;
	}
	res[0] = j;
	rep(i,1,n){
		if (j == i) j = (j+1)%n;
		while((j+1)%n != i && catches(d, b0, f1, (j+1)%n, i)){
			j = (j+1)%n;
		}
		res[i] = j;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vi d(n), a(n), b(n), c(n);
	rep(i,0,n) cin >> d[i];
	rep(i,0,n) cin >> a[i];
	rep(i,0,n) cin >> b[i];
	rep(i,0,n) cin >> c[i];

	if (n < 3) {
		cout << "impossible" << endl;
		return 0;
	}

	tour(d, a0, a1, a);
	tour(d, b0, b1, b);
	tour(d, c0, c1, c);

	vi ab(n), ac(n), bc(n), ba(n), ca(n), cb(n);

	// ab[i] is the closest position behind b that a can start if b starts at i
	min_back(d, a0, b1, ab);
	min_back(d, a0, c1, ac);
	min_back(d, b0, c1, bc);
	min_back(d, b0, a1, ba);
	min_back(d, c0, a1, ca);
	min_back(d, c0, b1, cb);

	rep(apos,0,n){
		int bpos = ba[apos];
		int cpos = cb[bpos];
		int ab_d = (apos - bpos + n) % n;
		int bc_d = (bpos - cpos + n) % n;
		int ca_d = (cpos - ac[cpos] + n) % n;
		// cout << ca_d << " " << bc_d << " " << ab_d << endl;
		if (ab_d + bc_d	+ ca_d <= n){
			cout << apos+1 << " " << bpos+1 << " " << cpos+1 << endl;
			return 0;
		}
	}
	rep(apos,0,n){
		int cpos = ca[apos];
		int bpos = bc[cpos];
		int ac_d = (apos - cpos + n) % n;
		int cb_d = (cpos - bpos + n) % n;
		int ba_d = (bpos - ab[bpos] + n) % n;
		// cout << ac_d << " " << cb_d << " " << ba_d << endl;
		if (ac_d + cb_d	+ ba_d <= n){
			cout << apos+1 << " " << bpos+1 << " " << cpos+1 << endl;
			return 0;
		}
	}
	cout << "impossible" << endl;

	// bool win = false;

	// rep(i,0,n){
	// 	{
	// 		int j1 = ab[i];
	// 		int j2 = bc[j1];
	// 		int j3 = ca[j2];
	// 		int diff = (i - j1 + n) % n;
	// 		diff += (j1 - j2 + n) % n;
	// 		diff += (j2 - j3 + n) % n;
	// 		if (diff <= n) {
	// 			cout << i+1 << " " << j1+1 << " " << j2+1 << endl;
	// 			win = true;
	// 			break;
	// 		}
	// 	}
	// 	{
	// 		int j1 = ac[i];
	// 		int j2 = cb[j1];
	// 		int j3 = ba[j2];
	// 		int diff = (i - j1 + n) % n;
	// 		diff += (j1 - j2 + n) % n;
	// 		diff += (j2 - j3 + n) % n;
	// 		if (diff <= n) {
	// 			cout << i+1 << " " << j2+1 << " " << j1+1 << endl;
	// 			win = true;
	// 			break;
	// 		}
	// 	}
	// }
	// if (!win) cout << "impossible" << endl;
	// min_back(d, a, b, ab);
}