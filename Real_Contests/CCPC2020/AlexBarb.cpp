#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

// DONE
// Game theory is fun

int main(){
	int k;
	int m,n;
	cin >> k >> n >> m;
	k = k % (m+n);
	if(k < n) cout << "Barb" << endl;
	else cout << "Alex" << endl;
}