#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;
		// int a=0, b=0;
		int a=1;
		int state = s[0]-'0';
		rep(i,0,n){
			if (state^(i%2)^(s[i]-'0') == 1){
				a++;
				state = state^1;
			}
		}
		printf("%d\n", a/2);
	}
}