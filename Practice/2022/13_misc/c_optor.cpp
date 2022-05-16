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

stringstream s;
double R[107];

double parse(){
	char type = 0;
	vector<double> res;
	char c;
	s >> c;
	while(c != ')'){
		if (c == '('){
			res.push_back(parse());
		} else if (c == 'R'){
			int a;
			s >> a;
			res.push_back(R[a]);
		} else if (c == '-') {
			type = '-';
		} else if (c == '|') {
			type = '|';
		}
		s >> c;
		// cout << c << endl;
	}
	// cout << "out" << endl;
	if (sz(res) == 1){
		return res[0];
	}
	if (type == '-'){
		double su = 0;
		for(auto a : res) su += a;
		return su;
	}
	double su = 0;
	for(auto a : res) su += (1/a);
	return 1/su;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,1,n+1){
		cin >> R[i];
	}
	string t;
	cin >> t;
	// cout << t << endl;
	s << t;
	char c;
	s >> c;
	cout << setprecision(12) << parse() << endl;
}