#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 3e5 + 10;

int W[MAXN] = {0};
// int R[MAXN] = {0};

int state[MAXN][256] = {{0}};
// int transition[MAXN][256] = {{0}};

// bitset<MAXN> state2[MAXN];

int finalstate[256];

vi to[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	// vector<bitset<MAXN>> state2(n);
	rep(i,0,256){
		if (i & (1<<7)) finalstate[i] = 1;
		state[0][i] = i;
		// cout << "state " << 0 << " " << i << ": " << state[0][i] << endl;
	}

	rep(i,0,n){
		string s;
		cin >> s;
		rep(j,0,8){
			if (s[j] == 'W') W[i] |= (1<<j);
		}
	}

	rep(i, 0, n){
		rep(k,1,9){
			if (i+k < n && 8 - __builtin_popcount(W[i]^W[i+k]) >= k) {
				to[i].push_back(i+k);
			}
		}
	}

	// rep(i,0,n){
	// 	cout << i << " to: ";
	// 	for(auto f : to[i]){
	// 		cout << f << " ";
	// 	}
	// 	cout << endl;
	// }

	rep(i, 0, n-1){
		rep(j,0,256){
			int st = 0;
			for (auto t : to[i]){
				// if (j == 0) cout << "t << " << t << endl;
				st |= !(j & (1<<(8-(t-i))));

				// for (auto f : from[]) {
				// 	st |= !(j & (1<<(8-k)) );
				// 	// if (j==0){
				// 	// 	cout << i-1+k << "<-" << i-1 << endl;
				// 	// }
				// }
			}
			// if (j == 0) cout << st << " hih?" << endl;
			// cout << ((int) (st<<7) | (j>>1)) << endl;
			// transition[i+1][j] = (st<<7) | (j>>1);
			state[i+1][j] = state[i][ (st<<7) | (j>>1) ];
			// cout << "state " << i << " " << j << ": " << state[i][j] << endl;
		}
	}

	// rep(i,0,n){
	// 	int currstate = 0;
	// 	for(int j=i; j>0; --j){
	// 		cout << transition[j][currstate] << endl;
	// 		if (j) currstate = transition[j][currstate];
	// 		// cout << (state[j-1][currstate] & (1<<7)) << endl;
	// 	}
	// 	cout << endl;
	// }

	rep(i,0,n){
		// int currstate = 0;
		// for(int j=i; j>0; --j){
		// 	currstate = state[j][currstate];
		// 	cout << currstate << endl;
		// }
		cout << ( (state[i][ (1<<7)-1]&(1<<7)) ? '1' : '2');
	}
	cout << endl;

		// rep(i,0,64){
		// 	if (i & (1<<7)) state[n-1][i] = 1;
		// 	else state[n-1][i] = 0;
		// }

		// state[i] = 0;
		// int nsince = 0;
		// for(int j=i-1; j>=0; --j){
		// 	int b4 = state[j];
		// 	state[j] = 0;
		// 	for(int k=1; k<=8; ++k){
		// 		if (j+k <=i && 8 - __builtin_popcount( (W[j]^W[j+k]) ) >= k) {
		// 			state[j] |= !state[j+k];
		// 		}
		// 	}
		// 	if (state[j]==b4) nsince++;
		// 	else nsince = 0;
		// 	if (nsince >= 8) break;
		// }
		// cout << (state[0] ? '1' : '2');
	// }
	// cout << endl;

}









