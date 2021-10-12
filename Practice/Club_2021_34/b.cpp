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
	int n;
	cin >> n;
	while(n--){
		int t;
		cin >> t;
		int a=0,b=0,c=0, tmp;
		rep(i,0,t){
			cin >> tmp;
			if (tmp%3==0) a++;
			else if (tmp%3==1) b++;
			else c++;
		}
		int bc = min(b, c);
		a += bc;
		b -= bc;
		c -= bc;


		cout << a + (b/3) + (c/3) << endl;
	}
}