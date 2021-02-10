#include <bits/stdc++.h>
using namespace std;
// incomplete
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef unsigned long long ull;
vector<string> minPrefixes(int bits, ull lo, ull hi){
	vector<string> prefixes;
	int msize;
	while(lo<=hi){
		for(msize = min(bits, __builtin_ctzll(lo)); msize>=0; msize--){
			if ( (1ULL<<msize) <= hi-lo+1 ){
				// Make string
				prefixes.emplace_back(bits, '0');
				rep(i,0,msize) prefixes[prefixes.size()-1][bits-1-i]='*';
				rep(i,msize,bits) prefixes[prefixes.size()-1][bits-1-i] = (lo & (1ULL<<i)) ? '1' : '0';
				break;
			}
		}
		// Increment
		lo += (1ULL<<msize);
	}
	return prefixes;
}

void run_test(int bits, ull a, ull b){
	vector<string> res = minPrefixes(bits, a, b);
	cout << "printing min number of " << bits << "-bit prefixes of range [" << a << ", " << b << "]" << endl;
	for(auto s : res){
		cout << s << endl;
	}
	cout << endl;
}

int main() {
	// run_test(8,0,0);
	// run_test(8,0,1);
	// run_test(8,0,64);
	// run_test(8,3,10);
	// run_test(8,4,14);
	// run_test(8,9,120);
	// run_test(31,1,1095873459);
	run_test(63,1,9223372036854775806);
}