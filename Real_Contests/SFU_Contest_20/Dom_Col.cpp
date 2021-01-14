#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int DP[107][107] = {{0}}; // #odd, #even

int main() {
	int n;
	cin >> n;
	while(n--){
		string T;
		cin >> T;
		string a,b,c;
		a = T.substr(1,2);
		b = T.substr(3,2);
		c = T.substr(5,2);
		int A,B,C;
		A=stoi(a,NULL,16);
		B=stoi(b,NULL,16);
		C=stoi(c,NULL,16);
		// printf("%d %d %d\n", A,B,C);
		string res;
		if(A>=B && A>=C){
			if(A==B && A==C){
				res = "grey";
			}else if(A==B){
				res = "yellow";
			}else if(A==C){
				res = "magenta";
			}else{
				res = "red";
			}
		}else if(B>=A && B>=C){
			if(B==C){
				res = "cyan";
			}else{
				res = "green";
			}
		}else{
			res = "blue";
		}
		cout << res << endl;
	}
}