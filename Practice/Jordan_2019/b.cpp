#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector <int> primes;
bool* sieve;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	primes.push_back(2);
	sieve = new bool[(int)1e7];
	fill(sieve, sieve+(int)1e7, true);
	for(int i=2; i<1e7; ++i){
		if (sieve[i]) {
			primes.push_back(i);
			for(int j=2*i; j<1e7; j+=i){
				sieve[j] = false;
			}
		}
	}

	free(sieve);

	int n, a(0), b(0);
	cin >> n;
	for(auto p : primes){
		if (p >= n) break;
		if (binary_search(all(primes), n-p)) {
			a = p; b = n-p;
		}	
	}
	if (a) {
		cout << a << " " << b << endl;
	} else {
		cout << -1 << endl;
	}
}