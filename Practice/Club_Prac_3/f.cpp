#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define inf 2e9

typedef long long ll;

ll E[100007];
ll O[100007];

int main(){
	int n;
	cin >> n;
	vector <ll> a(n+1);
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}

	E[0] = 0;
	O[0] = -2e9;

	for(int i=1; i<=n; ++i){
		if (a[i]%2==0){
			E[i] = max(E[i-1], E[i-1]+a[i]);
			O[i] = max(O[i-1], O[i-1]+a[i]);
		}else{
			E[i] = max(E[i-1], O[i-1]+a[i]);
			O[i] = max(O[i-1], E[i-1]+a[i]);
		}
	}
	cout << O[n] << endl;
}














