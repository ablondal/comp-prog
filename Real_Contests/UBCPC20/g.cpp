#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char isP[(int)1e9] = {0};

bool isprime(int n){
	if (isP[n]){
		if (isP[n]==1) return true;
		else return false;
	}
	if (n>2 && n%2==0) {isP[n]=0; return 0;}
	for(int i=3; i*i<=n; i+=2){
		if(n%i==0) {isP[n]=0; return 0;}
	}
	isP[n] = 1;
	return 1;
}

set<int> p[9];
set<int> ps[9];
unordered_set<string> s;
unordered_set<string> sb;
set<int> PS;

char opts[4] = {'1', '3', '7', '9'};

int fill(vector<char> tr, int m, int n, int x, int y){
	// rep(i,0,m*n) printf(i%m==m-1 ? "%c\n" : "%c", tr[i]);printf("\n");
	if (x==m) x=0,y++;
	if (y>=n) return 1;
	while(tr[y*m+x] != '0'){
		x++;
		if (x==m){
			y++;
			x=0;
			if (y>=n){
				// rep(i,0,m*n) printf(i%m==m-1 ? "%c\n" : "%c", tr[i]);printf("\n");
				return 1;
			}
		}
	}
	string a, b;
	rep(i,0,y) a = a+tr[i*m+x];
	rep(i,0,x) b = b+tr[y*m+i];
	int ct = 0;
	for(int i=0; i<4; i++){
		// int aa = stoi(a+opts[i]);
		// int bb = stoi(b+opts[i]);
		// cout << "opt " << aa << " " << bb << endl;
		// cout << (int)(PS.count(aa)) << " " << (int)(PS.count(bb)) << endl;
		if (s.count(a+opts[i]) && s.count(b+opts[i])){
			tr[y*m+x] = opts[i];
			ct += fill(tr, m, n, x, y);
			tr[y*m+x] = '0';
			// rep(i,0,m*n) printf(i%m==m-1 ? "%c\n" : "%c", (tr[i] ? tr[i] : '0'));printf("\n");
		}
	}
	return ct;
}

int main() {
	isP[1] = -1;
	// DP[1][1].insert({2});
	// DP[1][1].insert({3});
	// DP[1][1].insert({5});
	// DP[1][1].insert({7});
	for(int i=2; i<10; ++i){
		if (isprime(i)){p[1].insert(i);ps[1].insert(i);}
	}
	for(int i=2; i<9; ++i){
		for(auto pr : p[i-1]){
			for(int j=1; j<10; j+=2){
				if (isprime(10*pr+j)){
					p[i].insert(10*pr+j);
				}
			}
		}
		for(auto pr :ps[i-1]){
			for(int j=3; j<8; j+=2){
				if (isprime(10*pr+j)){
					ps[i].insert(10*pr+j);
				}
			}
		}
	}
	rep(i,1,9){
	for(auto pr: p[i]){
		s.insert(to_string(pr));
		// if (i==4) printf("%d\n", pr);
		PS.insert(pr);
	}
	}
	rep(i,1,9){
	for(auto pr: ps[i]){
		sb.insert(to_string(pr));
	}
	}

	// for(auto S:s){
	// 	cout << S << endl;
	// }

	int n,m;
	scanf("%d%d", &n, &m);

	if (m>5 || n>5){
		printf("%d\n", 0);
		return 0;
	}
	if (m==1){
		printf("%d\n", sz(ps[n]));
		return 0;
	}
	if (n==1){
		printf("%d\n", sz(ps[m]));
		return 0;
	}
	int num = 0;
	for(auto p1: ps[m]){
		for(auto p2:ps[n]){
			string s1 = to_string(p1);
			string s2 = to_string(p2);
			if (s1[0]!=s2[0]) continue;
			// cout << s1 << " " << s2 << endl;
			vector<char> tr(m*n, '0');
			rep(i,0,m) tr[i] = s1[i];
			rep(i,0,n) tr[m*i] = s2[i];
			num += fill(tr, m, n, 1, 1);
		}
	}
	printf("%d\n", num);

}




















