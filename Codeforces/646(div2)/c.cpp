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
		int n, x;
		cin >> n >> x;
		int nverts=0;
		int u, v;
		fori(i, n-1){
			cin >> u >> v;
			if (u==x || v==x){
				nverts++;
			}
		}
		if(nverts>1){
			cout << (n%2==0 ? "Ayush" : "Ashish") << endl;
		}else{
			cout << "Ayush" << endl;
		}

	}
}