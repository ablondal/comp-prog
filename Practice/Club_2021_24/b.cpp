#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a;
	rep(i,0,n){
		int t;
		cin >> t;
		if (i && __gcd(t, a.back()) != 1){
			for(int j=0; j<19; ++j){
				int p = primes[j];
				if (__gcd(p, a.back())==1 && __gcd(p,t)==1){
					a.push_back(p);
					break;
				}
			}
		}
		a.push_back(t);
	}
	cout << a.size()-n << endl;
	for(auto e:a) cout << e << " ";
		cout << endl;
}