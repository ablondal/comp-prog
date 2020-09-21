#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define fori(i,k) for(int i=0; i<k; ++i)

int main(){
	int t;
	cin >> t;
	while(t--){
		int c;
		cin >> c;
		vector <int> C(c, 0);
		fori(i, c){
			int n;
			cin >> n;
			fori(j, n){
				int t;
				cin >> t;
				C[i] += t;
			}
		}
		sort(C.begin(), C.end());
		double tot = 0;
		for(int i=0; i<c; ++i){
			tot += C[i] * (c-i);
		}
		tot /= (double) c;
		cout << setprecision(10) << tot << endl;
	}
}