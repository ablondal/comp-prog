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
typedef bitset<105> bs;

vi primes;

void make_primes(int t){
	primes.push_back(2);
	int i = 3;
	while(sz(primes) < t){
		bool g = true;
		for(int j=2; j*j <= i; ++j){
			if (i % j == 0){
				g = false;
				break;
			}
		}
		if (g) primes.push_back(i);
		i++;
	}
}

bs factor(int b){
	bs r = 0;
	rep(i,0,sz(primes)){
		while(b % primes[i] == 0){
			b /= primes[i];
			r[i]=!r[i];
		}
	}
	return r;
}

int reduce(bs a, vector<bs>& mat){
	for(int i=104; i>=0; --i){
		if (a[i]) {
			if (mat[i][i]) {
				a ^= mat[i];
			} else {
				return i;
			}
		}
	}
	return -1;
}

string decimal_string(__uint128_t bleh){
	string ans;
	while(bleh){
		string b(1, '0'+(bleh%10));
		ans = b + ans;
		bleh /= 10;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream in("rsa.in");
	ofstream out("rsa.out");

	int t, m;
	in >> t >> m;
	make_primes(t);
	vector<bs> mat(105, 0);

	int ct = 0;

	rep(i,0,m){
		int b;
		in >> b;
		bs r = factor(b);
		int c = reduce(r, mat);
		if (c == -1){
			ct++;
		} else {
			mat[c] = r;
		}
	}
	__uint128_t a = 1;
	a = a << ct;
	a = a-1;
	out << decimal_string(a) << endl;
	cout << decimal_string(a) << endl;
	// cout << decimal_string(a << 120) << endl;
}