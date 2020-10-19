#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int t;
	cin >> t;
	string sss;
	getline(cin, sss);
	while(t--){
		string cmd;
		getline(cin, cmd);
		if (sz(cmd)<10 || cmd.substr(0, 10) != "Simon says"){
			continue;
		}
		cout << cmd.substr(10, 100) << endl;
	}
}