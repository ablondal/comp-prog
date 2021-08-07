#include <bits/stdc++.h>
using namespace std;
// hacky answer
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int ans[] = {2, 1, 2, 2, 1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int N;
		cin >> N;
		if (N >= 5){
			cout << "first" << endl;
		}else if (ans[N]==1){
			cout << "first" << endl;
		}else{
			cout << "second" << endl;
		}
	}
}