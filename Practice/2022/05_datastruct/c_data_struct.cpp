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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin >> n){

		queue<int> Q;
		stack<int> S;
		priority_queue<int> H;

		int poss = 7;

		rep(i,0,n){
			int a, x;
			cin >> a >> x;
			if (a == 1) {
				Q.push(x);
				S.push(x);
				H.push(x);
			} else {
				if (Q.empty()){
					poss = 0;
					continue;
				}
				if (Q.front() != x) poss &= 3;
				if (S.top() != x) poss &= 5;
				if (H.top() != x) poss &= 6;
				Q.pop(); S.pop(); H.pop();
			}
		}

		if (poss == 4) cout << "queue" << endl;
		else if (poss == 2) cout << "stack" << endl;
		else if (poss == 1) cout << "priority queue" << endl;
		else if (poss == 0) cout << "impossible" << endl;
		else cout << "not sure" << endl;
	}
}