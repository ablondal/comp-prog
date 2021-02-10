#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int primes[] = {2,3,5,7,11,13,17,19,23};
// const int sump[] = {2,3,5,7,11,13,17,19,23,29};

int main() {
	int n;
	scanf("%d", &n);
	vi a(n);
	rep(i,0,n){
		scanf("%d", &a[i]);
	}
	sort(all(a));
	ll tot = 0;
	rep(i,0,n){
		tot += abs(i+1 - a[i]);
	}
	printf("%lld\n", tot);
}