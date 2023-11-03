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
const int MX = 1e5+7;

ll L[MX], R[MX];
ll pos[MX], v[MX], done[MX] = {0};

using pdpii = pair<long double, pair<int, int>>;
priority_queue<pdpii, vector<pdpii>, greater<pdpii>> Q;

void addQ(int a, int b){
	long double vdiff = v[a] - v[b];
	long double pdiff = pos[b] - pos[a];
	if (vdiff == 0) return;
	long double coltime = pdiff / vdiff;
	if (coltime < 0) return;
	Q.push({coltime, {a, b}});
	// cout << a << " " <<  b << " " << coltime << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int nn = n;
	rep(i,1,n+1){
		cin >> pos[i] >> v[i];
		L[i] = i-1;
		R[i] = i+1;
	}
	pos[0] = v[0] = -2e14;
	pos[n+1] = v[n+1] = 2e14;
	rep(i,2,n+1){
		addQ(i-1, i);
	}
	while(!Q.empty()){
		auto [colt, ab] = Q.top();
		Q.pop();
		auto [a, b] = ab;
		// cout << colt << " " << a << " " << b << endl;
		if (done[a] || done[b]) continue;
		done[a] = done[b] = true;
		nn -= 2;
		int l = L[a], r = R[b];
		R[l] = r;
		L[r] = l;
		addQ(l, r);
	}
	cout << nn << endl;
	rep(i,1, n+1){
		if (!done[i]){
			cout << i << " ";
		}
	}
	cout << endl;
}