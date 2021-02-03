#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1e6;

char isprime[N+1] = {0};

int main() {
	isprime[0] = isprime[1] = 1;
	isprime[2] = 0;
	vector<int> primes;
	primes.push_back(2);
	for (int i=3; i<=N; i+=2) {
		if ( isprime[i] ) continue;

		primes.push_back(i);
		
		if ( (ll) i*i > N ) continue;
		for( int j = i*i; j<=N; j+=i ){
			isprime[j] = 1;
		}
	}
	for(int i=0; i<20; ++i){
		printf("%d\n", primes[i]);
	}
}