#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE

typedef vector <int> vi;
typedef long long ll;
typedef vector <ll> vll;

int main(){
	int n;
	cin >> n;
	vi inp(n);
	vi oup(n);
	for(int i=0; i<n; ++i){
		cin >> inp[i];
	}
	int cmax = 0;
	for(int i=0; i<n; ++i){
		if (inp[i] >= 0 ){
			cmax += inp[i];
			oup[i] = cmax;
		}else{
			oup[i] = inp[i] + cmax;
		}
	}
	for(int i=0; i<n; ++i){
		if (i!=0) cout << " ";
		cout << oup[i];
	}
	cout << endl;
}





























