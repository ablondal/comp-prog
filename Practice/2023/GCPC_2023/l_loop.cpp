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
	string s;
	cin >> s;
	string bb;
	int layer = 0;
	int i=0;
	do{
		if (s[i] == '(') layer++;
		else layer--;
		i++;
	}while(layer != 0);
	bb = s.substr(0,i);
	// cout << bb << endl;
	bool ans = false;
	int k = 0;
	rep(j,0,sz(s)){
		if (s[j] == '(') layer++;
		else layer--;
		if (layer == 0){
			string cc = s.substr(k, j-k+1);
			// cout << cc << endl;
			if (cc != bb) {
				ans = true;
				cout << s.substr(i, sz(s)) + bb << endl;
				return 0;
			}
			k = j+1;
		}
	}
	if (ans == false){
		cout << "no" << endl;
	}
}