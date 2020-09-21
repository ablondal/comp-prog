#include <iostream>
#include <vector>
using namespace std;


int main(){
	int t;
	cin >> t;
	while(t--){
		bool yes = false;
		long double bx, by, x, y;
		cin >> bx >> by;
		int m;
		cin >> m;
		for(int i=0; i<m; ++i){
			cin >> x >> y;
			if ( (x-bx)*(x-bx) + (y-by)*(y-by) <= 64 ){
				yes = true;
			}
		}
		if (yes) cout << "light a candle" << endl;
		else cout << "curse the darkness" << endl;
	}
}