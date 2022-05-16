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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	if (a==b && b!=c){
		cout << "C" << endl;
	}else if (a==c && b!=c){
		cout << "B" << endl;
	}else if (b==c && a!=b){
		cout << "A" << endl;
	}else{
		cout << "*" << endl;
	}
}