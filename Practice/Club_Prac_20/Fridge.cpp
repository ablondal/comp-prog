#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int n;
	int h;
	scanf("%d%d", &n, &h);
	vi a(n);
	rep(i,0,n){scanf("%d", &a[i]);}
	bool cansort = 1;
	int i=1;
	while(i<=n && cansort){
		sort(a.begin(), a.begin()+i);
		int s = 0;
		for(int j=i-1; j>=0; j-=2){
			s+=a[j];
		}
		if (s>h) cansort = false;
		else i++;
	}
	printf("%d\n", i-1);
}










