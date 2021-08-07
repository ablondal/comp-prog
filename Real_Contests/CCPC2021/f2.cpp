#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int W, H, D;
	cin >> W >> H >> D;

	int box[107][107][107] = {{{0}}};
	// rep(i,0,W)rep(j,0,H)rep(k,0,D) box[i][j][k] = 1;

	int fr[107][107] = {{0}};
	int ri[107][107] = {{0}};
	int to[107][107] = {{0}};
	int f_c[107][107] = {{0}};
	int r_c[107][107] = {{0}};
	int t_c[107][107] = {{0}};
	bool works = true;

	rep(j,0,H){
		rep(i,0,W){
			char a;
			scanf(" %c", &a);
			if (a=='#') fr[i][j] = 1;
			else fr[i][j] = 0;
		}
	}

	rep(j,0,H){
		rep(k,0,D){
			char a;
			scanf(" %c", &a);
			if (a=='#') ri[j][k] = 1;
			else ri[j][k] = 0;
		}
	}

	for(int k=D-1; k>=0; --k){
		rep(i,0,W){
			char a;
			scanf(" %c", &a);
			if (a=='#') to[i][k] = 1;
			else to[i][k] = 0;
		}
	}
	int tot = 0;
	rep(i,0,W)rep(j,0,H)rep(k,0,D){
		box[i][j][k] = fr[i][j] & ri[j][k] & to[i][k];
		tot += box[i][j][k];
		// cout << box[i][j][k] << endl;
		f_c[i][j] += box[i][j][k];
		r_c[j][k] += box[i][j][k];
		t_c[i][k] += box[i][j][k];
	}

	rep(j,0,H){
		rep(i,0,W){
			if (fr[i][j] && f_c[i][j]<1){
				works = false;
			}
		}
		// cout << endl;
	}

	rep(j,0,H){
		rep(k,0,D){
			if (ri[j][k] && r_c[j][k]<1){
				works = false;
			}
		}
	}

	rep(k,0,D){
		rep(i,0,W){
			if (to[i][k] && t_c[i][k]<1){
				works = false;
			}
		}
	}

	if(works){
		cout << tot << endl;
	}else{
		cout << "invalid" << endl;
	}

}