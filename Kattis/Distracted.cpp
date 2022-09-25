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

char type[50007] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l;
	cin >> n >> l;
	map<string, int> M;
	int Mi = 0;
	rep(i,0,n){
		string s;
		cin >> s;
		M[s] = Mi++;
		cin >> type[Mi-1];
	}
}