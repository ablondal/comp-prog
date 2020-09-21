#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

char winner[1000001];

int main(){
	int n;
	while(cin >> n){
		vector <int> mvs;
		int m;
		cin >> m;
		mvs.resize(m);
		for(int i=0; i<m; ++i){
			cin >> mvs[i];
		}
		memset(winner, 0, n+1);

		for(int i=1; i <= n; ++i){
			for(int mv : mvs){
				if (i-mv >= 0 && winner[i-mv]==0){
					winner[i] = 1;
					break;
				}
			}
		}
		// cout << endl;
		cout << (winner[n] ? "Stan" : "Ollie") << " wins" << endl;
	}
}
