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

int st[307][307] = {{0}};

void calcst(){
	vector<char> reach(607);
	rep(i,1,301){
		rep(j,i+2,301){
			reach.assign(607, 1);
			rep(k,1,i){
				reach[st[k][j]] = 0;
			}
			rep(k,1,i-1){
				reach[st[k][i]] = 0;
			}
			rep(k,i+2,j){
				reach[st[i][k]] = 0;
			}
			rep(k,0,607){
				if (reach[k]) {
					st[i][j] = k;
					break;
				}
			}
		}
	}
}

bool evalstate(int a, int b, int c, int d){
	// cout << a << b << c << d;
	// printf("%d %d %d %d\n", a, b, c, d);
	if (a > c) swap(a,c);
	if (b > d) swap(b,d);
	int dx = c-a, dy = d-b;
	if (dx + dy == 1){
		// printf("0\n");
		// printf("%d %d %d %d\n", a, b, c, d);
		return 0;
	}
	else if (dx < 2 || dy < 2){
		// printf("1\n");
		 return 1;
	}
	else{
		// printf("%d\n", st[a][c] != st[b][d]);
		// if (st[a][c] == st[b][d]) {
		// 	printf("%d %d %d %d\n", a, b, c, d);
		// }
		return st[a][c] != st[b][d];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	calcst();

	// cout << st[3][5] << " " << st[1][6] << endl;
	int n;
	cin >> n;
	rep(i,0,n){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int tot = 0;
		// if (!evalstate(a,b,c,d)){
		// 	cout << 0 << endl;
		// 	continue;
		// }
		// cout << evalstate(a,b,c,d) << endl;
		rep(i,1,a){
			if (b == d && a>c && i <= c) continue;
			tot += !evalstate(i, b, c, d);
		}
		rep(i,1,c){
			if (b==d && c>a && i<=a) continue;
			tot += !evalstate(a, b, i, d);
		}
		rep(i,1,b){
			if (a==c && b > d && i<=d) continue;
			tot += !evalstate(a, i, c, d);
		}
		rep(i,1,d){
			if (a==c && d > b && i<=b) continue;
			tot += !evalstate(a, b, c, i);
		}
		cout << tot << endl;
	}

}