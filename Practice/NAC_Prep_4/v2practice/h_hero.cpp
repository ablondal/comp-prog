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
const int MX = 50007;

int n, p;
int notes[MX];
pii ivals[107];
int DP[107] = {0};
int spow[MX] = {0};

int nx_ival(int t){
	int lo = 0, hi = p;
	while(hi-lo){
		int md = (hi+lo)/2;
		if (notes[ivals[md].first] < t){
			lo = md+1;
		} else {
			hi = md;
		}
	}
	return lo;
}

int nx_note(int t){
	int lo = 0, hi = n;
	while(hi-lo){
		int md = (hi+lo)/2;
		if (notes[md] < t){
			lo = md+1;
		} else {
			hi = md;
		}
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> p;
	rep(i,0,n) cin >> notes[i];
	rep(i,0,p) cin >> ivals[i].first >> ivals[i].second;
	notes[n] = 1e9;
	ivals[p].first = n;

	int j = 0;
	rep(i,0,p){
		while(notes[j] < ivals[i].first) {
			j++;
			spow[j] = spow[j-1];
		}
		ivals[i].first = j;
		while(notes[j] < ivals[i].second) {
			j++;
			spow[j] = spow[j-1] + notes[j] - notes[j-1];
		}
		ivals[i].second = j;
	}
	while(j<n) {
		j++;
		spow[j] = spow[j-1];
	}

	rep(i,0,p){
		rep(c, ivals[i].first, ivals[i+1].first) {
			j = i+1;
			for(int b4 = i; b4 >= 0; --b4){
				int cpow = spow[c] - spow[ivals[b4].first];
				int nx_i = nx_ival(notes[c] + cpow);
				int nx_n = nx_note(notes[c] + cpow);
				rep(k, j, nx_i+1){
					DP[k] = max(DP[k], DP[b4] + min(nx_n, ivals[k].first) - c);
				}
				j = nx_i;
			}
		}
		// cout << DP[i] << endl;
	}
	cout << DP[p] + n << endl;
}