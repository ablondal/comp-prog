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
	int n;
	cin >> n;
	vector <int> m(n);
	for(auto &u : m){
		cin >> u;
	}
	vector <int> min_marks(n);
	for(int i=m.size()-1; i>=0; --i){
		min_marks[i] = m[i]+1;
		if (i!=m.size()-1){
			min_marks[i] = max(min_marks[i], min_marks[i+1]-1);
		}
	}
	ll mm = 0;
	ll tot = 0;
	for(int i=0; i<m.size(); ++i){
		mm = max(mm, min_marks[i]);
		tot += mm - m[i] - 1;
	}
	cout << tot << endl;
}














