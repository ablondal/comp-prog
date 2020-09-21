#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define inf 1e9

typedef pair <int, int> pt;
typedef long long ll;

int main(){
	string s;
	cin >> s;
	string S;
	for(auto ss: s){
		if (ss >= 'A' && ss <= 'Z'){
			S = S + ss;
		}
	}
	cout << S << endl;
}














