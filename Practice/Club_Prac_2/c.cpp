#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define fori(i,k) for(int i=0; i<k; ++i)


int main(){
	int n;
	cin >> n;
	while(n--){
		int t;
		cin >> t;
		int l, ln;
		cin >> l;
		bool k = true;
		for(int i=1; i<t; ++i){
			cin >> ln;
			if (k && ln != l+1){
				k = false;
				cout << i+1 << endl;
			}
			l = ln;
		}
	}
}