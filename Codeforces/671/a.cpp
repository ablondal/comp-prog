#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string S;
		cin >> S;
		bool is0 = false;
		bool is1 = false;
		rep(i,0,n){
			if (i%2==0 && (S[i]-'0') % 2 == 1){
				is0 = true;
			}else if (i%2==1 && (S[i]-'0') % 2 == 0){
				is1 = true;
			}
		}
		rep(i,0,n){}
		if ( (n % 2 == 1 and is0) or (n%2==0 and !is1)){
			printf("1\n");
		}else{
			printf("2\n");
		}
	}
}