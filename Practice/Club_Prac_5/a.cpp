#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

int ncol[101] = {0};
int nrow[101] = {0};

int main(){
	int n;
	char t;
	cin >> n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> t;
			if(t == 'C'){
				ncol[i]++;
				nrow[j]++;
			}
		}
	}
	int tot = 0;
	for(int i=0; i<n; ++i){
		tot += (ncol[i] * (ncol[i]-1)) / 2;
		tot += (nrow[i] * (nrow[i]-1)) / 2;
	}
	cout << tot << endl;
}
