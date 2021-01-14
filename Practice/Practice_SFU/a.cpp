#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// DONE
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	string month;
	cin >> month;
	string res;
	if(month == "january" || month == "december" || month == "february"){
		res = "summer";
	}else if(month == "september" || month == "october" || month == "november"){
		res = "spring";
	}else if(month == "march" || month == "april" || month == "may"){
		res = "autumn";
	}else{
		res = "winter";
	}
	cout << res << endl;
}