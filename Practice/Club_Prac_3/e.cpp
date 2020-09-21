#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define inf 1e9

typedef pair <int, int> pt;
typedef long long ll;

bool a[1000001] = {0};
bool b[1000001] = {0};

int main(){

	string c, d;
	int n;
	cin >> n;
	cin >> c >> d;

	for(int i=0; i<n; ++i){
		if (c[i]=='0') a[i] = 0;
		if (c[i]=='1') a[i] = 1;
		if (d[i]=='0') b[i] = 0;
		if (d[i]=='1') b[i] = 1;
	}

	vector <int> E(n);
	
	E[0] = (a[0] == b[0]) ? 0 : 1;

	for(int i=1; i<n; ++i){
		if (a[i]==b[i]){
			E[i] = E[i-1];
		}else if (a[i]==b[i-1] && a[i-1]==b[i]){
			if (i==1) E[i] = 1;
			else E[i] = min(E[i-1]+1, E[i-2]+1);
		}else{
			E[i] = E[i-1]+1;
		}
	}
	cout << E[n-1] << endl;
}














