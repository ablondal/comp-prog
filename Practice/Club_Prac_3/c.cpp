#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)

typedef pair <int, int> pt;
typedef long long ll;

int main(){
	int n;

	cin >> n;
	vector <int> C(n);
	for( auto &c : C ){
		cin >> c;
	}
	sort(C.begin(), C.end());
	ll x = 0;
	ll y = 0;
	for(int i=0; i<C.size() / 2; ++i){
		x += C[i];
	}
	for(int i=C.size() / 2; i<C.size(); ++i){
		y += C[i];
	}
	cout << x*x + y*y << endl;

}














