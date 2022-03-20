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
const int MAXN = 1e5+7;

int L[MAXN], R[MAXN];
string S;

void goL(int &pt){
	int npt = L[pt];
	if (R[npt] != pt){
		swap(R[npt], L[npt]);
	}
	pt = npt;
}

void goR(int &pt){
	int npt = R[pt];
	if (L[npt] != pt){
		swap(R[npt], L[npt]);
	}
	pt = npt;
}

void sw(int &l, int &r){
	if (R[l] == r && L[r] == l){
		swap(S[l], S[r]);
		return;
	}
	// swap(l, r);
	swap(S[l], S[r]);
	swap(L[r], R[l]);
	if (L[R[l]] == r) L[R[l]] = l;
	else R[R[l]] = l;
	if (R[L[r]] == l) R[L[r]] = r;
	else L[L[r]] = r;
	// swap(R[r], R[l]);
	// swap(L[r], R[l]);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, l, r;
	cin >> n >> l >> r;
	cin >> S;
	l--; r--;
	rep(i,0,n){
		L[i] = i-1;
		R[i] = i+1;
	}
	int m;
	cin >> m;
	string ans;
	rep(i,0,m){
		char Q, X, Y;
		cin >> Q;
		if (Q == 'S'){
			cin >> X >> Y;
			if (X == 'L' && Y == 'L') goL(l);
			if (X == 'L' && Y == 'R') goR(l);
			if (X == 'R' && Y == 'L') goL(r);
			if (X == 'R' && Y == 'R') goR(r);
		} else if (Q == 'R') {
			sw(l, r);
		} else {
			cin >> X;
			if (X == 'L'){
				ans.push_back(S[l]);
			} else {
				ans.push_back(S[r]);
			}
		}
		// int j = 0;
		// int RL = 0;
		// int RR = 0;
		// int tt = 0;
		// while(j < n){
		// 	if (j == l) RL = tt;
		// 	if (j == r) RR = tt;
		// 	cout << S[j];
		// 	goR(j);
		// 	tt++;
		// 	// cout << j;
		// }
		// cout << endl;
		// rep(i,0,n){
		// 	if (i == RL) cout << "L";
		// 	else if (i == RR) cout << "R";
		// 	else cout << " ";
		// }
		// cout << endl;
	}
	cout << ans << endl;
}