#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a[1007];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i = 0;
	int b = 1;
	while(i<1005){
		if (b%3 == 0 || b%10 == 3){
			b++;
		}else{
			a[i++] = b++;
		}
	}
	cin >> i;
	while(i--){
		cin >> b;
		cout << a[b-1] << endl;
	}
	// cout << a[i] << endl;
}