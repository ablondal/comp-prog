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
		int n, x;
		cin >> n >> x;
		int tot = 0;
		int totn = 0;
		int toty = 0;
		rep(i,0,n){
			int tmp;
			cin >> tmp;
			if (tmp!=x){
				tot+=(tmp-x);
				totn++;
			}else{
				toty++;
			}
		}
		if (totn==0){
			printf("0\n");
		}else if (tot==0 || toty>0){
			printf("1\n");
		}else{
			printf("2\n");
		}
	}
}