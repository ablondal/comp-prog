#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define fori(i, n) for(int i=0; i<n; ++i)
#define min(a,b) ((a<b)?a:b)


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x, t;
		cin >> n >> x;
		int nodd=0, neven=0;
		fori(i, n){
			cin >> t;
			if (t%2==0){
				neven++;
			}else{
				nodd++;
			}
		}
		if(nodd>0){
			nodd--;
			x--;
		}else{
			cout << "No" << endl;
			continue;
		}
		if (x<=neven){
			cout << "Yes" << endl;
			continue;
		}
		x -= min((x/2)*2, (nodd/2)*2);
		nodd -= min((x/2)*2, (nodd/2)*2);
		if(x<=neven){
			cout << "Yes" << endl;
		}else{
			cout <<"No" <<endl;
		}

	}
}



















