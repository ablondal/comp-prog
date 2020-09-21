#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair <int, int> pt;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector <pt> P(n);
	priority_queue <int> Q;
	
	for(int i=0; i<n; ++i){
		cin >> P[i].first >> P[i].second; // deadline, value
	}

	sort(P.begin(), P.end());

	int index = P[P.size() - 1].first; // deadline
	int i = P.size() - 1;

	ll totmoney = 0;

	while ( i >= 0 && index > 0 ){
		while( i >= 0 && P[i].first >= index ){
			Q.push(P[i].second);
			i--;
		}

		totmoney += Q.top();
		Q.pop();

		if (Q.empty()) {
			index = P[i].first;
		} else {
			index--;
		}

	}

	cout << totmoney << endl;
}