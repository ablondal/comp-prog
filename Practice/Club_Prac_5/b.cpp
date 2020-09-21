#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)


int main(){
	int T;
	cin >> T;
	while(T--){
		ll g, l;
		cin >> g >> l;
		if (l % g){
			cout << -1 << endl;
			continue;
		}
		ll c = l / g;
		cout << g << " " << g * c << endl; 

	}
}
