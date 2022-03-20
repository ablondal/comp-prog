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

struct frac{
	ll top, bot;
	void reduce(){
		ll a = gcd(top, bot);
		top/=a;
		bot/=a;
	}
	void inv(){
		swap(top, bot);
	}
};

frac operator+(frac a, frac b){
	frac c{a.top*b.bot + b.top*a.bot, a.bot*b.bot};
	c.reduce();
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	frac t{1, 0};
	vi xs(n);
	rep(i,0,n){
		cin >> xs[i];
	}
	for(int i=sz(xs)-1; i>=0; --i){
		t.inv();
		t = t+frac{xs[i],1};
	}
	cout << t.top << "/" << t.bot << endl;
	

}