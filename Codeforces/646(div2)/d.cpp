#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ostream>
#include <set>
using namespace std;
#define fori(i, n) for(int i=0; i<n; ++i)
#define min(a,b) ((a<b)?a:b)

vector <int> S[1001];
int ini[1001] = {0};

int getQ(int s, int t){
	cout << "? " << t-s;
	for(int i=s; i<t; ++i){
		cout << " " << i;
	}
	cout << endl << flush;
	// cout.flush();
	int ans;
	cin >> ans;
	return ans;
}

int getbutQ(int Mi, int n, int k){
	cout << "? " << (n-S[ini[Mi]].size());
	set <int> notin(S[ini[Mi]].begin(), S[ini[Mi]].end());
	for(int i=1; i<n+1; ++i){
		if (!notin.count(i)){
			cout << " " << i;
		}
	}
	cout << endl << flush;
	// cout.flush();
	int ans;
	cin >> ans;
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k, t;
		cin >> n >> k;
		vector <int> A(k);

		for(int i=1; i<=k; ++i){
			cin >> t;
			S[i].resize(t);
			for(int j=0; j<t; ++j){
				cin >> S[i][j];
				ini[S[i][j]] = i;
			}
		}
		int M = getQ(1, n+1);
		int top = n+1;
		int bot = 1;
		int mid;
		while(top-bot>1){
			mid = (top+bot)/2;
			if (getQ(mid, top) == M){
				bot = mid;
			}else{
				top = mid;
			}
		}
		int Mi = bot;
		int MB;
		if (ini[Mi]!=0)
			MB = getbutQ(Mi, n, k);
		else
			MB = M;
		cout << "!";
		for(int i=1; i<=k; ++i){
			if (i==ini[Mi]) {
				cout << " " << MB;
			}else{
				cout << " " << M;
			}
		}
		cout << endl << flush;
		// cout.flush();
		string s;
		cin >> s;
		if(s!="Correct") return 0;

	}
}
















