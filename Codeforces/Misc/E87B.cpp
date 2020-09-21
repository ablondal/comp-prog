#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#define min(a,b) ((a<b)?a:b)

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		vector <int> v(8, 0); // '', 1, 2, 12, 3, 13, 23, 123
		int m = 1e9;
		for( char c : s ){
			for(int i=1; i<8; ++i){
				if (v[i]) v[i]++;
			}
			if (c=='1'){
				v[1]=1;
				if (v[2]) v[3] = v[2];
				if (v[4]) v[5] = v[4];
				if (v[6]) v[7] = v[6];
			}else if (c=='2') {
				v[2]=1;
				if (v[1]) v[3] = v[1];
				if (v[4]) v[6] = v[4];
				if (v[5]) v[7] = v[5];
			}else if (c=='3') {
				v[4]=1;
				if (v[1]) v[5] = v[1];
				if (v[2]) v[6] = v[2];
				if (v[3]) v[7] = v[3];
			}
			if (v[7]) m = min(m,v[7]);
		}
		if (m==1e9) m = 0;
		cout << m << endl;
	}
}