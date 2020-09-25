#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<string> pns(n);
		rep(i,0,n) cin >> pns[i];
		sort(all(pns));
		bool mm = false;
		rep(i,1,n){
			bool match = true;
			for(int a=0; a<min(sz(pns[i]), sz(pns[i-1])); ++a){
				if (pns[i][a]!=pns[i-1][a]){
					match = false;
					break;
				}
			}
			if (match){
				mm = true;
				break;
			}
		}
		if (mm){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}
}