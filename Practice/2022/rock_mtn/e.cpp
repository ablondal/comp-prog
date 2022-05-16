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

unordered_map<int, int> M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vi a(N), b(N);
	rep(i,0,N) cin >> a[i];
	rep(i,0,N) cin >> b[i];
	int diff = 0;
	vi divpos;
	rep(i,0,N){
		M[a[i]]++;
		// M[b[i]]--;
		if (M[a[i]] > 0) diff++;
		else diff--;
		M[b[i]]--;
		if (M[b[i]] < 0) diff++;
		else diff--;
		if (diff == 0) divpos.push_back(i);
	}
	// divpos.pop_back();
	int j = 0;
	rep(i,0,N){
		cout << b[i] << " ";
		if (i != N-1 && divpos[j] == i){
			cout << "# ";
			j++;
		}
	}
	cout << endl;
}