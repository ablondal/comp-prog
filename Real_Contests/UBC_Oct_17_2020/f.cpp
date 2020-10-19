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
	scanf("%d", &t);
	string line;
	getline(cin, line);
	while(t--){
		vector<int> al(26, 0);
		getline(cin, line);
		for (auto c : line){
			if ('a'<=c && c <= 'z'){
				al[c-'a'] = 1;
			}
			if ('A'<=c && c<='Z'){
				al[c-'A'] = 1;
			}
		}
		string mis = "";
		rep(i,0,26){
			if (!al[i]){
				mis += i+'a';
			}
		}
		if (mis==""){
			printf("pangram\n");
		}else{
			cout << "missing " << mis << endl;
		}
	}
}