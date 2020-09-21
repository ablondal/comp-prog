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
		int n, t;
		cin >> n;
		vector <int> odds, evens;
		for(int i=1; i<=2*n; ++i){
			cin >> t;
			if (t & 1){
				odds.push_back(i);
			}else{
				evens.push_back(i);
			}
		}
		int i, j;
		if (odds.size() & 1){
			i = 1;
			j = 1;
		}else if (odds.size() > 1){
			i = 2;
			j = 0;
		}else{
			i = 0;
			j = 2;
		}
		for( ; i<odds.size(); i+=2){
			cout << odds[i] << ' ' << odds[i+1] << endl;
		}
		for( ; j<evens.size(); j+=2){
			cout << evens[j] << ' ' << evens[j+1] << endl;
		}
	}
}
