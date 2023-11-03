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
const int MAXN = 1e6+7;

vector<vector<int>> T1, T2;
stringstream in, t1, t2;

int make_tree(vector<vector<int>> &T){
	int v;
	in >> v;
	while(true){
		char c;
		if(!(in >> c) ){
			break;
		}
		// cout << c << endl;
		if (c == '(') {
			T[v].push_back(make_tree(T));
		} else {
			break;
		}
	}
	sort(all(T[v]));
	// for(auto e: T[v]){
	// 	cout << e << " ";
	// }
	// cout << endl;
	return v;
}

void retree(stringstream &t, vector<vector<int>> &T, int v){
	t << v;
	for(auto c: T[v]){
		t << '(';
		retree(t, T, c);
		t << ')';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1, s2;
	T1.resize(MAXN);
	T2.resize(MAXN);
	getline(cin,s1);
	getline(cin,s2);
	string a, b;
	in << s1;
	int v1 = make_tree(T1); retree(t1, T1, v1);
	in.clear();
	t1 >> a;
	// cout << a << endl;

	in << s2;
	int v2 = make_tree(T2); retree(t2, T2, v2);
	t2 >> b;
	// cout << b << endl;
	if (a==b){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

}