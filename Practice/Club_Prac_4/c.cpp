#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
// const int MAXN = 1000;

bool F[101] = {0};

int main(){
	int n, d;
	cin >> n >> d;
	int jumps = 0;
	int frogpos = 0;
	string F;
	cin >> F;
	while(frogpos < n-1){
		for(int j=frogpos+d; j>=frogpos; --j){
			if (j>=n) continue;
			if (j==frogpos){
				cout << -1 << endl;
				return 0;
			}
			if (F[j]=='1'){
				frogpos = j;
				jumps++;
				break;
			}
		}
	}
	cout << jumps << endl;
}