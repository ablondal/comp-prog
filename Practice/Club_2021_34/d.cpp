#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MX = 3e6;

vector <int> primes;
int get_ind(int p){
	int lo=-1, hi=primes.size();
	while(hi-lo>1){
		int md = (lo+hi)/2;
		if (primes[md] == p) return md;
		else if (primes[md] < p) lo = md;
		else hi = md;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	primes.push_back(2);
	char* sieve = new char[MX];
	fill(sieve, sieve+MX, true);
	for(ll i=3; i<MX; i+=2){
		if (sieve[i]) {
			primes.push_back(i);
			// if (i<100) cout << i << endl;
			for(ll j=i*i; j<MX; j+=i){
				sieve[j] = false;
			}
		}
	}

	int n;
	cin >> n;
	vi b(2*n);
	rep(i,0,2*n) cin >> b[i];
	sort(all(b));

	unordered_map<int, int> claimed1, claimed2;

	vi a;

	for(int i=2*n-1; i>=0; --i){
		auto f1 = claimed1[b[i]];
		auto f2 = claimed2[b[i]];
		auto p = get_ind(b[i])+1;

		if ( f1 > 0 ) {
			claimed1[b[i]]--;
			// cout << b[i] << "cl1" << endl;
			// a.push_back(b[i]);
		} else if ( f2 > 0 ){
			claimed2[b[i]]--;
			// cout << b[i] << "cl2" << endl;
		} else if (p) {
			claimed1[p]++;
			a.push_back(p);
			// cout << p << "->" << b[i] << endl;
		} else {
			a.push_back(b[i]);
			int aa;
			for (auto pp : primes) {
				if ( b[i] % pp == 0 ){
					aa = pp;
					break;
				}
			}
			claimed2[b[i]/aa]++;
			// cout << b[i] << "->" << b[i]/aa << endl;
		}
	}
	for(auto aa : a) cout << aa << " ";
	cout << endl;
	
}