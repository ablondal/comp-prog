#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 3e5+7;

ll cost_time[maxn];
ll free_time[maxn];

ostream& operator<<(ostream& c, pii a){
	return c << "{" << a.first << ", " << a.second << "}, ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, a, b;
	cin >> n >> a >> b;
	n;
	rep(i,0,n){
		ll h;
		cin >> h;
		free_time[i] = floor(((long double)h-1)/b);
		cost_time[i] = ceil( ((long double)h - b*free_time[i])/ a);
	}
	ll tottime = 1;
	priority_queue<ll> Q;
	rep(i,0,n){
		tottime += free_time[i]+1;
		Q.push(cost_time[i]+1);
		tottime -= cost_time[i]+1;
		while(tottime < 0){
			tottime += Q.top();
			Q.pop();
		}
	}
	cout << Q.size() << endl;
}