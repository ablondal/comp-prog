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

	int box[100][100][100];
	rep(i,0,W)rep(j,0,H)rep(k,0,D) box[i][j][k] = 1;

	int fr[100][100];
	int ri[100][100];
	int to[100][100];
	bool works = true;

	rep(j,0,H){
		rep(i,0,W){
			char a;
			scanf(" %c", &a);
			if (a=='#') fr[i][j] = 1;
			else fr[i][j] = 0;
			// cout << fr[i][j] << " ";
			if (fr[i][j]){
				;
			}else{
				rep(k,0,D) box[i][j][k] = 0;
			}
		}
		// cout << endl;
	}

	rep(j,0,H){
		rep(k,0,D){
			char a;
			scanf(" %c", &a);
			if (a=='#') ri[j][k] = 1;
			else ri[j][k] = 0;
			if (a=='#'){
				;
			}else{
				rep(i,0,W) box[i][j][k] = 0;
			}
		}
	}

	for(int k=D-1; k>=0; --k){
		rep(i,0,W){
			char a;
			scanf(" %c", &a);
			// if (a=='#') fr[i][j] = 1;
			// else fr[i][j] = 0;
			if (a=='#'){
				int ct = 0;
				rep(j,0,H){
					ct += box[i][j][k];
				}
				if (ct==0) works = false;
			}else{
				rep(j,0,H) box[i][j][k] = 0;
			}
		}
	}

	rep(j,0,H){
		rep(i,0,W){
			// char a;
			if (fr[i][j]){
				int ct = 0;
				rep(k,0,D){
					ct += box[i][j][k];
				}
				if (ct==0) works = false;
			}
		}
	}

	rep(j,0,H){
		rep(k,0,D){
			// if (a=='#') ri[j][k] = 1;
			// else ri[j][k] = 0;
			if (ri[j][k]){
				int ct = 0;
				rep(i,0,W){
					ct += box[i][j][k];
				}
				if (ct==0) works = false;
			}
		}
	}

	int ctt = 0;
	rep(i,0,W)rep(j,0,H)rep(k,0,D) ctt += box[i][j][k];
	if(works){
		cout << ctt << endl;
	}else{
		cout << "invalid" << endl;
	}

}