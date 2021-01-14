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
const int MAXN = 1e5+7;

int w[MAXN], h[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	rep(i, 0, n){
		scanf("%d%d", w+i, h+i);
	}
	int lasth = 1e9+7;
	string ans = "YES";
	rep(i,0,n){
		if (w[i]>lasth){
			if (h[i]>lasth){
				ans = "NO";
				break;
			}
			lasth = h[i];
		}else if (h[i] > lasth){
			lasth = w[i];
		}else{
			lasth = max(w[i],h[i]);
		}
	}
	cout << ans << endl;
}