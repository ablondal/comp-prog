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
const int MN = 100;
int N, M;

typedef struct vec V;

struct vec{
	vector<double> v;
	vec(vector<double> av): v(all(av)) {}
	vec(): v(N, 0) {}
	V operator+(vec &a){
		V b(v);
		rep(i,0,N) b.v[i] += a.v[i];
		return b;
	}
	V operator-(vec &a){
		V b(v);
		rep(i,0,N) b.v[i] -= a.v[i];
		return b;
	}
	V operator*(double c){
		V b(v);
		rep(i,0,N) b.v[i] *= c;
		return b;
	}
	double dot(vec &a){
		ll b(0);
		rep(i,0,N) b += a.v[i] * v[i];
		return b;
	}
};




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

}