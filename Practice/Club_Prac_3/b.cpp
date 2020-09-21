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

int bills[5] = {100, 20, 10, 5, 1};

int main(){
	int n;
	cin >> n;
	int b = 0;
	for(auto bill : bills){
		if (n >= bill){
			b += (n/bill);
			n %= bill;
		}
	}
	cout << b << endl;
}














